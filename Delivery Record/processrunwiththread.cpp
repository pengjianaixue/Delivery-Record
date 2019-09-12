#include "stdafx.h"
#include "processrunwiththread.h"

processRunWithThread::processRunWithThread(QThread *parent)
	: QThread(parent)
{
	
}

processRunWithThread::~processRunWithThread()
{
	m_isStop = true;
	wait();
}
void processRunWithThread::emitProcessMsg()
{
	if (this->m_runCmdProcess)
	{
		QByteArray baStandardoutpt = this->m_runCmdProcess->readAllStandardOutput();
		QString msg = QString::fromLocal8Bit(baStandardoutpt);
		emit s_ProcessMsgReaded(msg);
		return;
	}
	
}
void processRunWithThread::terminateProcess()
{
	if (m_runCmdProcess)
	{
		m_runCmdProcess->terminate();
	}
	return;
}

void processRunWithThread::registerrunCommandList(const QList<QString>& cmdList)
{
	QMutexLocker locker(&m_mutex);
	m_cmdList = cmdList;
	return;
}

void processRunWithThread::run()
{

	m_runCmdProcess = new QProcess;
	m_runCmdProcess->deleteLater();
	m_runCmdProcess->setProcessChannelMode(QProcess::ProcessChannelMode::MergedChannels);
	connect(this->m_runCmdProcess, &QProcess::readyReadStandardOutput, this, &processRunWithThread::emitProcessMsg);
	while (!m_isStop)
	{
		QMutexLocker locker(&m_mutex);
		for (auto &cmditem : m_cmdList)
		{
			m_runCmdProcess->start(cmditem);
			m_runCmdProcess->waitForFinished();
		}
		m_cmdList.clear();
	}	
	return;
}
