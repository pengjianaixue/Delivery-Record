#include "stdafx.h"
#include "deliveryrecord.h"

DeliveryRecord::DeliveryRecord(QWidget *parent)
	: QMainWindow(parent), configurUi(new dialog_UserConfigure(this))
{
	ui.setupUi(this);
	init();
}

DeliveryRecord::~DeliveryRecord()
{
	delete configurUi;
}

void DeliveryRecord::resizeEvent(QResizeEvent *event)
{ 
	
}

void DeliveryRecord::initUI()
{
	ui.progressBar_update->hide();
	this->configurUi->hide();
	this->ui.widget_displayinfor->hide();
	ui.horizontalLayout_2->insertSpacerItem(1,new QSpacerItem(20, 20, QSizePolicy::Expanding));
	IniFileProcesser initIniReader("./RecordTemp.ini");
	IniFileProcesser::VALUELISTDIC iniFileValue =  initIniReader.fetchValueDictFromIni();
	QStringList deliveryKeyWords;
	QStringList deliveryInfoWords;
	XmlReader::VALUEPAIRLIST deliveryInfo;
	m_XmlReader->openFile(m_strXmlFilePath);
	m_XmlReader->setRootName();
	m_XmlReader->getAnSpecialCategoryValue("Delivery_Infor", "DliveryInfo", QStringList("Value"), deliveryInfo);
	int count = initIniReader.getGroupKeycount("Dilivery_table_configure");
	for (int i = 0;i < count;++i)
	{
		QString keyword = "Word_" + QString(std::to_string(i+1).c_str());
		QStringList temp = initIniReader.fetchSpecGroupAndKeyValue("Dilivery_table_configure", keyword).split("@=");

		deliveryKeyWords.append(temp[0]);
		i<deliveryInfo.length() ? deliveryInfoWords.append(deliveryInfo[i][0].second) : deliveryInfoWords.append("");
	}
	ui.tablewideget_deliverytable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tablewideget_deliverytable->setColumnCount(1);
	ui.tablewideget_deliverytable->setRowCount(deliveryKeyWords.size());
	ui.tablewideget_deliverytable->setVerticalHeaderLabels(deliveryKeyWords);
	ui.tablewideget_deliverytable->horizontalHeader()->setVisible(true);
	ui.tablewideget_deliverytable->setHorizontalHeaderLabels(QStringList(""));
	ui.tablewideget_deliverytable->verticalHeader()->setVisible(true); 
	ui.tablewideget_deliverytable->setItemDelegateForColumn(0, m_pInputTextEditorDelegate.get());
	ui.tablewideget_deliverytable->horizontalHeader()->setStretchLastSection(true);
	ui.tablewideget_deliverytable->verticalHeader()->setStretchLastSection(true);
	for (size_t i = 0; i < deliveryInfoWords.length(); i++)
	{
		QTableWidgetItem *item = new QTableWidgetItem();
		item->setText(deliveryInfoWords[i]);
		ui.tablewideget_deliverytable->setItem(i, 0, item);
	}
	connectSlots();

}
void DeliveryRecord::init()
{
	m_strXmlFilePath = QApplication::applicationDirPath() + "/DeliveryInfor.xml";
	m_pyCallProcess->setProcessChannelMode(QProcess::ProcessChannelMode::MergedChannels);
	initUI();
}
bool DeliveryRecord::saveTableContents()
{
	QStringList valueList;
	QList<QStringList> valueStringList;
	for (size_t i = 0; i < ui.tablewideget_deliverytable->rowCount(); i++)
	{
		valueList.append(ui.tablewideget_deliverytable->item(i, 0)->text());
		valueStringList.append(valueList);
		valueList.clear();
	}
	m_XmlWirter->emptyXmlDoc();
	m_XmlWirter->fileStructInit("root");
	m_XmlWirter->writeAncategoryData("Delivery_Infor", "DliveryInfo", QStringList("Value"), valueStringList);
	if (m_XmlWirter->saveToFile(m_strXmlFilePath))
	{
		callUpdateWikiPyScript();
	}
	else
	{
		QMessageBox::critical(this, "save file error", "save delivery information to file faild");
		return false;
	}
	return true;
}
void DeliveryRecord::openConfigurDialog(bool open)
{
	this->configurUi->show();
}

void DeliveryRecord::connectSlots()
{
	connect(this->ui.actionconfiguration, &QAction::triggered, this, &DeliveryRecord::openConfigurDialog);
	connect(this->ui.pushButton_update, &QPushButton::clicked, this, &DeliveryRecord::saveTableContents);
	connect(this->m_pyCallProcess.get(), &QProcess::readyReadStandardOutput, this, &DeliveryRecord::readPyScriptOutputToDisplay);
	connect(this->m_pyCallProcess.get(), &QProcess::readyReadStandardError, this, &DeliveryRecord::readPyScriptOutputToDisplay);
	connect(this->ui.pushButton_hidedispaly, &QPushButton::clicked, this, &DeliveryRecord::hideDisplayTextBrowse);
	connect(this->ui.actionclean_contents, &QAction::triggered, this, &DeliveryRecord::cleanTableContents);
}

bool DeliveryRecord::callUpdateWikiPyScript()
{
	this->ui.textBrowser_updateInfor->clear();
	QString pythonFilePath = R"(")" + QApplication::applicationDirPath() + R"(")"  + "/Delivery_note_record.exe";
	QString cmdstr = pythonFilePath;
	m_pyCallProcess->start(cmdstr);
	this->ui.widget_displayinfor->show();
	this->ui.textBrowser_updateInfor->insertPlainText("Start run python script...\r\n");
	return true;
}

bool DeliveryRecord::updateTableContents()
{
	return false;
}

void DeliveryRecord::readPyScriptOutputToDisplay()
{
	if (this->ui.widget_displayinfor->isHidden())
	{
		this->ui.widget_displayinfor->show();
	}
	QByteArray baStandardoutpt = m_pyCallProcess->readAllStandardOutput();
	QString msg = QString::fromLocal8Bit(baStandardoutpt);
	this->ui.textBrowser_updateInfor->insertPlainText(msg);
}

void DeliveryRecord::hideDisplayTextBrowse()
{
	this->ui.widget_displayinfor->hide();
}

void DeliveryRecord::cleanTableContents()
{
	for (size_t i = 0; i < this->ui.tablewideget_deliverytable->rowCount(); i++)
	{
		this->ui.tablewideget_deliverytable->item(i, 0)->setText("");
	}
}

