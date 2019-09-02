#pragma once

#include <QWidget>
#include "ui_configure.h"
#include "IniFileTemplateHandler.h"
class dialog_UserConfigure : public QDialog
{
	Q_OBJECT

public:
	dialog_UserConfigure(QWidget *parent = Q_NULLPTR);
	~dialog_UserConfigure();
private slots:
	void initUi();
	void connectslots();
	void submitButtonClick();
	void cancelButtonClick();

private:
	Ui::Configure ui;
};
