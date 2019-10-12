#pragma once

#include <QtWidgets/QMainWindow>
#include <thread>
#include "ui_deliveryrecord.h"
#include "IniFileTemplateHandler.h"
#include "configure.h"
#include "QTextEditDelegate.h"
#include "XmlWirter.h"
#include "XmlReader.h"
#include "processRunWithThread.h"
class DeliveryRecord : public QMainWindow
{
	Q_OBJECT

public:
	DeliveryRecord(QWidget *parent = Q_NULLPTR);
	~DeliveryRecord();
protected:
	void resizeEvent(QResizeEvent * event) override;
	bool eventFilter(QObject *target, QEvent *event) override;
private:
	void initUI();
	void init();
	bool saveTableContents();
	void connectSlots();
	bool callUpdateWikiPyScript();
signals:
	bool s_runCallPyScriptSolt(QList<QString>);
private slots:
	void openConfigurDialog(bool open);
	void readPyScriptOutputToDisplay(QString cmdProcessMsg);
	void hideDisplayTextBrowse();
	void cleanTableContents();
	void fetchPyScriptRunResult(const QString &cmditem);
	void setEditRowWidth();
	
private:
	Ui::DeliveryRecordClass					ui;
	dialog_UserConfigure					*configurUi = {nullptr};
	std::shared_ptr<QTextEditDelegate>		m_pInputTextEditorDelegate = std::make_shared<QTextEditDelegate>(this);
	std::shared_ptr<XmlWirter>				m_XmlWirter = std::make_shared<XmlWirter>(this);
	std::shared_ptr<XmlReader>				m_XmlReader = std::make_shared<XmlReader>(this);
	std::shared_ptr<subProcessRunner>		m_pyCallProcess = { std::make_shared<subProcessRunner>(nullptr)}; //= std::make_shared<QProcess>();
	//std::shared_ptr<QProcess>				m_emialSendPyCallProcess = std::make_shared<QProcess>();
	QString									m_strXmlFilePath;
	volatile bool							m_updateisfinied = {false};
	QThread									m_pyRunThread;

};
