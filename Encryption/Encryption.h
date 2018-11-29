#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Encryption.h"
#include <string>
#include "AES.h"
#include <QToolTip>
#include "SHA256.h"
#include <QtSerialPort/qserialport.h>
#include <QtSerialPort/qserialportinfo.h>
#include <qmessagebox.h>
#include <qinputdialog.h>
#include "Setting.h"
#include "RWIniFile.h"
#include "SerialCard.h"

using namespace std;

class Encryption : public QMainWindow
{
	Q_OBJECT

public:
	Encryption(QWidget *parent = Q_NULLPTR);

private:
	Ui::EncryptionClass ui;
	AES aes;
	char salt[15] = "";
	QString str2qstr(const string str);
	string qstr2str(const QString qstr);
	void stringToHtmlFilter(QString &str);
	void stringToHtml(QString &str, QColor crl);
	QStringList getEnableCommPort();
	wchar_t *multiByteToWideChar(string str);

private slots:
	void button_encrypt_clicked();
	void button_decrypt_clicked();
	void textBrowser_message_textChanged();
	void button_readIC_clicked();
	void button_writeIC_clicked();
	void comboBox_port_clicked();
	void action_setting_triggered();
	void action_esc_triggered();
	void button_clearMessage_clicked();
};
