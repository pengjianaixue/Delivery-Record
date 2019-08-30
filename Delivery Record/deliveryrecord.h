#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_deliveryrecord.h"

class DeliveryRecord : public QMainWindow
{
	Q_OBJECT

public:
	DeliveryRecord(QWidget *parent = Q_NULLPTR);

private:
	Ui::DeliveryRecordClass ui;
};
