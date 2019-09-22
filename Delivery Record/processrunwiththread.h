#pragma once

#include <QObject>

class subProcessRunner : public QObject
{
	Q_OBJECT

public:
	subProcessRunner(QObject *parent);
	~subProcessRunner();
	void terminateProcess();
	//void registerrunCommandList(const QList<QString> &cmdList);
	void run(const QList<QString>& cmdList);
public slots:
	
private slots:
	void emitProcessMsg();
signals:
	void s_ProcessMsgReaded(QString);
private:
	QProcess				*m_runCmdProcess = {nullptr};
};
