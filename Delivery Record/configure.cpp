#include "stdafx.h"
#include "configure.h"

dialog_UserConfigure::dialog_UserConfigure(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUi();
}

dialog_UserConfigure::~dialog_UserConfigure()
{

}

void dialog_UserConfigure::initUi()
{
	ui.lineEdit_password->setEchoMode(QLineEdit::Password);
	ui.lineEdit_password->setPlaceholderText("please input password");
	ui.lineEdit_username->setPlaceholderText("please input username");
	ui.lineEdit_editsection->setPlaceholderText("Pelse input table order");
	IniFileTemplateHandler initIniReader("./RecordTemp.ini");
	IniFileTemplateHandler::VALUELISTDIC iniFileValue = initIniReader.fetchValueDictFromIni();
	for (auto &item : iniFileValue["user configure"])
	{
		if (item.first == "user name")
		{
			ui.lineEdit_username->setText(item.second);
		}
		else if (item.first == "password")
		{
			/*QCryptographicHash HashPassword(QCryptographicHash::Md5);
			HashPassword.addData(item.second.toStdString().c_str(), item.second.toStdString().length());*/
			/*std::hash<QString> HashPassword;
			int n =  HashPassword(item.second);*/
			ui.lineEdit_password->setText(item.second);
		}
	}
	for (auto &item : iniFileValue["wikipage configure"])
	{
		if (item.first == "editSection")
		{
			ui.lineEdit_editsection->setText(item.second);
		}

	}
	
}
