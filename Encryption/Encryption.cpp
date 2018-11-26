#include "Encryption.h"

Encryption::Encryption(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
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

	ui.lineEdit_cal1->setText(QString::number(cal[0], 'f', 2));
	ui.lineEdit_cal2->setText(QString::number(cal[1], 'f', 2));
	ui.lineEdit_cal3->setText(QString::number(cal[2], 'f', 2));
	ui.lineEdit_cal4->setText(QString::number(cal[3], 'f', 2));
	ui.lineEdit_cal5->setText(QString::number(cal[4], 'f', 2));
	ui.lineEdit_cal6->setText(QString::number(cal[5], 'f', 2));
	ui.lineEdit_cal7->setText(QString::number(cal[6], 'f', 2));
	ui.lineEdit_cal8->setText(QString::number(cal[7], 'f', 2));

}
