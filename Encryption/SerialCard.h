#ifndef __SERIAL_CARD_H__
#define __SERIAL_CARD_H__
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>


#define ERR_COMMUNICATION -1//接收的起始数据出错
#define ERR_READ -2//数据读取出错

typedef unsigned char UChar;

using namespace std;

class SerialCard
{
public:
	SerialCard();
	~SerialCard();
	//打开串口，默认波特率57600，数据位8位，停止位一位，无奇偶校验位
	bool OpenSeialPort(const TCHAR* port, UINT baud_rate = CBR_57600, UINT databits = DATABITS_8, BYTE stop_bit = ONESTOPBIT, BYTE parity = NOPARITY);
	void ClosePort();
	bool WriteData(UChar* pData, unsigned int length);//写串口数据
	int ReadData(UChar* data);//读串口数据//, DWORD length, UINT BytesInCom);
	bool send_cmd(UChar cmd, UChar len, UChar *data);//发送命令
	int check_card(UChar _Mode, unsigned long* snr);//寻卡并选卡
	int load_key(UChar mode, UChar sector, UChar* bufkey);//下载密码A
	int auth_key(UChar mode, UChar sector);//验证密码
	int read_block(UChar address, UChar* databuf);//读一个块，16字节
	int write_block(UChar address, UChar* databuf);//写一个块，16字节
	int write_card(string str);//写卡，一次写4个块，一共六十四字节
	int read_card(string &str);//读卡，一次读4个块，一共六十四字节
	UINT GetBytesInCom();//获取串口输入缓冲区的字节数
	void beep(int msecond, int time);//蜂鸣器
private:
	HANDLE m_hCom;
	static UChar _TKey[16][8];
	static UChar key[2][8];
	static UChar data[4][16];
};

#endif
