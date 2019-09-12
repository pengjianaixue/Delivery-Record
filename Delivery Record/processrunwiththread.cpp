#include "stdafx.h"
#include "processrunwiththread.h"

processRunWithThread::processRunWithThread(QObject *parent)
	: QObject(parent)
{
	m_runCmdProcess.setProcessChannelMode(QProcess::ProcessChannelMode::MergedChannels);
	connect(&this->m_runCmdProcess, &QProcess::readyReadStandardOutput, this, &processRunWithThread::emitProcessMsg);
}

processRunWithThread::~processRunWithThread()
{
	m_runCmdProcess.terminate();
}
void processRunWithThread::emitProcessMsg()
{
	QByteArray baStandardoutpt = this->m_runCmdProcess.readAllStandardOutput();
	QString msg = QString::fromLocal8Bit(baStandardoutpt);
	emit s_ProcessMsgReaded(msg);
	return;
}
bool processRunWithThread::runCommandList(QList<QString> cmdList)
{
	for (auto &cmditem: cmdList)
	{
		m_runCmdProcess.start(cmditem);
		m_runCmdProcess.waitForFinished();
	}
	return true;
}

void processRunWithThread::terminateProcess()
{
	m_runCmdProcess.terminate();
	return;
}
