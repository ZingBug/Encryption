#ifndef AES_H
#define AES_H

#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>

class AES {
private:
	static const int S[16][16];//S��
	static const int invS[16][16];//��S��
	static const int Rcon[10];//������ֵ��
	static const int colM[4][4];//�л���õ��ľ���
	static const int invColM[4][4];////���л���õ��ľ���
	static int w[44];//��Կ��Ӧ����չ����
	int getLeft4Bit(int num);//��ȡ�������ݵĵ�8λ�е���4��λ
	int getRight4Bit(int num);//��ȡ�������ݵĵ�8λ�е���4��λ
	int getNumFromSBox(int index);//������������S���л��Ԫ��
	int invGetNumFrmoSBox(int index);//������������S���л�ȡֵ
	int getIntFromChar(char c);//��һ���ַ�ת��Ϊ����
	void convertToIntArray(char *str, int pa[4][4]);//��16���ַ�ת��Ϊ4*4�����飬�þ������ֽڵ�����˳��Ϊ���ϵ��£��������������С�
	void printArray(int a[4][4]);//��ӡ4*4������
	void printASCII(char *str, int len);//��ӡ�ַ�����ASCII�룬��ʮ��������ʾ
	int getWordFromStr(char *str);//��������4���ַ��ϲ���һ��4�ֽڵ�����
	void splitIntToArray(int num, int array[4]);//��һ��4�ֽڵ����ĵ�һ�����������ĸ��ֽ�ȡ��������һ��4Ԫ�ص�����������
	void leftLoop4int(int array[4], int step);//�������е�Ԫ��ѭ������stepλ
	void rightLoop4int(int array[4], int step);//�������е�Ԫ��ѭ������stepλ
	int mergeArrayToInt(int array[4]);//�������еĵ�һ������������Ԫ�طֱ���Ϊ4�ֽ����͵ĵ�һ�������������ֽڣ��ϲ�Ϊһ��4�ֽ�����
	int Mix(int num);//��Կ��չ�е�Mix����
	void extendKey(char *key);//��չ��Կ
	void subBytes(int array[4][4]);//�ֽڴ���
	void invSubBytes(int array[4][4]);//���ֽڴ���
	void shiftRows(int array[4][4]);//����λ
	void invShiftRows(int array[4][4]);//������λ
	void addRoundKey(int array[4][4], int round);//��Կ�ּ�
	int GMul(int u, int v);//��Ԫ����
	void mixColumns(int array[4][4]);//�л��
	void invMixColumns(int array[4][4]);//���л��
	void convertArrayToStr(int array[4][4], char *str);//��4*4����ת���ַ���
	bool checkKeyLen(int len);//�����Կ����
	void int2Hex(int x, char array[2]);//��ʮ��������ת��Ϊ�������
	int hex2Int(const char *c);//��ʮ�������ַ���ת��Ϊ�з��ŵ�ʮ��������
public:
	void aesEncrypt(char *p, int plen, char *key);//AES����
	void aesDecrypt(char *c, int clen, char *key);//AES����
	void aesEncryptCode(char * p, int plen, char * key, char *out);//AES���ܲ�����ʮ�����Ʊ���
	void aesDecryptCode(char * in, int inclen, char * key, char *out);//ASE��ʮ�����Ʊ�����н���
};
#endif
