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
    QAction *actionsave;
    QAction *actionHelp;
    QAction *actionVersion;
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
    QPushButton *pushButton_sendemail;
    QPushButton *pushButton_logview;
    QPushButton *pushButton_update;
    QMenuBar *menuBar;
    QMenu *menuOperation;
    QMenu *menuAoubt;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DeliveryRecordClass)
    {
        if (DeliveryRecordClass->objectName().isEmpty())
            DeliveryRecordClass->setObjectName(QStringLiteral("DeliveryRecordClass"));
        DeliveryRecordClass->resize(1038, 811);
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
        actionsave = new QAction(DeliveryRecordClass);
        actionsave->setObjectName(QStringLiteral("actionsave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/DeliveryRecord/Resources/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsave->setIcon(icon2);
        actionHelp = new QAction(DeliveryRecordClass);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionVersion = new QAction(DeliveryRecordClass);
        actionVersion->setObjectName(QStringLiteral("actionVersion"));
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
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/DeliveryRecord/Resources/hide.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_hidedispaly->setIcon(icon3);

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

        pushButton_sendemail = new QPushButton(centralWidget);
        pushButton_sendemail->setObjectName(QStringLiteral("pushButton_sendemail"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/DeliveryRecord/Resources/send_email.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_sendemail->setIcon(icon4);

        horizontalLayout_2->addWidget(pushButton_sendemail);

        pushButton_logview = new QPushButton(centralWidget);
        pushButton_logview->setObjectName(QStringLiteral("pushButton_logview"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/DeliveryRecord/Resources/visual.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_logview->setIcon(icon5);

        horizontalLayout_2->addWidget(pushButton_logview);

        pushButton_update = new QPushButton(centralWidget);
        pushButton_update->setObjectName(QStringLiteral("pushButton_update"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/DeliveryRecord/Resources/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_update->setIcon(icon6);

        horizontalLayout_2->addWidget(pushButton_update);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        DeliveryRecordClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DeliveryRecordClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1038, 31));
        menuOperation = new QMenu(menuBar);
        menuOperation->setObjectName(QStringLiteral("menuOperation"));
        menuAoubt = new QMenu(menuBar);
        menuAoubt->setObjectName(QStringLiteral("menuAoubt"));
        DeliveryRecordClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DeliveryRecordClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DeliveryRecordClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DeliveryRecordClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DeliveryRecordClass->setStatusBar(statusBar);

        menuBar->addAction(menuOperation->menuAction());
        menuBar->addAction(menuAoubt->menuAction());
        menuOperation->addAction(actionclean_contents);
        menuOperation->addAction(actionconfiguration);
        menuOperation->addAction(actionsave);
        menuAoubt->addAction(actionHelp);
        menuAoubt->addAction(actionVersion);
        mainToolBar->addAction(actionconfiguration);
        mainToolBar->addAction(actionsave);
        mainToolBar->addAction(actionclean_contents);

        retranslateUi(DeliveryRecordClass);

        QMetaObject::connectSlotsByName(DeliveryRecordClass);
    } // setupUi

    void retranslateUi(QMainWindow *DeliveryRecordClass)
    {
        DeliveryRecordClass->setWindowTitle(QApplication::translate("DeliveryRecordClass", "DeliveryRecord", Q_NULLPTR));
        actionclean_contents->setText(QApplication::translate("DeliveryRecordClass", "clean contents", Q_NULLPTR));
        actionconfiguration->setText(QApplication::translate("DeliveryRecordClass", "configuration", Q_NULLPTR));
        actionsave->setText(QApplication::translate("DeliveryRecordClass", "save", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionsave->setShortcut(QApplication::translate("DeliveryRecordClass", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionHelp->setText(QApplication::translate("DeliveryRecordClass", "Help", Q_NULLPTR));
        actionVersion->setText(QApplication::translate("DeliveryRecordClass", "Version", Q_NULLPTR));
        pushButton_hidedispaly->setText(QString());
        pushButton_sendemail->setText(QApplication::translate("DeliveryRecordClass", "Send email", Q_NULLPTR));
        pushButton_logview->setText(QApplication::translate("DeliveryRecordClass", "Logview", Q_NULLPTR));
        pushButton_update->setText(QApplication::translate("DeliveryRecordClass", "Update", Q_NULLPTR));
        menuOperation->setTitle(QApplication::translate("DeliveryRecordClass", "Operation", Q_NULLPTR));
        menuAoubt->setTitle(QApplication::translate("DeliveryRecordClass", "About", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DeliveryRecordClass: public Ui_DeliveryRecordClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELIVERYRECORD_H
