/********************************************************************************
** Form generated from reading UI file 'configure.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURE_H
#define UI_CONFIGURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Configure
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *Lable_username;
    QLabel *Lable_password;
    QLabel *Lable_editsection;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_editsection;
    QRadioButton *radioButton_enableSendEmail;
    QWidget *widget_email;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *Lable_email_sender;
    QLabel *Lable_editsection_DelieveryComments;
    QLabel *Lable_editsection_EmailRecviers;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *lineEdit_emailsender;
    QLineEdit *lineEdit_emailcomments;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBox_emailrecviers;
    QPushButton *pushButton_addEmailRecvier;
    QPushButton *pushButton_removeEmailRecvier;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *spacer;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *Configure)
    {
        if (Configure->objectName().isEmpty())
            Configure->setObjectName(QStringLiteral("Configure"));
        Configure->resize(610, 335);
        gridLayout_2 = new QGridLayout(Configure);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        Lable_username = new QLabel(Configure);
        Lable_username->setObjectName(QStringLiteral("Lable_username"));
        Lable_username->setMinimumSize(QSize(30, 0));
        Lable_username->setStyleSheet(QStringLiteral("image: url(:/DeliveryRecord/Resources/user-name.png);"));

        verticalLayout_2->addWidget(Lable_username);

        Lable_password = new QLabel(Configure);
        Lable_password->setObjectName(QStringLiteral("Lable_password"));
        Lable_password->setMinimumSize(QSize(30, 0));
        Lable_password->setStyleSheet(QStringLiteral("image: url(:/DeliveryRecord/Resources/password normal.png);"));

        verticalLayout_2->addWidget(Lable_password);

        Lable_editsection = new QLabel(Configure);
        Lable_editsection->setObjectName(QStringLiteral("Lable_editsection"));
        Lable_editsection->setMinimumSize(QSize(30, 0));
        Lable_editsection->setStyleSheet(QStringLiteral("image: url(:/DeliveryRecord/Resources/section.png);"));

        verticalLayout_2->addWidget(Lable_editsection);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lineEdit_username = new QLineEdit(Configure);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));

        verticalLayout_3->addWidget(lineEdit_username);

        lineEdit_password = new QLineEdit(Configure);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));

        verticalLayout_3->addWidget(lineEdit_password);

        lineEdit_editsection = new QLineEdit(Configure);
        lineEdit_editsection->setObjectName(QStringLiteral("lineEdit_editsection"));

        verticalLayout_3->addWidget(lineEdit_editsection);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);

        radioButton_enableSendEmail = new QRadioButton(Configure);
        radioButton_enableSendEmail->setObjectName(QStringLiteral("radioButton_enableSendEmail"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/DeliveryRecord/Resources/email_send.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton_enableSendEmail->setIcon(icon);
        radioButton_enableSendEmail->setCheckable(true);
        radioButton_enableSendEmail->setChecked(false);

        verticalLayout_4->addWidget(radioButton_enableSendEmail);


        verticalLayout_6->addLayout(verticalLayout_4);

        widget_email = new QWidget(Configure);
        widget_email->setObjectName(QStringLiteral("widget_email"));
        gridLayout = new QGridLayout(widget_email);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Lable_email_sender = new QLabel(widget_email);
        Lable_email_sender->setObjectName(QStringLiteral("Lable_email_sender"));
        Lable_email_sender->setMinimumSize(QSize(30, 0));
        Lable_email_sender->setStyleSheet(QStringLiteral("image: url(:/DeliveryRecord/Resources/email_account_suser.png);"));

        verticalLayout->addWidget(Lable_email_sender);

        Lable_editsection_DelieveryComments = new QLabel(widget_email);
        Lable_editsection_DelieveryComments->setObjectName(QStringLiteral("Lable_editsection_DelieveryComments"));
        Lable_editsection_DelieveryComments->setMinimumSize(QSize(30, 0));
        Lable_editsection_DelieveryComments->setStyleSheet(QStringLiteral("image: url(:/DeliveryRecord/Resources/comments.png);"));

        verticalLayout->addWidget(Lable_editsection_DelieveryComments);

        Lable_editsection_EmailRecviers = new QLabel(widget_email);
        Lable_editsection_EmailRecviers->setObjectName(QStringLiteral("Lable_editsection_EmailRecviers"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Lable_editsection_EmailRecviers->sizePolicy().hasHeightForWidth());
        Lable_editsection_EmailRecviers->setSizePolicy(sizePolicy);
        Lable_editsection_EmailRecviers->setMinimumSize(QSize(30, 0));
        Lable_editsection_EmailRecviers->setStyleSheet(QStringLiteral("image: url(:/DeliveryRecord/Resources/Email Connect.png);"));

        verticalLayout->addWidget(Lable_editsection_EmailRecviers);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        lineEdit_emailsender = new QLineEdit(widget_email);
        lineEdit_emailsender->setObjectName(QStringLiteral("lineEdit_emailsender"));

        verticalLayout_5->addWidget(lineEdit_emailsender);

        lineEdit_emailcomments = new QLineEdit(widget_email);
        lineEdit_emailcomments->setObjectName(QStringLiteral("lineEdit_emailcomments"));

        verticalLayout_5->addWidget(lineEdit_emailcomments);


        verticalLayout_8->addLayout(verticalLayout_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        comboBox_emailrecviers = new QComboBox(widget_email);
        comboBox_emailrecviers->setObjectName(QStringLiteral("comboBox_emailrecviers"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_emailrecviers->sizePolicy().hasHeightForWidth());
        comboBox_emailrecviers->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(comboBox_emailrecviers);

        pushButton_addEmailRecvier = new QPushButton(widget_email);
        pushButton_addEmailRecvier->setObjectName(QStringLiteral("pushButton_addEmailRecvier"));
        sizePolicy1.setHeightForWidth(pushButton_addEmailRecvier->sizePolicy().hasHeightForWidth());
        pushButton_addEmailRecvier->setSizePolicy(sizePolicy1);
        pushButton_addEmailRecvier->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/DeliveryRecord/Resources/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_addEmailRecvier->setIcon(icon1);

        horizontalLayout_5->addWidget(pushButton_addEmailRecvier);

        pushButton_removeEmailRecvier = new QPushButton(widget_email);
        pushButton_removeEmailRecvier->setObjectName(QStringLiteral("pushButton_removeEmailRecvier"));
        sizePolicy1.setHeightForWidth(pushButton_removeEmailRecvier->sizePolicy().hasHeightForWidth());
        pushButton_removeEmailRecvier->setSizePolicy(sizePolicy1);
        pushButton_removeEmailRecvier->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/DeliveryRecord/Resources/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_removeEmailRecvier->setIcon(icon2);

        horizontalLayout_5->addWidget(pushButton_removeEmailRecvier);

        horizontalLayout_5->setStretch(0, 8);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 1);

        verticalLayout_8->addLayout(horizontalLayout_5);

        verticalLayout_8->setStretch(0, 6);
        verticalLayout_8->setStretch(1, 3);

        horizontalLayout_2->addLayout(verticalLayout_8);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        verticalLayout_6->addWidget(widget_email);


        verticalLayout_7->addLayout(verticalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        spacer = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(spacer);

        okButton = new QPushButton(Configure);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout_3->addWidget(okButton);

        cancelButton = new QPushButton(Configure);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_3->addWidget(cancelButton);


        verticalLayout_7->addLayout(horizontalLayout_3);

        verticalLayout_7->setStretch(0, 9);
        verticalLayout_7->setStretch(1, 1);

        gridLayout_2->addLayout(verticalLayout_7, 0, 0, 1, 1);


        retranslateUi(Configure);

        QMetaObject::connectSlotsByName(Configure);
    } // setupUi

    void retranslateUi(QWidget *Configure)
    {
        Configure->setWindowTitle(QApplication::translate("Configure", "Configure", Q_NULLPTR));
        Lable_username->setText(QString());
        Lable_password->setText(QString());
        Lable_editsection->setText(QString());
        radioButton_enableSendEmail->setText(QApplication::translate("Configure", "Enable Email Send", Q_NULLPTR));
        Lable_email_sender->setText(QString());
        Lable_editsection_DelieveryComments->setText(QString());
        Lable_editsection_EmailRecviers->setText(QString());
        pushButton_addEmailRecvier->setText(QApplication::translate("Configure", "AddRecvier", Q_NULLPTR));
        pushButton_removeEmailRecvier->setText(QApplication::translate("Configure", "RemoveRecvier", Q_NULLPTR));
        okButton->setText(QApplication::translate("Configure", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("Configure", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Configure: public Ui_Configure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURE_H
