#ifndef __SERIAL_CARD_H__
#define __SERIAL_CARD_H__
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>


#define ERR_COMMUNICATION -1//���յ���ʼ���ݳ���
#define ERR_READ -2//���ݶ�ȡ����

typedef unsigned char UChar;

using namespace std;

class SerialCard
{
public:
	SerialCard();
	~SerialCard();
	//�򿪴��ڣ�Ĭ�ϲ�����57600������λ8λ��ֹͣλһλ������żУ��λ
	bool OpenSeialPort(const TCHAR* port, UINT baud_rate = CBR_57600, UINT databits = DATABITS_8, BYTE stop_bit = ONESTOPBIT, BYTE parity = NOPARITY);
	void ClosePort();
	bool WriteData(UChar* pData, unsigned int length);//д��������
	int ReadData(UChar* data);//����������//, DWORD length, UINT BytesInCom);
	bool send_cmd(UChar cmd, UChar len, UChar *data);//��������
	int check_card(UChar _Mode, unsigned long* snr);//Ѱ����ѡ��
	int load_key(UChar mode, UChar sector, UChar* bufkey);//��������A
	int auth_key(UChar mode, UChar sector);//��֤����
	int read_block(UChar address, UChar* databuf);//��һ���飬16�ֽ�
	int write_block(UChar address, UChar* databuf);//дһ���飬16�ֽ�
	int write_card(string str);//д����һ��д4���飬һ����ʮ���ֽ�
	int read_card(string &str);//������һ�ζ�4���飬һ����ʮ���ֽ�
	UINT GetBytesInCom();//��ȡ�������뻺�������ֽ���
	void beep(int msecond, int time);//������
private:
	HANDLE m_hCom;
	static UChar _TKey[16][8];
	static UChar key[2][8];
	static UChar data[4][16];
};

#endif
