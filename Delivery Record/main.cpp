#include "stdafx.h"
#include "deliveryrecord.h"
#include <QtWidgets/QApplication>
#include<qmetatype.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	qRegisterMetaType<QList<QString>>();
	QFile qss(":/qdarkstyle/style.qss");
	qss.open(QFile::ReadOnly);
	a.setStyleSheet(qss.readAll());
	qss.close();
	QApplication::setStyle("Fusion");
	a.setWindowIcon(QIcon(":/DeliveryRecord/Resources/release-notes.png"));
	DeliveryRecord w;
	w.setWindowTitle("Delivery Record");
	w.show();
	return a.exec(); 
}
