#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_deliveryrecord.h"
#include "IniFileTemplateHandler.h"
#include "configure.h"

class DeliveryRecord : public QMainWindow
{
	Q_OBJECT

public:
	DeliveryRecord(QWidget *parent = Q_NULLPTR);
private:
	void resizeEvent(QResizeEvent * event) override;
	void InitUI();
	void connectSlots();

private slots :
	void openConfigurDialog(bool open);

private:
	Ui::DeliveryRecordClass ui;
	dialog_UserConfigure    configurUi;
	
};
