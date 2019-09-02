/********************************************************************************
** Form generated from reading UI file 'deliveryrecord.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELIVERYRECORD_H
#define UI_DELIVERYRECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
            DeliveryRecordClass->setObjectName(QStringLiteral("DeliveryRecordClass"));
        DeliveryRecordClass->resize(863, 604);
        actionclean_contents = new QAction(DeliveryRecordClass);
        actionclean_contents->setObjectName(QStringLiteral("actionclean_contents"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/DeliveryRecord/Resources/clean.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionclean_contents->setIcon(icon);
        actionconfiguration = new QAction(DeliveryRecordClass);
        actionconfiguration->setObjectName(QStringLiteral("actionconfiguration"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/DeliveryRecord/Resources/configure.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionconfiguration->setIcon(icon1);
        centralWidget = new QWidget(DeliveryRecordClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tablewideget_deliverytable = new QTableWidget(centralWidget);
        tablewideget_deliverytable->setObjectName(QStringLiteral("tablewideget_deliverytable"));

        gridLayout->addWidget(tablewideget_deliverytable, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        progressBar_update = new QProgressBar(centralWidget);
        progressBar_update->setObjectName(QStringLiteral("progressBar_update"));
        progressBar_update->setValue(24);

        horizontalLayout_2->addWidget(progressBar_update);

        pushButton_update = new QPushButton(centralWidget);
        pushButton_update->setObjectName(QStringLiteral("pushButton_update"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/DeliveryRecord/Resources/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_update->setIcon(icon2);

        horizontalLayout_2->addWidget(pushButton_update);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        DeliveryRecordClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DeliveryRecordClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 863, 21));
        menuOperation = new QMenu(menuBar);
        menuOperation->setObjectName(QStringLiteral("menuOperation"));
        DeliveryRecordClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DeliveryRecordClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DeliveryRecordClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DeliveryRecordClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DeliveryRecordClass->setStatusBar(statusBar);

        menuBar->addAction(menuOperation->menuAction());
        menuOperation->addAction(actionclean_contents);
        menuOperation->addAction(actionconfiguration);
        mainToolBar->addAction(actionconfiguration);
        mainToolBar->addAction(actionclean_contents);

        retranslateUi(DeliveryRecordClass);

        QMetaObject::connectSlotsByName(DeliveryRecordClass);
    } // setupUi

    void retranslateUi(QMainWindow *DeliveryRecordClass)
    {
        DeliveryRecordClass->setWindowTitle(QApplication::translate("DeliveryRecordClass", "DeliveryRecord", Q_NULLPTR));
        actionclean_contents->setText(QApplication::translate("DeliveryRecordClass", "clean contents", Q_NULLPTR));
        actionconfiguration->setText(QApplication::translate("DeliveryRecordClass", "configuration", Q_NULLPTR));
        pushButton_update->setText(QApplication::translate("DeliveryRecordClass", "update", Q_NULLPTR));
        menuOperation->setTitle(QApplication::translate("DeliveryRecordClass", "Operation", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DeliveryRecordClass: public Ui_DeliveryRecordClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELIVERYRECORD_H
