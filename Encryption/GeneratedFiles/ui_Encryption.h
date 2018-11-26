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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EncryptionClass
{
public:
    QWidget *centralWidget;
    QPushButton *button_encrypt;
    QPushButton *button_decrypt;
    QWidget *widget;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_province;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_province;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_expData;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *lineEdit_expData;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_reagentApp;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *lineEdit_reagentApp;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_reagentID;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_reagentID;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_reagentNum;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_reagentNum;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_FxKey;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit_FxKey;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_DxKey;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEdit_DxKey;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_ciphertext;
    QSpacerItem *horizontalSpacer_6;
    QTextEdit *textEdit_ciphertext;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_sha;
    QSpacerItem *horizontalSpacer_7;
    QTextEdit *textEdit_sha;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_cal1;
    QLineEdit *lineEdit_cal1;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_cal2;
    QLineEdit *lineEdit_cal2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_cal3;
    QLineEdit *lineEdit_cal3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_cal4;
    QLineEdit *lineEdit_cal4;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_cal5;
    QLineEdit *lineEdit_cal5;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_cal6;
    QLineEdit *lineEdit_cal6;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_cal7;
    QLineEdit *lineEdit_cal7;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_cal8;
    QLineEdit *lineEdit_cal8;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EncryptionClass)
    {
        if (EncryptionClass->objectName().isEmpty())
            EncryptionClass->setObjectName(QStringLiteral("EncryptionClass"));
        EncryptionClass->resize(685, 605);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Encryption/dongnan.png"), QSize(), QIcon::Normal, QIcon::Off);
        EncryptionClass->setWindowIcon(icon);
        centralWidget = new QWidget(EncryptionClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        button_encrypt = new QPushButton(centralWidget);
        button_encrypt->setObjectName(QStringLiteral("button_encrypt"));
        button_encrypt->setGeometry(QRect(540, 100, 120, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        button_encrypt->setFont(font);
        button_decrypt = new QPushButton(centralWidget);
        button_decrypt->setObjectName(QStringLiteral("button_decrypt"));
        button_decrypt->setGeometry(QRect(540, 140, 120, 30));
        button_decrypt->setFont(font);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 478, 522));
        verticalLayout_10 = new QVBoxLayout(widget);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_province = new QLabel(widget);
        label_province->setObjectName(QStringLiteral("label_province"));
        label_province->setMinimumSize(QSize(60, 30));
        label_province->setFont(font);

        horizontalLayout->addWidget(label_province);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lineEdit_province = new QLineEdit(widget);
        lineEdit_province->setObjectName(QStringLiteral("lineEdit_province"));
        lineEdit_province->setEnabled(true);
        lineEdit_province->setMinimumSize(QSize(340, 30));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        lineEdit_province->setFont(font1);
        lineEdit_province->setMaxLength(2);

        horizontalLayout->addWidget(lineEdit_province);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_expData = new QLabel(widget);
        label_expData->setObjectName(QStringLiteral("label_expData"));
        label_expData->setMinimumSize(QSize(60, 30));
        label_expData->setFont(font);

        horizontalLayout_9->addWidget(label_expData);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);

        lineEdit_expData = new QLineEdit(widget);
        lineEdit_expData->setObjectName(QStringLiteral("lineEdit_expData"));
        lineEdit_expData->setEnabled(true);
        lineEdit_expData->setMinimumSize(QSize(340, 30));
        lineEdit_expData->setFont(font1);
        lineEdit_expData->setMaxLength(8);

        horizontalLayout_9->addWidget(lineEdit_expData);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_reagentApp = new QLabel(widget);
        label_reagentApp->setObjectName(QStringLiteral("label_reagentApp"));
        label_reagentApp->setMinimumSize(QSize(60, 30));
        label_reagentApp->setFont(font);

        horizontalLayout_8->addWidget(label_reagentApp);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        lineEdit_reagentApp = new QLineEdit(widget);
        lineEdit_reagentApp->setObjectName(QStringLiteral("lineEdit_reagentApp"));
        lineEdit_reagentApp->setEnabled(true);
        lineEdit_reagentApp->setMinimumSize(QSize(340, 30));
        lineEdit_reagentApp->setFont(font1);
        lineEdit_reagentApp->setMaxLength(2);

        horizontalLayout_8->addWidget(lineEdit_reagentApp);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_reagentID = new QLabel(widget);
        label_reagentID->setObjectName(QStringLiteral("label_reagentID"));
        label_reagentID->setMinimumSize(QSize(60, 30));
        label_reagentID->setFont(font);

        horizontalLayout_2->addWidget(label_reagentID);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lineEdit_reagentID = new QLineEdit(widget);
        lineEdit_reagentID->setObjectName(QStringLiteral("lineEdit_reagentID"));
        lineEdit_reagentID->setEnabled(true);
        lineEdit_reagentID->setMinimumSize(QSize(340, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("Consolas"));
        font2.setPointSize(14);
        lineEdit_reagentID->setFont(font2);
        lineEdit_reagentID->setMaxLength(5);

        horizontalLayout_2->addWidget(lineEdit_reagentID);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_reagentNum = new QLabel(widget);
        label_reagentNum->setObjectName(QStringLiteral("label_reagentNum"));
        label_reagentNum->setMinimumSize(QSize(60, 30));
        label_reagentNum->setFont(font);

        horizontalLayout_3->addWidget(label_reagentNum);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        lineEdit_reagentNum = new QLineEdit(widget);
        lineEdit_reagentNum->setObjectName(QStringLiteral("lineEdit_reagentNum"));
        lineEdit_reagentNum->setEnabled(true);
        lineEdit_reagentNum->setMinimumSize(QSize(340, 30));
        lineEdit_reagentNum->setFont(font2);
        lineEdit_reagentNum->setMaxLength(3);
        lineEdit_reagentNum->setReadOnly(false);

        horizontalLayout_3->addWidget(lineEdit_reagentNum);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_FxKey = new QLabel(widget);
        label_FxKey->setObjectName(QStringLiteral("label_FxKey"));
        label_FxKey->setMinimumSize(QSize(60, 30));
        label_FxKey->setFont(font);
        label_FxKey->setMidLineWidth(0);

        horizontalLayout_4->addWidget(label_FxKey);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        lineEdit_FxKey = new QLineEdit(widget);
        lineEdit_FxKey->setObjectName(QStringLiteral("lineEdit_FxKey"));
        lineEdit_FxKey->setEnabled(true);
        lineEdit_FxKey->setMinimumSize(QSize(340, 30));
        lineEdit_FxKey->setFont(font2);
        lineEdit_FxKey->setMaxLength(32767);
        lineEdit_FxKey->setReadOnly(true);

        horizontalLayout_4->addWidget(lineEdit_FxKey);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_DxKey = new QLabel(widget);
        label_DxKey->setObjectName(QStringLiteral("label_DxKey"));
        label_DxKey->setMinimumSize(QSize(60, 30));
        label_DxKey->setFont(font);
        label_DxKey->setMidLineWidth(0);

        horizontalLayout_5->addWidget(label_DxKey);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        lineEdit_DxKey = new QLineEdit(widget);
        lineEdit_DxKey->setObjectName(QStringLiteral("lineEdit_DxKey"));
        lineEdit_DxKey->setEnabled(true);
        lineEdit_DxKey->setMinimumSize(QSize(340, 30));
        lineEdit_DxKey->setFont(font2);
        lineEdit_DxKey->setMaxLength(16);
        lineEdit_DxKey->setReadOnly(true);

        horizontalLayout_5->addWidget(lineEdit_DxKey);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_ciphertext = new QLabel(widget);
        label_ciphertext->setObjectName(QStringLiteral("label_ciphertext"));
        label_ciphertext->setMinimumSize(QSize(60, 30));
        label_ciphertext->setMaximumSize(QSize(16777215, 40));
        label_ciphertext->setFont(font);
        label_ciphertext->setMidLineWidth(0);

        horizontalLayout_6->addWidget(label_ciphertext);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        textEdit_ciphertext = new QTextEdit(widget);
        textEdit_ciphertext->setObjectName(QStringLiteral("textEdit_ciphertext"));
        textEdit_ciphertext->setMinimumSize(QSize(340, 0));
        textEdit_ciphertext->setMaximumSize(QSize(340, 50));
        textEdit_ciphertext->setFont(font2);

        horizontalLayout_6->addWidget(textEdit_ciphertext);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_sha = new QLabel(widget);
        label_sha->setObjectName(QStringLiteral("label_sha"));
        label_sha->setMinimumSize(QSize(60, 30));
        label_sha->setFont(font);
        label_sha->setMidLineWidth(0);

        horizontalLayout_7->addWidget(label_sha);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        textEdit_sha = new QTextEdit(widget);
        textEdit_sha->setObjectName(QStringLiteral("textEdit_sha"));
        textEdit_sha->setMinimumSize(QSize(340, 0));
        textEdit_sha->setMaximumSize(QSize(16777215, 50));
        textEdit_sha->setFont(font2);

        horizontalLayout_7->addWidget(textEdit_sha);


        verticalLayout->addLayout(horizontalLayout_7);


        verticalLayout_10->addLayout(verticalLayout);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_cal1 = new QLabel(widget);
        label_cal1->setObjectName(QStringLiteral("label_cal1"));
        label_cal1->setMaximumSize(QSize(80, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(14);
        label_cal1->setFont(font3);

        verticalLayout_2->addWidget(label_cal1);

        lineEdit_cal1 = new QLineEdit(widget);
        lineEdit_cal1->setObjectName(QStringLiteral("lineEdit_cal1"));
        lineEdit_cal1->setMinimumSize(QSize(0, 30));
        lineEdit_cal1->setMaximumSize(QSize(80, 30));
        lineEdit_cal1->setFont(font2);
        lineEdit_cal1->setMaxLength(5);

        verticalLayout_2->addWidget(lineEdit_cal1);


        horizontalLayout_11->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_cal2 = new QLabel(widget);
        label_cal2->setObjectName(QStringLiteral("label_cal2"));
        label_cal2->setMaximumSize(QSize(80, 30));
        label_cal2->setFont(font3);

        verticalLayout_3->addWidget(label_cal2);

        lineEdit_cal2 = new QLineEdit(widget);
        lineEdit_cal2->setObjectName(QStringLiteral("lineEdit_cal2"));
        lineEdit_cal2->setMinimumSize(QSize(0, 30));
        lineEdit_cal2->setMaximumSize(QSize(80, 16777215));
        lineEdit_cal2->setFont(font2);
        lineEdit_cal2->setMaxLength(5);

        verticalLayout_3->addWidget(lineEdit_cal2);


        horizontalLayout_11->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_cal3 = new QLabel(widget);
        label_cal3->setObjectName(QStringLiteral("label_cal3"));
        label_cal3->setMaximumSize(QSize(80, 30));
        label_cal3->setFont(font3);

        verticalLayout_4->addWidget(label_cal3);

        lineEdit_cal3 = new QLineEdit(widget);
        lineEdit_cal3->setObjectName(QStringLiteral("lineEdit_cal3"));
        lineEdit_cal3->setMinimumSize(QSize(0, 30));
        lineEdit_cal3->setMaximumSize(QSize(80, 16777215));
        lineEdit_cal3->setFont(font2);
        lineEdit_cal3->setMaxLength(5);

        verticalLayout_4->addWidget(lineEdit_cal3);


        horizontalLayout_11->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_cal4 = new QLabel(widget);
        label_cal4->setObjectName(QStringLiteral("label_cal4"));
        label_cal4->setMaximumSize(QSize(80, 30));
        label_cal4->setFont(font3);

        verticalLayout_5->addWidget(label_cal4);

        lineEdit_cal4 = new QLineEdit(widget);
        lineEdit_cal4->setObjectName(QStringLiteral("lineEdit_cal4"));
        lineEdit_cal4->setMinimumSize(QSize(0, 30));
        lineEdit_cal4->setMaximumSize(QSize(80, 16777215));
        lineEdit_cal4->setFont(font2);
        lineEdit_cal4->setMaxLength(5);

        verticalLayout_5->addWidget(lineEdit_cal4);


        horizontalLayout_11->addLayout(verticalLayout_5);


        verticalLayout_10->addLayout(horizontalLayout_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_cal5 = new QLabel(widget);
        label_cal5->setObjectName(QStringLiteral("label_cal5"));
        label_cal5->setMaximumSize(QSize(80, 30));
        label_cal5->setFont(font3);

        verticalLayout_6->addWidget(label_cal5);

        lineEdit_cal5 = new QLineEdit(widget);
        lineEdit_cal5->setObjectName(QStringLiteral("lineEdit_cal5"));
        lineEdit_cal5->setMinimumSize(QSize(0, 30));
        lineEdit_cal5->setMaximumSize(QSize(80, 16777215));
        lineEdit_cal5->setFont(font2);
        lineEdit_cal5->setMaxLength(5);

        verticalLayout_6->addWidget(lineEdit_cal5);


        horizontalLayout_10->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_cal6 = new QLabel(widget);
        label_cal6->setObjectName(QStringLiteral("label_cal6"));
        label_cal6->setMaximumSize(QSize(80, 30));
        label_cal6->setFont(font3);

        verticalLayout_7->addWidget(label_cal6);

        lineEdit_cal6 = new QLineEdit(widget);
        lineEdit_cal6->setObjectName(QStringLiteral("lineEdit_cal6"));
        lineEdit_cal6->setMinimumSize(QSize(0, 30));
        lineEdit_cal6->setMaximumSize(QSize(80, 16777215));
        lineEdit_cal6->setFont(font2);
        lineEdit_cal6->setMaxLength(5);

        verticalLayout_7->addWidget(lineEdit_cal6);


        horizontalLayout_10->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_cal7 = new QLabel(widget);
        label_cal7->setObjectName(QStringLiteral("label_cal7"));
        label_cal7->setMaximumSize(QSize(80, 30));
        label_cal7->setFont(font3);

        verticalLayout_8->addWidget(label_cal7);

        lineEdit_cal7 = new QLineEdit(widget);
        lineEdit_cal7->setObjectName(QStringLiteral("lineEdit_cal7"));
        lineEdit_cal7->setMinimumSize(QSize(0, 30));
        lineEdit_cal7->setMaximumSize(QSize(80, 16777215));
        lineEdit_cal7->setFont(font2);
        lineEdit_cal7->setMaxLength(5);

        verticalLayout_8->addWidget(lineEdit_cal7);


        horizontalLayout_10->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_cal8 = new QLabel(widget);
        label_cal8->setObjectName(QStringLiteral("label_cal8"));
        label_cal8->setMaximumSize(QSize(80, 30));
        label_cal8->setFont(font3);

        verticalLayout_9->addWidget(label_cal8);

        lineEdit_cal8 = new QLineEdit(widget);
        lineEdit_cal8->setObjectName(QStringLiteral("lineEdit_cal8"));
        lineEdit_cal8->setMinimumSize(QSize(0, 30));
        lineEdit_cal8->setMaximumSize(QSize(80, 16777215));
        lineEdit_cal8->setFont(font2);
        lineEdit_cal8->setMaxLength(5);

        verticalLayout_9->addWidget(lineEdit_cal8);


        horizontalLayout_10->addLayout(verticalLayout_9);


        verticalLayout_10->addLayout(horizontalLayout_10);

        EncryptionClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EncryptionClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 685, 23));
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
        button_encrypt->setText(QApplication::translate("EncryptionClass", "\345\212\240\345\257\206", nullptr));
        button_decrypt->setText(QApplication::translate("EncryptionClass", "\350\247\243\345\257\206", nullptr));
        label_province->setText(QApplication::translate("EncryptionClass", "\347\234\201\344\273\275\357\274\232", nullptr));
        label_expData->setText(QApplication::translate("EncryptionClass", "\346\234\211\346\225\210\346\227\245\346\234\237\357\274\232", nullptr));
        label_reagentApp->setText(QApplication::translate("EncryptionClass", "\350\257\225\345\211\202\345\272\224\347\224\250\357\274\232", nullptr));
        label_reagentID->setText(QApplication::translate("EncryptionClass", "\350\257\225\345\211\202ID\357\274\232", nullptr));
        label_reagentNum->setText(QApplication::translate("EncryptionClass", "\350\257\225\345\211\202\346\254\241\346\225\260\357\274\232", nullptr));
        label_FxKey->setText(QApplication::translate("EncryptionClass", "\345\233\272\345\256\232\345\257\206\351\222\245\357\274\232", nullptr));
        lineEdit_FxKey->setInputMask(QString());
        lineEdit_FxKey->setText(QApplication::translate("EncryptionClass", "0123456789abcdef", nullptr));
        label_DxKey->setText(QApplication::translate("EncryptionClass", "\345\212\250\346\200\201\345\257\206\351\222\245\357\274\232", nullptr));
        label_ciphertext->setText(QApplication::translate("EncryptionClass", "\345\257\206\346\226\207\357\274\232", nullptr));
        label_sha->setText(QApplication::translate("EncryptionClass", "\346\225\243\345\210\227\345\200\274\357\274\232", nullptr));
        label_cal1->setText(QApplication::translate("EncryptionClass", "\346\240\207\345\256\232\345\200\2741\357\274\232", nullptr));
        lineEdit_cal1->setInputMask(QString());
        lineEdit_cal1->setText(QString());
        label_cal2->setText(QApplication::translate("EncryptionClass", "\346\240\207\345\256\232\345\200\2742\357\274\232", nullptr));
        label_cal3->setText(QApplication::translate("EncryptionClass", "\346\240\207\345\256\232\345\200\2743\357\274\232", nullptr));
        label_cal4->setText(QApplication::translate("EncryptionClass", "\346\240\207\345\256\232\345\200\2744\357\274\232", nullptr));
        label_cal5->setText(QApplication::translate("EncryptionClass", "\346\240\207\345\256\232\345\200\2745\357\274\232", nullptr));
        label_cal6->setText(QApplication::translate("EncryptionClass", "\346\240\207\345\256\232\345\200\2746\357\274\232", nullptr));
        label_cal7->setText(QApplication::translate("EncryptionClass", "\346\240\207\345\256\232\345\200\2747\357\274\232", nullptr));
        label_cal8->setText(QApplication::translate("EncryptionClass", "\346\240\207\345\256\232\345\200\2748\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EncryptionClass: public Ui_EncryptionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENCRYPTION_H
