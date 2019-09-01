/********************************************************************************
** Form generated from reading UI file 'deliveryrecord.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELIVERYRECORD_H
#define UI_DELIVERYRECORD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeliveryRecordClass
{
public:
    QAction *actionclean_contents;
    QAction *actionconfiguration;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTableWidget *tablewideget_deliverytable;
    QHBoxLayout *horizontalLayout_2;
    QProgressBar *progressBar_update;
    QPushButton *pushButton_update;
    QMenuBar *menuBar;
    QMenu *menuOperation;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DeliveryRecordClass)
    {
        if (DeliveryRecordClass->objectName().isEmpty())
            DeliveryRecordClass->setObjectName(QString::fromUtf8("DeliveryRecordClass"));
        DeliveryRecordClass->resize(863, 604);
        actionclean_contents = new QAction(DeliveryRecordClass);
        actionclean_contents->setObjectName(QString::fromUtf8("actionclean_contents"));
        actionconfiguration = new QAction(DeliveryRecordClass);
        actionconfiguration->setObjectName(QString::fromUtf8("actionconfiguration"));
        centralWidget = new QWidget(DeliveryRecordClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tablewideget_deliverytable = new QTableWidget(centralWidget);
        tablewideget_deliverytable->setObjectName(QString::fromUtf8("tablewideget_deliverytable"));

        gridLayout->addWidget(tablewideget_deliverytable, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        progressBar_update = new QProgressBar(centralWidget);
        progressBar_update->setObjectName(QString::fromUtf8("progressBar_update"));
        progressBar_update->setValue(24);

        horizontalLayout_2->addWidget(progressBar_update);

        pushButton_update = new QPushButton(centralWidget);
        pushButton_update->setObjectName(QString::fromUtf8("pushButton_update"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/DeliveryRecord/Resources/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_update->setIcon(icon);

        horizontalLayout_2->addWidget(pushButton_update);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        DeliveryRecordClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DeliveryRecordClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 863, 23));
        menuOperation = new QMenu(menuBar);
        menuOperation->setObjectName(QString::fromUtf8("menuOperation"));
        DeliveryRecordClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DeliveryRecordClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DeliveryRecordClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DeliveryRecordClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DeliveryRecordClass->setStatusBar(statusBar);

        menuBar->addAction(menuOperation->menuAction());
        menuOperation->addAction(actionclean_contents);
        menuOperation->addAction(actionconfiguration);

        retranslateUi(DeliveryRecordClass);

        QMetaObject::connectSlotsByName(DeliveryRecordClass);
    } // setupUi

    void retranslateUi(QMainWindow *DeliveryRecordClass)
    {
        DeliveryRecordClass->setWindowTitle(QApplication::translate("DeliveryRecordClass", "DeliveryRecord", nullptr));
        actionclean_contents->setText(QApplication::translate("DeliveryRecordClass", "clean contents", nullptr));
        actionconfiguration->setText(QApplication::translate("DeliveryRecordClass", "configuration", nullptr));
        pushButton_update->setText(QApplication::translate("DeliveryRecordClass", "update", nullptr));
        menuOperation->setTitle(QApplication::translate("DeliveryRecordClass", "Operation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeliveryRecordClass: public Ui_DeliveryRecordClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELIVERYRECORD_H
