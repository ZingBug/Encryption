#include "Encryption.h"

Encryption::Encryption(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//��ȡ��Կ��salt
	QString qstr_key;
	QString qstr_salt;
	qstr_key = RWIniFile::readIni(RWIniFile::iniPath, "config1", "key", qstr_key);
	qstr_salt = RWIniFile::readIni(RWIniFile::iniPath, "config1", "salt", qstr_salt);
	if (qstr_key.length() == 0)
	{
		qstr_key = "0123456789abcdef";
	}
	if (qstr_salt.length() == 0)
	{
		qstr_salt = "sinnowa";
	}
	ui.lineEdit_FxKey->setText(qstr_key);
	string str_salt = qstr2str(qstr_salt);
	for (int i = 0; i < str_salt.length(); i++)
	{
		salt[i] = str_salt.at(i);
	}

	//��ȡ����
	QStringList list = getEnableCommPort();
	ui.comboBox_port->clear();
	for (int i = 0; i < list.size(); i++)
	{
		QString str = list.at(i);
		ui.comboBox_port->addItem(str);
	}
}

void Encryption::button_encrypt_clicked()
{
	char text1[64];//�̶���Կ����
	char text2[17];//��̬��Կ����
	char shaIn[50];//sha������
	memset(text1, 33, sizeof(text1));//���帳ֵ��ĸ!
	memset(text2, 33, sizeof(text2));//���帳ֵ��ĸ!
	memset(shaIn, 48, sizeof(shaIn));//���帳ֵ����0

	text1[0] = 0x80;//��ʼ֡
	text2[0] = 0x80;//��ʼ֡

	string str_province = qstr2str(ui.lineEdit_province->text());//����1
	string str_reagentApp = qstr2str(ui.lineEdit_reagentApp->text());//����1
	string str_reagentID = qstr2str(ui.lineEdit_reagentID->text());//����1
	string str_reagentNum = qstr2str(ui.lineEdit_reagentNum->text());//����2
	string str_expData = qstr2str(ui.lineEdit_expData->text());//����2
	if (str_reagentApp.length() != 2 || str_reagentID.length() != 5 || str_province.length() != 2 || str_expData.length() != 8 || str_reagentNum.length() != 3)
	{
		QString str = str2qstr(string("�������!\n"));
		QColor clrR(255, 0, 0);//��ɫ
		stringToHtml(str, clrR);
		ui.textBrowser_message->insertHtml(str);
		return;
	}

	QString qstr_cal1 = ui.lineEdit_cal1->text();//�궨ֵ1
	QString qstr_cal2 = ui.lineEdit_cal2->text();//�궨ֵ2
	QString qstr_cal3 = ui.lineEdit_cal3->text();//�궨ֵ3
	QString qstr_cal4 = ui.lineEdit_cal4->text();//�궨ֵ4
	QString qstr_cal5 = ui.lineEdit_cal5->text();//�궨ֵ5
	QString qstr_cal6 = ui.lineEdit_cal6->text();//�궨ֵ6
	QString qstr_cal7 = ui.lineEdit_cal7->text();//�궨ֵ7
	QString qstr_cal8 = ui.lineEdit_cal8->text();//�궨ֵ8

	double cal[8];
	cal[0] = qstr_cal1.toDouble();
	cal[1] = qstr_cal2.toDouble();
	cal[2] = qstr_cal3.toDouble();
	cal[3] = qstr_cal4.toDouble();
	cal[4] = qstr_cal5.toDouble();
	cal[5] = qstr_cal6.toDouble();
	cal[6] = qstr_cal7.toDouble();
	cal[7] = qstr_cal8.toDouble();

	for (int i = 0; i < 8; i++)
	{
		if (cal[i] == 0 || cal[i] < 0 || cal[i]>3)
		{
			QString str = str2qstr(string("�궨ֵ����!\n"));
			QColor clrR(255, 0, 0);//��ɫ
			stringToHtml(str, clrR);
			ui.textBrowser_message->insertHtml(str);
			return;
		}
	}

	//��д���һ�μ��ܵ�����
	int len = 1;
	for (int i = 0; i < str_reagentApp.length(); i++, len++)
	{
		text1[len] = str_reagentApp.at(i);
	}
	for (int i = 0; i < str_reagentID.length(); i++, len++)
	{
		text1[len] = str_reagentID.at(i);
	}
	for (int i = 0; i < 8; i++, len++)
	{
		text1[len] = (int)(85 * cal[i] - 128);//y=85*x-128
	}
	//��д��ڶ��μ��ܵ�����
	len = 1;
	for (int i = 0; i < str_province.length(); i++, len++)
	{
		text2[len] = str_province.at(i);
	}
	for (int i = 0; i < str_expData.length(); i++, len++)
	{
		text2[len] = str_expData.at(i);
	}
	for (int i = 0; i < str_reagentNum.length(); i++, len++)
	{
		text2[len] = str_reagentNum.at(i);
	}
	//������text1��ֵ��sha������
	for (int i = 0; i < 16; i++)
	{
		shaIn[i] = text1[i];
	}
	//���ں������
	int lenSalt = strlen(salt);
	for (int i = 0; i < lenSalt; i++)
	{
		shaIn[16 + i] = salt[i];
	}

	//��ȡ�̶���Կ
	char fxKey[17] = "";
	string str_fxKey = qstr2str(ui.lineEdit_FxKey->text());
	int lenFxKey = str_fxKey.length();
	for (int i = 0; i < lenFxKey&&i < 16; i++)
	{
		fxKey[i] = str_fxKey.at(i);
	}
	//�̶���Կ�������
	char out1[33] = "";//�̶���Կ���ܵ�����
	aes.aesEncryptCode(text1, 16, fxKey, out1);

	//����ɢ��
	char out2[65] = "";//ɢ��ֵ
	SHA256 sha = SHA256();
	sha.shaCoding(shaIn, 16 + lenSalt, out2);
	ui.textEdit_sha->setText(str2qstr((string)out2));//ɢ��ֵ��ʾ

	//��̬��Կ����
	char dxKey[17] = "";//��̬��Կ
	for (int i = 0; i < 16; i++)//SHAɢ��ֵ��ǰ16λ��Ϊ��̬��Կ
	{
		dxKey[i] = out2[i];
	}
	ui.lineEdit_DxKey->setText(str2qstr((string)dxKey));//��̬��Կ��ʾ
	
	//��̬���ܹ���
	char out3[33] = "";//��̬����
	aes.aesEncryptCode(text2, 16, dxKey, out3);//��̬���ļ��ܡ�

	//��̬���ܵ����ĺͶ�̬���ܵ����Ľ��
	char out4[65] = "";//��������
	for (int i = 0; i < 32; i++)
	{
		out4[i] = out1[i];
	}
	for (int i = 32; i < 64; i++)
	{
		out4[i] = out3[i - 32];
	}
	ui.textEdit_ciphertext->setText(str2qstr((string)out4));//����������ʾ

	QString str = str2qstr(string("���ܳɹ�!\n"));
	QColor clrG(0, 255, 0);//��ɫ
	stringToHtml(str, clrG);
	ui.textBrowser_message->insertHtml(str);
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

void Encryption::stringToHtmlFilter(QString & str)
{
	//ע���⼸�д����˳�����ң��������ɶ���滻
	str.replace("&", "&amp;");
	str.replace(">", "&gt;");
	str.replace("<", "&lt;");
	str.replace("\"", "&quot;");
	str.replace("\'", "&#39;");
	str.replace(" ", "&nbsp;");
	str.replace("\n", "<br>");
	str.replace("\r", "<br>");
}

void Encryption::stringToHtml(QString & str, QColor crl)
{
	stringToHtmlFilter(str);
	QByteArray array;
	array.append(crl.red());
	array.append(crl.green());
	array.append(crl.blue());
	QString strC(array.toHex());
	str = QString("<span style=\" color:#%1;\">%2</span>").arg(strC).arg(str);
}

QStringList Encryption::getEnableCommPort()
{
	QStringList commPortList;
	foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
	{
		QSerialPort serial;
		serial.setPort(info);
		if (serial.open(QIODevice::ReadWrite))
		{
			commPortList.append(serial.portName());
			serial.close();
		}
	}
	return commPortList;
}

void Encryption::button_decrypt_clicked()
{
	//��ȡ�̶���Կ
	char fxKey[17] = "";
	string str_fxKey = qstr2str(ui.lineEdit_FxKey->text());
	int lenFxKey = str_fxKey.length();
	for (int i = 0; i < lenFxKey&&i < 16; i++)
	{
		fxKey[i] = str_fxKey.at(i);
	}
	//��ȡ����
	string strCip = qstr2str(ui.textEdit_ciphertext->toPlainText());
	if (strCip.length() < 64)
	{
		QString str = str2qstr(string("����ʧ��!\n"));
		QColor clrR(255, 0, 0);//��ɫ
		stringToHtml(str, clrR);
		ui.textBrowser_message->insertHtml(str);
		return;
	}
	char cip1[33] = "";//��һ��������
	char cip2[33] = "";//�ڶ���������
	for (int i = 0; i < 32; i++)
	{
		cip1[i] = strCip.at(i);
	}
	for (int i = 32; i < 64; i++)
	{
		cip2[i - 32] = strCip.at(i);
	}
	
	//���ܵ�һ��������
	char out1[17] = "";//��һ��������
	aes.aesDecryptCode(cip1, 32, fxKey, out1);
	if (out1[0] != -128)
	{
		QString str = str2qstr(string("����ʧ��!\n"));
		QColor clrR(255, 0, 0);//��ɫ
		stringToHtml(str, clrR);
		ui.textBrowser_message->insertHtml(str);
		return;
	}
	int len = 1;
	
	//�Լ�Ӧ��
	char reagentApp[3] = "";
	for (int i = 0; i < 2; i++, len++)
	{
		reagentApp[i] = out1[len];
	}
	string str_reagentApp = reagentApp;

	//�Լ�ID
	char reagentID[9] = "";
	for (int i = 0; i < 5; i++, len++)
	{
		reagentID[i] = out1[len];
	}
	string str_reagentID = reagentID;

	//�궨ֵ
	double cal[8];
	for (int i = 0; i < 8; i++, len++)
	{
		cal[i] = ((out1[len] + 128) / 85.0);//x=(y+128)/85
	}
	
	//sha����
	char shaIn[50];
	memset(shaIn, 48, sizeof(shaIn));//���帳ֵ����0
	for (int i = 0; i < 16; i++)
	{
		shaIn[i] = out1[i];
	}
	//���ں������
	int lenSalt = strlen(salt);
	for (int i = 0; i < lenSalt; i++)
	{
		shaIn[16 + i] = salt[i];
	}

	//����ɢ��
	char out2[65] = "";//ɢ��ֵ
	SHA256 sha = SHA256();
	sha.shaCoding(shaIn, 16 + lenSalt, out2);
	
	//��̬��Կ����
	char dxKey[17] = "";//��̬��Կ
	for (int i = 0; i < 16; i++)//SHAɢ��ֵ��ǰ16λ��Ϊ��̬��Կ
	{
		dxKey[i] = out2[i];
	}
	char out3[17] = "";//�ڶ���������
	aes.aesDecryptCode(cip2, 32, dxKey, out3);//��̬��Կ����
	if (out3[0] != -128)
	{
		QString str = str2qstr(string("����ʧ��!\n"));
		QColor clrR(255, 0, 0);//��ɫ
		stringToHtml(str, clrR);
		ui.textBrowser_message->insertHtml(str);
		return;
	}
	len = 1;
	//ʡ��
	char province[3] = "";
	for (int i = 0; i < 2; i++, len++)
	{
		province[i] = out3[len];
	}
	string str_province = province;

	//��Ч����
	char expData[9] = "";
	for (int i = 0; i < 8; i++, len++)
	{
		expData[i] = out3[len];
	}
	string str_expData = expData;

	//ʣ����Ŀ
	char reagentNum[4] = "";
	for (int i = 0; i < 3; i++, len++)
	{
		reagentNum[i] = out3[len];
	}
	string str_reagentNum = reagentNum;

	//��ʾ
	ui.lineEdit_province->setText(str2qstr(str_province));
	ui.lineEdit_expData->setText(str2qstr(str_expData));
	ui.lineEdit_reagentApp->setText(str2qstr(str_reagentApp));
	ui.lineEdit_reagentID->setText(str2qstr(str_reagentID));
	ui.lineEdit_reagentNum->setText(str2qstr(str_reagentNum));

	ui.lineEdit_cal1->setText(QString::number(cal[0], 'f', 1));
	ui.lineEdit_cal2->setText(QString::number(cal[1], 'f', 1));
	ui.lineEdit_cal3->setText(QString::number(cal[2], 'f', 1));
	ui.lineEdit_cal4->setText(QString::number(cal[3], 'f', 1));
	ui.lineEdit_cal5->setText(QString::number(cal[4], 'f', 1));
	ui.lineEdit_cal6->setText(QString::number(cal[5], 'f', 1));
	ui.lineEdit_cal7->setText(QString::number(cal[6], 'f', 1));
	ui.lineEdit_cal8->setText(QString::number(cal[7], 'f', 1));

	QString str = str2qstr(string("���ܳɹ�!\n"));
	QColor clrG(0, 255, 0);//��ɫ
	stringToHtml(str, clrG);
	ui.textBrowser_message->insertHtml(str);
}

void Encryption::textBrowser_message_textChanged()
{
	ui.textBrowser_message->moveCursor(QTextCursor::End);
}

wchar_t *Encryption::multiByteToWideChar(string str)
{
	const char* pCStrKey = str.c_str();
	//��һ�ε��÷���ת������ַ������ȣ�����ȷ��Ϊwchar_t*���ٶ����ڴ�ռ�
	int pSize = MultiByteToWideChar(CP_OEMCP, 0, pCStrKey, strlen(pCStrKey) + 1, NULL, 0);
	wchar_t *pWCStrKey = new wchar_t[pSize];
	//�ڶ��ε��ý����ֽ��ַ���ת����˫�ֽ��ַ���
	MultiByteToWideChar(CP_OEMCP, 0, pCStrKey, strlen(pCStrKey) + 1, pWCStrKey, pSize);
	return pWCStrKey;
}

void Encryption::button_readIC_clicked()
{
	string comTemp = qstr2str(ui.comboBox_port->currentText());
	if (comTemp.size() == 0)
	{
		QString str = str2qstr(string("���ڴ���!\n"));
		QColor clrG(255, 0, 0);
		stringToHtml(str, clrG);
		ui.textBrowser_message->insertHtml(str);
		return;
	}
	string strcom = comTemp.substr(3);
	int num = atoi(strcom.c_str());
	string com;
	if (num >= 10)
		com = "\\\\.\\" + comTemp;
	else
		com = comTemp;
	//const char* ccom = com.c_str();
	SerialCard card;
	bool flag = card.OpenSeialPort(multiByteToWideChar(com));
	if (!flag)
	{
		QString str = str2qstr(string("����ʧ��!\n"));
		QColor clrG(255, 0, 0);
		stringToHtml(str, clrG);
		ui.textBrowser_message->insertHtml(str);
		return;
	}
	string pwd = "";
	flag = card.read_card(pwd);
	if (flag)
	{
		QString str = str2qstr(string("����ʧ��!\n"));
		QColor clrG(255, 0, 0);
		stringToHtml(str, clrG);
		ui.textBrowser_message->insertHtml(str);
		return;
	}
	else
	{
		ui.textEdit_ciphertext->setText(str2qstr(pwd));

		QString str = str2qstr(string("��ȡ�ɹ�!\n"));
		QColor clrG(0, 255, 0);
		stringToHtml(str, clrG);
		ui.textBrowser_message->insertHtml(str);
		return;
	}
	return;
}

void Encryption::button_writeIC_clicked()
{
	string comTemp = qstr2str(ui.comboBox_port->currentText());
	if (comTemp.size() == 0)
	{
		QString str = str2qstr(string("���ڴ���!\n"));
		QColor clrG(255, 0, 0);
		stringToHtml(str, clrG);
		ui.textBrowser_message->insertHtml(str);
		return;
	}
	string strcom = comTemp.substr(3);
	int num = atoi(strcom.c_str());
	string com;
	if (num >= 10)
		com = "\\\\.\\" + comTemp;
	else
		com = comTemp;
	//const char* ccom = com.c_str();
	//string com = qstr2str(ui.comboBox_port->currentText());
	string pwd = qstr2str(ui.textEdit_ciphertext->toPlainText());
	if (pwd.length() != 64)
	{
		QString str = str2qstr(string("���Ĵ���!\n"));
		QColor clrG(255, 0, 0);
		stringToHtml(str, clrG);
		ui.textBrowser_message->insertHtml(str);
		return;
	}
	const char* ccom = com.c_str();
	SerialCard card;
	bool flag = card.OpenSeialPort(multiByteToWideChar(com));
	if (!flag)
	{
		QString str = str2qstr(string("����ʧ��!\n"));
		QColor clrG(255, 0, 0);
		stringToHtml(str, clrG);
		ui.textBrowser_message->insertHtml(str);
		return;
	}
	
	flag = card.write_card(pwd);
	if (flag)
	{
		QString str = str2qstr(string("д��ʧ��!\n"));
		QColor clrG(255, 0, 0);
		stringToHtml(str, clrG);
		ui.textBrowser_message->insertHtml(str);
		return;
	}
	else
	{
		QString str = str2qstr(string("д��ɹ�!\n"));
		QColor clrG(0, 255, 0);
		stringToHtml(str, clrG);
		ui.textBrowser_message->insertHtml(str);
		return;
	}
	card.ClosePort();
}



void Encryption::comboBox_port_clicked()
{
	QStringList list = getEnableCommPort();
	ui.comboBox_port->clear();
	for (int i = 0; i < list.size(); i++)
	{
		QString str = list.at(i);
		ui.comboBox_port->addItem(str);
	}
}

void Encryption::action_setting_triggered()
{
	QInputDialog pwd(this);
	pwd.setWindowTitle("Input Password");
	pwd.setLabelText("Please input Password:");
	pwd.setInputMode(QInputDialog::TextInput);//��ѡ������DoubleInput  TextInput

	if (pwd.exec() == QInputDialog::Accepted)
	{
		QString qpwd = pwd.textValue();
		if (qpwd.compare(QString("1234")) == 0)
		{
			Setting *setting = new Setting();
			setting->show();
		}
		else
		{
			QString str = str2qstr(string("�������!\n"));
			QColor clrG(255, 0, 0);//��ɫ
			stringToHtml(str, clrG);
			ui.textBrowser_message->insertHtml(str);
		}
	}
}

void Encryption::action_esc_triggered()
{
	
	if (QMessageBox::Ok == QMessageBox::warning(this, "Tips", "Are you sure to quit the app?", QMessageBox::Ok, QMessageBox::No))
	{
		//this->close();
		qApp->quit();
	}
	else
	{
		return;
	}
}

void Encryption::button_clearMessage_clicked()
{
	ui.textBrowser_message->clear();
}
