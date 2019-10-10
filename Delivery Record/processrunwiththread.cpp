#include "stdafx.h"
#include "processrunwiththread.h"

subProcessRunner::subProcessRunner(QObject *parent)
	: QObject(parent)
{
	m_runCmdProcess = new QProcess(this);
	m_runCmdProcess->setParent(this);
	m_runCmdProcess->setProcessChannelMode(QProcess::ProcessChannelMode::MergedChannels);
	connect(this->m_runCmdProcess, &QProcess::readyReadStandardOutput, this, &subProcessRunner::emitProcessMsg);
}

subProcessRunner::~subProcessRunner()
{
	m_runCmdProcess->deleteLater();
}
void subProcessRunner::emitProcessMsg()
{
	if (this->m_runCmdProcess)
	{
		QByteArray baStandardoutpt = this->m_runCmdProcess->readAllStandardOutput();
		QString msg = QString::fromLocal8Bit(baStandardoutpt);
		emit s_processMsgReaded(msg);
		return;
	}
	
}
void subProcessRunner::terminateProcess()
{
	if (m_runCmdProcess)
	{
		m_runCmdProcess->terminate();
	}
	return;
}
void subProcessRunner::run(const QList<QString>& cmdList)
{
	for (auto &cmditem : cmdList)
	{
		m_runCmdProcess->start(cmditem);
		m_runCmdProcess->waitForFinished();
		emit s_runFinished(cmditem);
	}
	return;
}
