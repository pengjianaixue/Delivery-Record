#include "stdafx.h"
#include "configure.h"

dialog_UserConfigure::dialog_UserConfigure(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	initUi();
}

dialog_UserConfigure::~dialog_UserConfigure()
{

}

void dialog_UserConfigure::showEvent(QShowEvent *showevent)
{
	ui.lineEdit_username->setText(m_editSubmitContentsMap["username"]);
	QString passwordDecodestr = m_editSubmitContentsMap["password"];
	passwordDecodeProcess(passwordDecodestr);
	ui.lineEdit_password->setText(passwordDecodestr);
	ui.lineEdit_editsection->setText(m_editSubmitContentsMap["editsection"]);

}

void dialog_UserConfigure::connectslots()
{
	this->connect(this->ui.okButton,&QPushButton::clicked,this, &dialog_UserConfigure::submitButtonClick);
	this->connect(this->ui.cancelButton, &QPushButton::clicked, this, &dialog_UserConfigure::cancelButtonClick);
}

void dialog_UserConfigure::submitButtonClick()
{
	m_editSubmitContentsMap.clear();
	m_editSubmitContentsMap.insert({ "username",ui.lineEdit_username->text() });
	QString passwordEncStr = ui.lineEdit_password->text();
	passwordEncryptionProcess(passwordEncStr);
	m_editSubmitContentsMap.insert({ "password",passwordEncStr});
	m_editSubmitContentsMap.insert({ "editsection",ui.lineEdit_editsection->text() });
	QList<std::pair<QString, QString>> iniList;
	for (auto  &item : m_editSubmitContentsMap)
	{
		iniList.append({ item.first ,item.second });
	}
	IniFileProcesser iniFileWirter("./RecordTemp.ini");
	iniFileWirter.writeGroupValueToIni("user_configure", iniList);
	this->close();
}

void dialog_UserConfigure::cancelButtonClick()
{
	
	this->close();
}

bool dialog_UserConfigure::passwordEncryptionProcess(QString &paswordstr)
{
	QByteArray passwordbyte  = paswordstr.toUtf8();
	paswordstr = QString(passwordbyte.toBase64());
	return true;
}

bool dialog_UserConfigure::passwordDecodeProcess(QString &paswordstr)
{

	QByteArray passwordbyte = QByteArray::fromBase64(paswordstr.toUtf8());
	paswordstr = QString(passwordbyte);
	return true;
}

void dialog_UserConfigure::initUi()
{
	ui.lineEdit_password->setEchoMode(QLineEdit::Password);
	ui.lineEdit_password->setPlaceholderText("please input password");
	ui.lineEdit_username->setPlaceholderText("please input username");
	ui.lineEdit_editsection->setPlaceholderText("Pelse input table order");
	IniFileProcesser initIniReader("./RecordTemp.ini");
	IniFileProcesser::VALUELISTDIC iniFileValue = initIniReader.fetchValueDictFromIni();
	for (auto &item : iniFileValue["user_configure"])
	{
		if (item.first == "username")
		{
			m_editSubmitContentsMap.insert({ "username",item.second });
		}
		else if (item.first == "password")
		{
			passwordDecodeProcess(item.second);
			m_editSubmitContentsMap.insert({ "password",item.second });
		}
		else if (item.first == "editsection")
		{
			m_editSubmitContentsMap.insert({ "editsection",item.second });
		}
	}
	showEvent(nullptr);
	connectslots();
	
}
