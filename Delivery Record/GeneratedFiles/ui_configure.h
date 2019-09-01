/********************************************************************************
** Form generated from reading UI file 'configure.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURE_H
#define UI_CONFIGURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Configure
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *Lable_username;
    QLabel *Lable_password;
    QLabel *Lable_editsection;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_editsection;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *Configure)
    {
        if (Configure->objectName().isEmpty())
            Configure->setObjectName(QString::fromUtf8("Configure"));
        Configure->resize(428, 197);
        gridLayout = new QGridLayout(Configure);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Lable_username = new QLabel(Configure);
        Lable_username->setObjectName(QString::fromUtf8("Lable_username"));
        Lable_username->setMinimumSize(QSize(30, 0));
        Lable_username->setStyleSheet(QString::fromUtf8("image: url(:/DeliveryRecord/Resources/user-name.png);"));

        verticalLayout->addWidget(Lable_username);

        Lable_password = new QLabel(Configure);
        Lable_password->setObjectName(QString::fromUtf8("Lable_password"));
        Lable_password->setStyleSheet(QString::fromUtf8("image: url(:/DeliveryRecord/Resources/password normal.png);"));

        verticalLayout->addWidget(Lable_password);

        Lable_editsection = new QLabel(Configure);
        Lable_editsection->setObjectName(QString::fromUtf8("Lable_editsection"));
        Lable_editsection->setStyleSheet(QString::fromUtf8("image: url(:/DeliveryRecord/Resources/section.png);"));

        verticalLayout->addWidget(Lable_editsection);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lineEdit_username = new QLineEdit(Configure);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));

        verticalLayout_3->addWidget(lineEdit_username);

        lineEdit_password = new QLineEdit(Configure);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));

        verticalLayout_3->addWidget(lineEdit_password);

        lineEdit_editsection = new QLineEdit(Configure);
        lineEdit_editsection->setObjectName(QString::fromUtf8("lineEdit_editsection"));

        verticalLayout_3->addWidget(lineEdit_editsection);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(Configure);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(Configure);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        hboxLayout->addWidget(cancelButton);


        gridLayout->addLayout(hboxLayout, 1, 0, 1, 1);


        retranslateUi(Configure);

        QMetaObject::connectSlotsByName(Configure);
    } // setupUi

    void retranslateUi(QWidget *Configure)
    {
        Configure->setWindowTitle(QApplication::translate("Configure", "Configure", nullptr));
        Lable_username->setText(QString());
        Lable_password->setText(QString());
        Lable_editsection->setText(QString());
        okButton->setText(QApplication::translate("Configure", "OK", nullptr));
        cancelButton->setText(QApplication::translate("Configure", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Configure: public Ui_Configure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURE_H
