#pragma once

#include <QObject>

class processRunWithThread : public QThread
{
	Q_OBJECT

public:
	processRunWithThread(QThread *parent);
	~processRunWithThread();
	void terminateProcess();
	void registerrunCommandList(const QList<QString> &cmdList);
public slots:
	
private slots:
	void emitProcessMsg();
signals:
	void s_ProcessMsgReaded(QString);
protected:
	void run() override;
private:
	QProcess				*m_runCmdProcess = {nullptr};
	QList<QString>			m_cmdList;
	volatile bool			m_isStop = { false };
	QMutex					m_mutex;
};
