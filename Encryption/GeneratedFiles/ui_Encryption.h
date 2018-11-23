/********************************************************************************
** Form generated from reading UI file 'Encryption.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENCRYPTION_H
#define UI_ENCRYPTION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EncryptionClass
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *button_encrypt;
    QPushButton *button_decrypt;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_key;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_key;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_text;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_text;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_ciphertext;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_ciphertext;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_decrypt;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit_decrypt;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EncryptionClass)
    {
        if (EncryptionClass->objectName().isEmpty())
            EncryptionClass->setObjectName(QStringLiteral("EncryptionClass"));
        EncryptionClass->resize(700, 330);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Encryption/dongnan.png"), QSize(), QIcon::Normal, QIcon::Off);
        EncryptionClass->setWindowIcon(icon);
        centralWidget = new QWidget(EncryptionClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 20, 640, 250));
        button_encrypt = new QPushButton(groupBox);
        button_encrypt->setObjectName(QStringLiteral("button_encrypt"));
        button_encrypt->setGeometry(QRect(500, 97, 120, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        button_encrypt->setFont(font);
        button_decrypt = new QPushButton(groupBox);
        button_decrypt->setObjectName(QStringLiteral("button_decrypt"));
        button_decrypt->setGeometry(QRect(500, 147, 120, 30));
        button_decrypt->setFont(font);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 40, 461, 190));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(15);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_key = new QLabel(layoutWidget);
        label_key->setObjectName(QStringLiteral("label_key"));
        label_key->setMinimumSize(QSize(60, 30));
        label_key->setFont(font);

        horizontalLayout->addWidget(label_key);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lineEdit_key = new QLineEdit(layoutWidget);
        lineEdit_key->setObjectName(QStringLiteral("lineEdit_key"));
        lineEdit_key->setEnabled(true);
        lineEdit_key->setMinimumSize(QSize(340, 30));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        lineEdit_key->setFont(font1);
        lineEdit_key->setMaxLength(16);

        horizontalLayout->addWidget(lineEdit_key);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_text = new QLabel(layoutWidget);
        label_text->setObjectName(QStringLiteral("label_text"));
        label_text->setMinimumSize(QSize(60, 30));
        label_text->setFont(font);

        horizontalLayout_2->addWidget(label_text);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lineEdit_text = new QLineEdit(layoutWidget);
        lineEdit_text->setObjectName(QStringLiteral("lineEdit_text"));
        lineEdit_text->setEnabled(true);
        lineEdit_text->setMinimumSize(QSize(340, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("Consolas"));
        font2.setPointSize(14);
        lineEdit_text->setFont(font2);
        lineEdit_text->setMaxLength(16);

        horizontalLayout_2->addWidget(lineEdit_text);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_ciphertext = new QLabel(layoutWidget);
        label_ciphertext->setObjectName(QStringLiteral("label_ciphertext"));
        label_ciphertext->setMinimumSize(QSize(60, 30));
        label_ciphertext->setFont(font);

        horizontalLayout_3->addWidget(label_ciphertext);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        lineEdit_ciphertext = new QLineEdit(layoutWidget);
        lineEdit_ciphertext->setObjectName(QStringLiteral("lineEdit_ciphertext"));
        lineEdit_ciphertext->setEnabled(true);
        lineEdit_ciphertext->setMinimumSize(QSize(340, 30));
        lineEdit_ciphertext->setFont(font2);
        lineEdit_ciphertext->setMaxLength(32);
        lineEdit_ciphertext->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEdit_ciphertext);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_decrypt = new QLabel(layoutWidget);
        label_decrypt->setObjectName(QStringLiteral("label_decrypt"));
        label_decrypt->setMinimumSize(QSize(60, 30));
        label_decrypt->setFont(font);
        label_decrypt->setMidLineWidth(0);

        horizontalLayout_4->addWidget(label_decrypt);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        lineEdit_decrypt = new QLineEdit(layoutWidget);
        lineEdit_decrypt->setObjectName(QStringLiteral("lineEdit_decrypt"));
        lineEdit_decrypt->setEnabled(true);
        lineEdit_decrypt->setMinimumSize(QSize(340, 30));
        lineEdit_decrypt->setFont(font2);
        lineEdit_decrypt->setMaxLength(16);
        lineEdit_decrypt->setReadOnly(true);

        horizontalLayout_4->addWidget(lineEdit_decrypt);


        verticalLayout->addLayout(horizontalLayout_4);

        EncryptionClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EncryptionClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 23));
        EncryptionClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EncryptionClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        EncryptionClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EncryptionClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        EncryptionClass->setStatusBar(statusBar);

        retranslateUi(EncryptionClass);
        QObject::connect(button_encrypt, SIGNAL(clicked()), EncryptionClass, SLOT(button_encrypt_clicked()));
        QObject::connect(button_decrypt, SIGNAL(clicked()), EncryptionClass, SLOT(button_decrypt_clicked()));

        QMetaObject::connectSlotsByName(EncryptionClass);
    } // setupUi

    void retranslateUi(QMainWindow *EncryptionClass)
    {
        EncryptionClass->setWindowTitle(QApplication::translate("EncryptionClass", "Encryption", nullptr));
        groupBox->setTitle(QApplication::translate("EncryptionClass", "AES\345\212\240\345\257\206\347\263\273\347\273\237", nullptr));
        button_encrypt->setText(QApplication::translate("EncryptionClass", "\345\212\240\345\257\206", nullptr));
        button_decrypt->setText(QApplication::translate("EncryptionClass", "\350\247\243\345\257\206", nullptr));
        label_key->setText(QApplication::translate("EncryptionClass", "\345\257\206\351\222\245\357\274\232", nullptr));
        label_text->setText(QApplication::translate("EncryptionClass", "\346\230\216\346\226\207\357\274\232", nullptr));
        label_ciphertext->setText(QApplication::translate("EncryptionClass", "\345\257\206\346\226\207\357\274\232", nullptr));
        label_decrypt->setText(QApplication::translate("EncryptionClass", "\350\247\243\345\257\206\346\225\260\346\215\256\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EncryptionClass: public Ui_EncryptionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENCRYPTION_H
