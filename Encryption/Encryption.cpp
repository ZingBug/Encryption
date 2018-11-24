#include "Encryption.h"

Encryption::Encryption(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void Encryption::button_encrypt_clicked()
{
	//��Կ
	QString qKey = ui.lineEdit_key->text();
	if (qKey.isEmpty())
	{
		//������ʾ
		QToolTip::showText(ui.lineEdit_key->mapToGlobal(QPoint(0, 0)),str2qstr("��ǰ����Ϊ��"));
		//�༭����
		ui.lineEdit_key->setStyleSheet("QLineEdit{border:1px solid red }");
		return;
	}
	else
	{
		//�ָ�֮ǰ��̬
		ui.lineEdit_key->setStyleSheet("QLineEdit{border:1px solid gray border-radius:1px}");
	}
	string strKey = qstr2str(qKey);
	int lenKey = strKey.length();
	char key[17] = "";
	for (int i = 0; i < lenKey&&i < 16; i++)
	{
		key[i] = strKey.at(i);
	}
	//����
	QString qText = ui.lineEdit_text->text();
	if (qText.isEmpty())
	{
		//������ʾ
		QToolTip::showText(ui.lineEdit_text->mapToGlobal(QPoint(0, 0)), str2qstr("��ǰ����Ϊ��"));
		//�༭����
		ui.lineEdit_text->setStyleSheet("QLineEdit{border:1px solid red }");
		return;
	}
	else
	{
		//�ָ�֮ǰ��̬
		ui.lineEdit_text->setStyleSheet("QLineEdit{border:1px solid gray border-radius:1px}");
	}
	string strText = qstr2str(qText);
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
	//��Կ
	QString qKey = ui.lineEdit_key->text();
	if (qKey.isEmpty())
	{
		//������ʾ
		QToolTip::showText(ui.lineEdit_key->mapToGlobal(QPoint(0, 0)), str2qstr("��ǰ��ԿΪ��"));
		//�༭����
		ui.lineEdit_key->setStyleSheet("QLineEdit{border:1px solid red }");
		return;
	}
	else
	{
		//�ָ�֮ǰ��̬
		ui.lineEdit_key->setStyleSheet("QLineEdit{border:1px solid gray border-radius:1px}");
	}
	string strKey = qstr2str(qKey);
	int lenKey = strKey.length();
	char key[17] = "";
	for (int i = 0; i < lenKey&&i < 16; i++)
	{
		key[i] = strKey.at(i);
	}
	//����
	QString qCip = ui.lineEdit_ciphertext->text();
	if (qCip.isEmpty())
	{
		//������ʾ
		QToolTip::showText(ui.lineEdit_ciphertext->mapToGlobal(QPoint(0, 0)), str2qstr("��ǰ����Ϊ��"));
		//�༭����
		ui.lineEdit_ciphertext->setStyleSheet("QLineEdit{border:1px solid red }");
		return;
	}
	else
	{
		//�ָ�֮ǰ��̬
		ui.lineEdit_ciphertext->setStyleSheet("QLineEdit{border:1px solid gray border-radius:1px}");
	}
	string strCip = qstr2str(qCip);
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
