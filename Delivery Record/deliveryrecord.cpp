#include "stdafx.h"
#include "deliveryrecord.h"

DeliveryRecord::DeliveryRecord(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	InitUI();
}

void DeliveryRecord::resizeEvent(QResizeEvent *event)
{ 
	
	
}
	



void DeliveryRecord::InitUI()
{
	ui.progressBar_update->hide();
	ui.horizontalLayout_2->insertSpacerItem(1,new QSpacerItem(20, 20, QSizePolicy::Expanding));
	ui.lineEdit_password->setEchoMode(QLineEdit::Password);
	ui.lineEdit_password->setPlaceholderText("please input password");
	ui.lineEdit_username->setPlaceholderText("please input username");
	IniFileTemplateHandler initIniReader("./RecordTemp.ini");
	IniFileTemplateHandler::VALUELISTDIC iniFileValue =  initIniReader.fetchValueDictFromIni();
	QStringList deliveryInfoWord;
	for (auto &item :iniFileValue["Dilivery table configure"])
	{
		if (item.second == "true")
		{
			deliveryInfoWord.append(item.first);
		}
	}
	for (auto &item : iniFileValue["user configure"])
	{
		if (item.first == "user name")
		{
			ui.lineEdit_username->setText(item.second);
		}
		else if (item.first == "password")
		{
			ui.lineEdit_password->setText(item.second);
		}
	}
	ui.tablewideget_deliverytable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tablewideget_deliverytable->setColumnCount(1);
	ui.tablewideget_deliverytable->setRowCount(deliveryInfoWord.size());
	ui.tablewideget_deliverytable->setVerticalHeaderLabels(deliveryInfoWord);
	ui.tablewideget_deliverytable->horizontalHeader()->setVisible(true);
	ui.tablewideget_deliverytable->setHorizontalHeaderLabels(QStringList(""));
	ui.tablewideget_deliverytable->verticalHeader()->setVisible(true); 
	//TODO Add the ItemDelegate
	ui.tablewideget_deliverytable->setItemDelegateForColumn(1, nullptr);
	ui.tablewideget_deliverytable->horizontalHeader()->setStretchLastSection(true);
	ui.tablewideget_deliverytable->verticalHeader()->setStretchLastSection(true);

}
