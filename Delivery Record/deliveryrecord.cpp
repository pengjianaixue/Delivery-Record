#include "stdafx.h"
#include "deliveryrecord.h"

DeliveryRecord::DeliveryRecord(QWidget *parent)
	: QMainWindow(parent), configurUi(new dialog_UserConfigure(this))
{
	ui.setupUi(this);
	m_strXmlFilePath = QApplication::applicationDirPath() + "\\DeliveryInfor.xml";
	initUI();
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
	ui.horizontalLayout_2->insertSpacerItem(1,new QSpacerItem(20, 20, QSizePolicy::Expanding));
	IniFileProcesser initIniReader("./RecordTemp.ini");
	IniFileProcesser::VALUELISTDIC iniFileValue =  initIniReader.fetchValueDictFromIni();
	QStringList deliveryKeyWords;
	QStringList deliveryInfoWords;
	int count = initIniReader.getGroupKeycount("Dilivery table configure");
	for (int i = 1;i<= count;++i)
	{
		QString keyword = "Word_" + QString(std::to_string(i).c_str());
		QStringList temp = initIniReader.fetchSpecGroupAndKeyValue("Dilivery table configure", keyword).split("@=");
		deliveryKeyWords.append(temp[0]);
		//temp.length() > 1 ? deliveryInfoWords.append(temp[1]) : deliveryInfoWords.append("");
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
bool DeliveryRecord::saveTableContents()
{
	QStringList valueList;
	for (size_t i = 0; i < ui.tablewideget_deliverytable->rowCount(); i++)
	{
		valueList.append(ui.tablewideget_deliverytable->item(i, 0)->text());
	}
	m_XmlWirter->fileStructInit("root");
	//m_XmlWirter->writeAncategoryData("DiliveryInfo","DiliveryWord","")
	return true;
}
void DeliveryRecord::openConfigurDialog(bool open)
{
	this->configurUi->show();
}

void DeliveryRecord::connectSlots()
{
	connect(this->ui.actionconfiguration, &QAction::triggered, this, &DeliveryRecord::openConfigurDialog);
}

bool DeliveryRecord::UpdateTableContents()
{
	return false;
}

