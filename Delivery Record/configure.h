#pragma once

#include <QWidget>
#include "ui_configure.h"
#include "XmlWirter.h"
#include "XmlReader.h"
#include "IniFileTemplateHandler.h"
#include "QTextEditDelegate.h"
class dialog_UserConfigure : public QDialog
{
	Q_OBJECT

public:
	dialog_UserConfigure(QWidget *parent = Q_NULLPTR);
	~dialog_UserConfigure();
	bool isEnableEmail() const;
protected:
	void showEvent(QShowEvent *showevent) override;
private slots:
	void initUi();
	void connectslots();
	void submitButtonClick();
	void cancelButtonClick();
	bool passwordEncryptionProcess(QString &paswordstr);
	bool passwordDecodeProcess(QString &paswordstr);
	void removeEmailRecvier();
	void addEmailRecvier();
	void emialRadioPushbuttonCliked();
private:
	Ui::Configure ui;
	std::map<QString,QString>				m_editSubmitContentsMap;
	QLineEdit								*m_lineEditEmialRecvierAdd	= {nullptr};
	bool									m_isSendEmail				= { false };
	std::shared_ptr<QTextEditDelegate>		m_pInputTextEditorDelegate  = std::make_shared<QTextEditDelegate>(this);
	XmlWirter								m_xmlWirter;
	XmlReader								m_xmlReader;
	
};
