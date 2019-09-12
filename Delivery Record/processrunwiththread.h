#pragma once

#include <QObject>

class processRunWithThread : public QObject
{
	Q_OBJECT

public:
	processRunWithThread(QObject *parent);
	~processRunWithThread();
	void terminateProcess();
public slots:
	bool runCommandList(QList<QString> cmdList);
private slots:
	void emitProcessMsg();
signals:
	void s_ProcessMsgReaded(QString);
private:
	QProcess		m_runCmdProcess;
};
