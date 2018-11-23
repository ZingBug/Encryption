#ifndef AES_H
#define AES_H

#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>

class AES {
private:
	static const int S[16][16];//S盒
	static const int invS[16][16];//逆S盒
	static const int Rcon[10];//常量轮值表
	static const int colM[4][4];//列混合用到的矩阵
	static const int invColM[4][4];////逆列混合用到的矩阵
	static int w[44];//密钥对应的拓展数据
	int getLeft4Bit(int num);//获取整形数据的低8位中的左4个位
	int getRight4Bit(int num);//获取整形数据的低8位中的右4个位
	int getNumFromSBox(int index);//根据索引，从S盒中获得元素
	int invGetNumFrmoSBox(int index);//根据索引从逆S盒中获取值
	int getIntFromChar(char c);//把一个字符转变为整数
	void convertToIntArray(char *str, int pa[4][4]);//把16个字符转变为4*4的数组，该矩阵中字节的排列顺序为从上到下，从左到右依次排列。
	void printArray(int a[4][4]);//打印4*4的数组
	void printASCII(char *str, int len);//打印字符串的ASCII码，以十六进制显示
	int getWordFromStr(char *str);//把连续的4个字符合并成一个4字节的整形
	void splitIntToArray(int num, int array[4]);//把一个4字节的数的第一、二、三、四个字节取出，放入一个4元素的整形数组中
	void leftLoop4int(int array[4], int step);//将数组中的元素循环左移step位
	void rightLoop4int(int array[4], int step);//将数组中的元素循环右移step位
	int mergeArrayToInt(int array[4]);//把数组中的第一、二、三和四元素分别作为4字节整型的第一、二、三和四字节，合并为一个4字节整型
	int Mix(int num);//密钥拓展中的Mix函数
	void extendKey(char *key);//拓展密钥
	void subBytes(int array[4][4]);//字节代换
	void invSubBytes(int array[4][4]);//逆字节代换
	void shiftRows(int array[4][4]);//行移位
	void invShiftRows(int array[4][4]);//逆行移位
	void addRoundKey(int array[4][4], int round);//密钥轮加
	int GMul(int u, int v);//二元运算
	void mixColumns(int array[4][4]);//列混合
	void invMixColumns(int array[4][4]);//逆列混合
	void convertArrayToStr(int array[4][4], char *str);//将4*4数组转回字符串
	bool checkKeyLen(int len);//检查密钥长度
	void int2Hex(int x, char array[2]);//将十进制整数转换为补码输出
	int hex2Int(const char *c);//将十六进制字符串转换为有符号的十进制整数
public:
	void aesEncrypt(char *p, int plen, char *key);//AES加密
	void aesDecrypt(char *c, int clen, char *key);//AES解密
	void aesEncryptCode(char * p, int plen, char * key, char *out);//AES加密并生成十六进制编码
	void aesDecryptCode(char * in, int inclen, char * key, char *out);//ASE对十六进制编码进行解密
};
#endif
