/********************************************************************************
** Form generated from reading UI file 'Setting.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Setting
{
public:
    QLabel *label_key;
    QPushButton *button_modify;
    QLineEdit *lineEdit_salt;
    QLabel *label_salt;
    QLineEdit *lineEdit_key;
    QPushButton *button_cancel;

    void setupUi(QWidget *Setting)
    {
        if (Setting->objectName().isEmpty())
            Setting->setObjectName(QStringLiteral("Setting"));
        Setting->resize(400, 250);
        label_key = new QLabel(Setting);
        label_key->setObjectName(QStringLiteral("label_key"));
        label_key->setGeometry(QRect(30, 20, 120, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        label_key->setFont(font);
        button_modify = new QPushButton(Setting);
        button_modify->setObjectName(QStringLiteral("button_modify"));
        button_modify->setGeometry(QRect(70, 200, 100, 30));
        button_modify->setFont(font);
        lineEdit_salt = new QLineEdit(Setting);
        lineEdit_salt->setObjectName(QStringLiteral("lineEdit_salt"));
        lineEdit_salt->setGeometry(QRect(30, 140, 340, 30));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setPointSize(14);
        lineEdit_salt->setFont(font1);
        lineEdit_salt->setMaxLength(10);
        label_salt = new QLabel(Setting);
        label_salt->setObjectName(QStringLiteral("label_salt"));
        label_salt->setGeometry(QRect(30, 100, 120, 30));
        label_salt->setFont(font);
        lineEdit_key = new QLineEdit(Setting);
        lineEdit_key->setObjectName(QStringLiteral("lineEdit_key"));
        lineEdit_key->setGeometry(QRect(30, 60, 340, 30));
        lineEdit_key->setFont(font1);
        lineEdit_key->setMaxLength(16);
        button_cancel = new QPushButton(Setting);
        button_cancel->setObjectName(QStringLiteral("button_cancel"));
        button_cancel->setGeometry(QRect(230, 200, 100, 30));
        button_cancel->setFont(font);

        retranslateUi(Setting);
        QObject::connect(button_modify, SIGNAL(clicked()), Setting, SLOT(button_modify_clicked()));
        QObject::connect(button_cancel, SIGNAL(clicked()), Setting, SLOT(button_cancel_clicked()));

        QMetaObject::connectSlotsByName(Setting);
    } // setupUi

    void retranslateUi(QWidget *Setting)
    {
        Setting->setWindowTitle(QApplication::translate("Setting", "Setting", nullptr));
        label_key->setText(QApplication::translate("Setting", "\345\257\206\351\222\245\357\274\232", nullptr));
        button_modify->setText(QApplication::translate("Setting", "\344\277\256\346\224\271", nullptr));
        label_salt->setText(QApplication::translate("Setting", "Salt\357\274\232", nullptr));
        button_cancel->setText(QApplication::translate("Setting", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Setting: public Ui_Setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
