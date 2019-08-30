#include "stdafx.h"
#include "deliveryrecord.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DeliveryRecord w;
	w.show();
	return a.exec();
}
