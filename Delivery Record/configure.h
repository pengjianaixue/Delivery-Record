#pragma once

#include <QWidget>
#include "ui_configure.h"
#include "IniFileTemplateHandler.h"
class dialog_UserConfigure : public QWidget
{
	Q_OBJECT

public:
	dialog_UserConfigure(QWidget *parent = Q_NULLPTR);
	~dialog_UserConfigure();
	void initUi();

private:
	Ui::Configure ui;
};
