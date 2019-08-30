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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
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
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *Lable_username;
    QLabel *Lable_password;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
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
        DeliveryRecordClass->resize(600, 400);
        actionclean_contents = new QAction(DeliveryRecordClass);
        actionclean_contents->setObjectName(QStringLiteral("actionclean_contents"));
        actionconfiguration = new QAction(DeliveryRecordClass);
        actionconfiguration->setObjectName(QStringLiteral("actionconfiguration"));
        centralWidget = new QWidget(DeliveryRecordClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Lable_username = new QLabel(centralWidget);
        Lable_username->setObjectName(QStringLiteral("Lable_username"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Lable_username->sizePolicy().hasHeightForWidth());
        Lable_username->setSizePolicy(sizePolicy);
        Lable_username->setMinimumSize(QSize(30, 5));
        Lable_username->setStyleSheet(QStringLiteral("image: url(:/DeliveryRecord/Resources/user-name.png);"));
        Lable_username->setFrameShape(QFrame::NoFrame);

        verticalLayout->addWidget(Lable_username);

        Lable_password = new QLabel(centralWidget);
        Lable_password->setObjectName(QStringLiteral("Lable_password"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Lable_password->sizePolicy().hasHeightForWidth());
        Lable_password->setSizePolicy(sizePolicy1);
        Lable_password->setMinimumSize(QSize(30, 5));
        Lable_password->setStyleSheet(QStringLiteral("image: url(:/DeliveryRecord/Resources/password normal.png);"));

        verticalLayout->addWidget(Lable_password);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEdit_username = new QLineEdit(centralWidget);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_username->sizePolicy().hasHeightForWidth());
        lineEdit_username->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(lineEdit_username);

        lineEdit_password = new QLineEdit(centralWidget);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        sizePolicy2.setHeightForWidth(lineEdit_password->sizePolicy().hasHeightForWidth());
        lineEdit_password->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(lineEdit_password);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        tablewideget_deliverytable = new QTableWidget(centralWidget);
        tablewideget_deliverytable->setObjectName(QStringLiteral("tablewideget_deliverytable"));

        verticalLayout_3->addWidget(tablewideget_deliverytable);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        progressBar_update = new QProgressBar(centralWidget);
        progressBar_update->setObjectName(QStringLiteral("progressBar_update"));
        progressBar_update->setValue(24);

        horizontalLayout_2->addWidget(progressBar_update);

        pushButton_update = new QPushButton(centralWidget);
        pushButton_update->setObjectName(QStringLiteral("pushButton_update"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/DeliveryRecord/Resources/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_update->setIcon(icon);

        horizontalLayout_2->addWidget(pushButton_update);


        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        DeliveryRecordClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DeliveryRecordClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 22));
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

        retranslateUi(DeliveryRecordClass);

        QMetaObject::connectSlotsByName(DeliveryRecordClass);
    } // setupUi

    void retranslateUi(QMainWindow *DeliveryRecordClass)
    {
        DeliveryRecordClass->setWindowTitle(QApplication::translate("DeliveryRecordClass", "DeliveryRecord", Q_NULLPTR));
        actionclean_contents->setText(QApplication::translate("DeliveryRecordClass", "clean contents", Q_NULLPTR));
        actionconfiguration->setText(QApplication::translate("DeliveryRecordClass", "configuration", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        Lable_username->setWhatsThis(QApplication::translate("DeliveryRecordClass", "<html><head/><body><p>user name</p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        Lable_username->setText(QString());
#ifndef QT_NO_WHATSTHIS
        Lable_password->setWhatsThis(QApplication::translate("DeliveryRecordClass", "<html><head/><body><p>password</p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        Lable_password->setText(QString());
#ifndef QT_NO_ACCESSIBILITY
        lineEdit_username->setAccessibleDescription(QApplication::translate("DeliveryRecordClass", "please input username", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        lineEdit_password->setAccessibleDescription(QApplication::translate("DeliveryRecordClass", "please input password", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        pushButton_update->setText(QApplication::translate("DeliveryRecordClass", "update", Q_NULLPTR));
        menuOperation->setTitle(QApplication::translate("DeliveryRecordClass", "Operation", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DeliveryRecordClass: public Ui_DeliveryRecordClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELIVERYRECORD_H
