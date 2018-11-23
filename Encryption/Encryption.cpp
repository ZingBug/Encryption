#include "Encryption.h"

Encryption::Encryption(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
}

void Encryption::button_encrypt_clicked()
{
	//ÃÜÔ¿
	string strKey = ui.lineEdit_key->text().toStdString();
	int lenKey = strKey.length();
	char key[17] = "";
	for (int i = 0; i < lenKey&&i < 16; i++)
	{
		key[i] = strKey.at(i);
	}
	//Ã÷ÎÄ
	string strText = qstr2str(ui.lineEdit_text->text());
	int lenText = strText.length();
	char text[17] = "";
	for (int i = 0; i < lenText; i++)
	{
		text[i] = strText.at(i);
	}
	char out[33] = "";
	aes.aesEncryptCode(text, 16, key, out);
	QString cip = QString(QLatin1String(out));
	ui.lineEdit_ciphertext->setText(cip);
}

QString Encryption::str2qstr(const string str)
{
	return QString::fromLocal8Bit(str.data());
}

string Encryption::qstr2str(const QString qstr)
{
	QByteArray cdata = qstr.toLocal8Bit();
	return string(cdata);
}

void Encryption::button_decrypt_clicked()
{
	//ÃÜÔ¿
	string strKey = ui.lineEdit_key->text().toStdString();
	int lenKey = strKey.length();
	char key[17] = "";
	for (int i = 0; i < lenKey&&i < 16; i++)
	{
		key[i] = strKey.at(i);
	}
	//ÃÜÎÄ
	string strCip = ui.lineEdit_ciphertext->text().toStdString();
	int lenCip = strCip.length();
	char cip[33] = "";
	for (int i = 0; i < lenCip; i++)
	{
		cip[i] = strCip.at(i);
	}
	char out[17] = "";
	aes.aesDecryptCode(cip, 32, key, out);
	string text = out;
	ui.lineEdit_decrypt->setText(str2qstr(text));
}
