#pragma once

#include <QWidget>
#include <QAbstractItemModel>
#include "ui_configure.h"
#include "XmlWirter.h"
#include "XmlReader.h"
#include "IniFileTemplateHandler.h"
#include "QTextEditDelegate.h"
class UserConfigureDialog : public QDialog
{
	Q_OBJECT

public:
	explicit UserConfigureDialog(QWidget *parent = Q_NULLPTR);
	~UserConfigureDialog();
	bool isEnableEmail() const;
protected:
	void showEvent(QShowEvent *showevent) override;
	bool eventFilter(QObject *target, QEvent *event) override ;
	
private slots:
	void initUi();
	bool connectslots();
	void submitButtonClick();
	void cancelButtonClick();
	bool passwordEncryptionProcess(QString &paswordstr);
	bool passwordDecodeProcess(QString &paswordstr);
	void removeEmailRecvier();
	void addEmailRecvier();
	void emialRadioPushbuttonCliked();
	void setEditRowWidth();
	void rowAdd(int row, int cloumu);
	void rowOperationMenu(const QPoint &pos);
	void addTableInCell();
	
private:
	Ui::Configure ui;
	std::map<QString,QString>				m_editSubmitContentsMap;
	QLineEdit								*m_lineEditEmialRecvierAdd	= {nullptr};
	bool									m_isSendEmail				= { false };
	QTextEditDelegate						*m_pInputTextEditorDelegate = {nullptr};
	XmlWirter								m_xmlWirter;
	XmlReader								m_xmlReader;
	
};
