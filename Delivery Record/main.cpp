#include "stdafx.h"
#include "deliveryrecord.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QApplication::setStyle(QStyleFactory::create("Fusion"));
	DeliveryRecord w;
	w.setWindowTitle("Delivery Record");
	w.show();
	return a.exec(); 
}
