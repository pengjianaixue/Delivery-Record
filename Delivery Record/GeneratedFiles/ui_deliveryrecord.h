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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeliveryRecordClass
{
public:
    QAction *actionclean_contents;
    QAction *actionconfiguration;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QTableWidget *tablewideget_deliverytable;
    QWidget *widget_displayinfor;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_hidedispaly;
    QTextBrowser *textBrowser_updateInfor;
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
        DeliveryRecordClass->resize(1020, 775);
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
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tablewideget_deliverytable = new QTableWidget(centralWidget);
        tablewideget_deliverytable->setObjectName(QStringLiteral("tablewideget_deliverytable"));

        gridLayout_2->addWidget(tablewideget_deliverytable, 0, 0, 1, 1);

        widget_displayinfor = new QWidget(centralWidget);
        widget_displayinfor->setObjectName(QStringLiteral("widget_displayinfor"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_displayinfor->sizePolicy().hasHeightForWidth());
        widget_displayinfor->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(widget_displayinfor);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_hidedispaly = new QPushButton(widget_displayinfor);
        pushButton_hidedispaly->setObjectName(QStringLiteral("pushButton_hidedispaly"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_hidedispaly->sizePolicy().hasHeightForWidth());
        pushButton_hidedispaly->setSizePolicy(sizePolicy1);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/DeliveryRecord/Resources/hide.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_hidedispaly->setIcon(icon2);

        horizontalLayout->addWidget(pushButton_hidedispaly);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser_updateInfor = new QTextBrowser(widget_displayinfor);
        textBrowser_updateInfor->setObjectName(QStringLiteral("textBrowser_updateInfor"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textBrowser_updateInfor->sizePolicy().hasHeightForWidth());
        textBrowser_updateInfor->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(textBrowser_updateInfor);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget_displayinfor, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        progressBar_update = new QProgressBar(centralWidget);
        progressBar_update->setObjectName(QStringLiteral("progressBar_update"));
        progressBar_update->setValue(24);

        horizontalLayout_2->addWidget(progressBar_update);

        pushButton_update = new QPushButton(centralWidget);
        pushButton_update->setObjectName(QStringLiteral("pushButton_update"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/DeliveryRecord/Resources/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_update->setIcon(icon3);

        horizontalLayout_2->addWidget(pushButton_update);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        DeliveryRecordClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DeliveryRecordClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1020, 21));
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
        pushButton_hidedispaly->setText(QString());
        pushButton_update->setText(QApplication::translate("DeliveryRecordClass", "update", Q_NULLPTR));
        menuOperation->setTitle(QApplication::translate("DeliveryRecordClass", "Operation", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DeliveryRecordClass: public Ui_DeliveryRecordClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELIVERYRECORD_H
