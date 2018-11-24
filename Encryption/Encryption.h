#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Encryption.h"
#include <string>
#include "AES.h"
#include <QToolTip>

using namespace std;

class Encryption : public QMainWindow
{
	Q_OBJECT

public:
	Encryption(QWidget *parent = Q_NULLPTR);

private:
	Ui::EncryptionClass ui;
	AES aes;
	QString str2qstr(const string str);
	string qstr2str(const QString qstr);

public slots:
	void button_encrypt_clicked();
	void button_decrypt_clicked();
};