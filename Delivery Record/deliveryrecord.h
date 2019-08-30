#pragma once

#include <QtWidgets/QMainWindow>
#include "IniFileTemplateHandler.h"
#include "ui_deliveryrecord.h"

class DeliveryRecord : public QMainWindow
{
	Q_OBJECT

public:
	DeliveryRecord(QWidget *parent = Q_NULLPTR);
	void resizeEvent(QResizeEvent * event) override;
	void InitUI();

private:
	Ui::DeliveryRecordClass ui;
};
