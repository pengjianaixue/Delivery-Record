#include "stdafx.h"
#include "deliveryrecord.h"
#include <QtWidgets/QApplication>
#include<qmetatype.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	qRegisterMetaType<QList<QString>>();
	QApplication::setStyle(QStyleFactory::create("Fusion"));
	DeliveryRecord w;
	w.setWindowTitle("Delivery Record");
	w.show();
	return a.exec(); 
}
