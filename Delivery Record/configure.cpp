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
	if (!m_lineEditEmialRecvierAdd)
	{
		delete m_lineEditEmialRecvierAdd;
		m_lineEditEmialRecvierAdd = nullptr;
	}
}

bool dialog_UserConfigure::isEnableEmail() const
{
	return m_isSendEmail;
}

void dialog_UserConfigure::showEvent(QShowEvent *showevent)
{
	ui.lineEdit_username->setText(m_editSubmitContentsMap["username"]);
	QString passwordDecodestr = m_editSubmitContentsMap["password"];
	passwordDecodeProcess(passwordDecodestr);
	ui.lineEdit_password->setText(passwordDecodestr);
	ui.lineEdit_editsection->setText(m_editSubmitContentsMap["editsection"]);
	ui.lineEdit_emailcomments->setText(m_editSubmitContentsMap["emailcomments"]);
	ui.lineEdit_emailsender->setText(m_editSubmitContentsMap["emailsender"]);
	ui.lineEdit_username->setText(m_editSubmitContentsMap["username"]);

}

void dialog_UserConfigure::connectslots()
{
	this->connect(this->ui.okButton,&QPushButton::clicked,this, &dialog_UserConfigure::submitButtonClick);
	this->connect(this->ui.cancelButton, &QPushButton::clicked, this, &dialog_UserConfigure::cancelButtonClick);
	this->connect(this->ui.pushButton_removeEmailRecvier, &QPushButton::clicked, this, &dialog_UserConfigure::removeEmailRecvier);
	this->connect(this->ui.pushButton_addEmailRecvier, &QPushButton::clicked, this, &dialog_UserConfigure::addEmailRecvier);
	this->connect(this->ui.radioButton_enableSendEmail, &QRadioButton::clicked, this, &dialog_UserConfigure::emialRadioPushbuttonCliked);
	
}

void dialog_UserConfigure::submitButtonClick()
{
	m_editSubmitContentsMap.clear();
	m_editSubmitContentsMap.insert({ "username",ui.lineEdit_username->text()});
	QString passwordEncStr = ui.lineEdit_password->text();
	passwordEncryptionProcess(passwordEncStr);
	m_editSubmitContentsMap.insert({ "password",passwordEncStr});
	m_editSubmitContentsMap.insert({ "editsection",ui.lineEdit_editsection->text() });
	m_editSubmitContentsMap.insert({"emailcomments",ui.lineEdit_emailcomments->text()});
	m_editSubmitContentsMap.insert({ "emailsender",ui.lineEdit_emailsender->text() });
#ifdef _DEBUG
	qDebug() << ui.comboBox_emailrecviers->count();
#endif // _DEBUG
	for (size_t i = 0; i < ui.comboBox_emailrecviers->count(); i++)
	{

#ifdef _DEBUG
		qDebug() << ui.comboBox_emailrecviers->count();
#endif // _DEBUG
		m_editSubmitContentsMap.insert({QString("recvier_")+ QString::number(i),ui.comboBox_emailrecviers->itemText(i)});
	}
	QList<std::pair<QString, QString>> iniList;
	for (auto  &item : m_editSubmitContentsMap)
	{
		iniList.append({ item.first ,item.second });
	}
	IniFileProcesser iniFileWirter("./RecordTemp.ini");
	iniFileWirter.deleteGroupContents("user_configure");
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

void dialog_UserConfigure::removeEmailRecvier()
{
	ui.comboBox_emailrecviers->removeItem(ui.comboBox_emailrecviers->currentIndex());
}

void dialog_UserConfigure::addEmailRecvier()
{
	ui.comboBox_emailrecviers->lineEdit()->text();
	ui.comboBox_emailrecviers->addItem(ui.comboBox_emailrecviers->lineEdit()->text());
}


void dialog_UserConfigure::emialRadioPushbuttonCliked()
{
	if (ui.radioButton_enableSendEmail->isChecked())
	{
		m_isSendEmail = true;
		ui.widget_email->show();
	}
	else
	{
		m_isSendEmail = false;
		ui.widget_email->hide();
	}
}


void dialog_UserConfigure::initUi()
{
	ui.widget_email->hide();
	this->resize(QSize(this->geometry().width(),this->geometry().height()));
	ui.comboBox_emailrecviers->setEditable(true);
	ui.lineEdit_password->setEchoMode(QLineEdit::Password);
	ui.lineEdit_password->setPlaceholderText("please input password");
	ui.lineEdit_username->setPlaceholderText("please input username");
	ui.lineEdit_editsection->setPlaceholderText("Pelse input table order");
	IniFileProcesser initIniReader("./RecordTemp.ini");
	IniFileProcesser::VALUELISTDIC iniFileValue = initIniReader.fetchValueDictFromIni();
	for (auto &item : iniFileValue["user_configure"])
	{
		m_editSubmitContentsMap.insert({item.first,item.second });
	}
	for (size_t i = 0; i < (m_editSubmitContentsMap.size() - 5); i++)
	{
		ui.comboBox_emailrecviers->addItem(m_editSubmitContentsMap[QString("recvier_") + QString::number(i)]);
	}
	showEvent(nullptr);
	connectslots();
	
}
