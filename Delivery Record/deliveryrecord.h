#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_deliveryrecord.h"
#include "IniFileTemplateHandler.h"
#include "configure.h"
#include "QTextEditDelegate.h"
#include "XmlWirter.h"
#include "XmlReader.h"
class DeliveryRecord : public QMainWindow
{
	Q_OBJECT

public:
	DeliveryRecord(QWidget *parent = Q_NULLPTR);
	~DeliveryRecord();
private:
	void resizeEvent(QResizeEvent * event) override;
	void initUI();
	void init();
	bool saveTableContents();
	void connectSlots();
	bool callUpdateWikiPyScript();

private slots:
	void openConfigurDialog(bool open);
	void readPyScriptOutputToDisplay();
	void hideDisplayTextBrowse();
	void cleanTableContents();
	
private:
	Ui::DeliveryRecordClass					ui;
	dialog_UserConfigure					*configurUi = {nullptr};
	std::shared_ptr<QTextEditDelegate>		m_pInputTextEditorDelegate = std::make_shared<QTextEditDelegate>(this);
	std::shared_ptr<XmlWirter>				m_XmlWirter = std::make_shared<XmlWirter>(this);
	std::shared_ptr<XmlReader>				m_XmlReader = std::make_shared<XmlReader>(this);
	std::shared_ptr<QProcess>				m_pyCallProcess = std::make_shared<QProcess>();
	QString									m_strXmlFilePath;
	
};
