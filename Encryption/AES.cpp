#include "AES.h"

//S盒
const int AES::S[16][16] = {
	0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
	0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
	0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
	0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
	0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
	0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
	0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
	0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
	0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
	0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
	0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
	0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
	0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
	0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
	0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
	0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};
//逆S盒
const int AES::invS[16][16] = {
	0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
	0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
	0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
	0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
	0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
	0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
	0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
	0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
	0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
	0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
	0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
	0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
	0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
	0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
	0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
	0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d
};
//常量轮值表
const int AES::Rcon[10] = {
	0x01000000, 0x02000000,
	0x04000000, 0x08000000,
	0x10000000, 0x20000000,
	0x40000000, 0x80000000,
	0x1b000000, 0x36000000
};
int AES::w[44] = {};
//获取整形数据的低8位中的左4个位
int AES::getLeft4Bit(int num)
{
	int left = num & 0x000000f0;
	return left >> 4;
}
//获取整形数据的低8位中的右4个位
int AES::getRight4Bit(int num)
{
	return num & 0x0000000f;

}
//根据索引，从S盒中获得元素
int AES::getNumFromSBox(int index)
{
	int row = getLeft4Bit(index);
	int col = getRight4Bit(index);
	return S[row][col];
}
//根据索引从逆S盒中获取值
int AES::invGetNumFrmoSBox(int index)
{
	int row = getLeft4Bit(index);
	int col = getRight4Bit(index);
	return invS[row][col];
}
//把一个字符转变为整数
int AES::getIntFromChar(char c)
{
	int result = (int)c;
	return result & 0x000000ff;
}
//把16个字符转变为4*4的数组，该矩阵中字节的排列顺序为从上到下，从左到右依次排列。
void AES::convertToIntArray(char *str, int pa[4][4])
{
	int k = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			pa[j][i] = getIntFromChar(str[k++]);//注意数组竖排顺序
		}
	}
}
//打印4*4的数组
void AES::printArray(int a[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf_s("a[%d][%d] = 0x%x ", i, j, a[i][j]);
		}
		printf_s("\n");
	}
	printf_s("\n");
}
//打印字符串的ASCII码，以十六进制显示
void AES::printASCII(char *str, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf_s("0x%02X ", getIntFromChar(str[i]));
	}
	printf_s("\n");
}
//把连续的4个字符合并成一个4字节的整形
int AES::getWordFromStr(char *str)
{

	int one = getIntFromChar(str[0]);
	one = one << 24;
	int two = getIntFromChar(str[1]);
	two = two << 16;
	int three = getIntFromChar(str[2]);
	three = three << 8;
	int four = getIntFromChar(str[3]);
	return one | two | three | four;

}
//把一个4字节的数的第一、二、三、四个字节取出，放入一个4元素的整形数组中
void AES::splitIntToArray(int num, int array[4])
{
	int one = num >> 24;
	array[0] = one & 0x000000ff;
	int two = num >> 16;
	array[1] = two & 0x000000ff;
	int three = num >> 8;
	array[2] = three & 0x000000ff;
	array[3] = num & 0x000000ff;
}
//将数组中的元素循环左移step位
void AES::leftLoop4int(int array[4], int step)
{
	int temp[4];
	for (int i = 0; i < 4; i++)
	{
		temp[i] = array[i];
	}
	int index = step % 4;
	for (int i = 0; i < 4; i++)
	{
		array[i] = temp[index++];
		index %= 4;
	}
}
//把数组中的元素循环右移step位
void AES::rightLoop4int(int array[4], int step)
{
	int temp[4];
	for (int i = 0; i < 4; i++)
	{
		temp[i] = array[i];
	}
	int index = step % 4;
	index = 3 - index;
	for (int i = 3; i >= 0; i--)
	{
		array[i] = temp[index];
		index--;
		index = index == -1 ? 3 : index;
	}
}
//把数组中的第一、二、三和四元素分别作为4字节整型的第一、二、三和四字节，合并为一个4字节整型
int AES::mergeArrayToInt(int array[4])
{
	int one = array[0] << 24;
	int two = array[1] << 16;
	int three = array[2] << 8;
	int four = array[3];
	return one | two | three | four;
}
//密钥拓展中的Mix函数
int AES::Mix(int num)
{
	int numArray[4];
	splitIntToArray(num, numArray);
	leftLoop4int(numArray, 1);//向左循环1位
	//字节代换
	for (int i = 0; i < 4; i++)
	{
		numArray[i] = getNumFromSBox(numArray[i]);
	}
	return mergeArrayToInt(numArray);
}
//拓展密钥
void AES::extendKey(char *key)
{

	for (int i = 0; i < 4; i++)
	{
		AES::w[i] = getWordFromStr(key + i * 4);
	}

	for (int i = 4, j = 0; i < 44; i++)
	{
		if (i % 4 == 0)
		{
			w[i] = w[i - 4] ^ (Mix(w[i - 1]) ^ Rcon[j]);
			j++;//下一轮
		}
		else
		{
			w[i] = w[i - 4] ^ w[i - 1];
		}
	}


}
//字节代换
void AES::subBytes(int array[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			array[i][j] = getNumFromSBox(array[i][j]);
		}
	}
}
//逆字节代换
void AES::invSubBytes(int array[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			array[i][j] = invGetNumFrmoSBox(array[i][j]);
		}
	}
}
//行移位
void AES::shiftRows(int array[4][4])
{
	int rowTwo[4], rowThree[4], rowFour[4];
	//复制状态矩阵的第2，3，4行
	for (int i = 0; i < 4; i++)
	{
		rowTwo[i] = array[1][i];
		rowThree[i] = array[2][i];
		rowFour[i] = array[3][i];
	}
	//循环左移相应的位数
	leftLoop4int(rowTwo, 1);
	leftLoop4int(rowThree, 2);
	leftLoop4int(rowFour, 3);
	//把左移后的行复制回到状态矩阵中
	for (int i = 0; i < 4; i++)
	{
		array[1][i] = rowTwo[i];
		array[2][i] = rowThree[i];
		array[3][i] = rowFour[i];
	}
}
//逆行移位
void AES::invShiftRows(int array[4][4])
{
	int rowTwo[4], rowThree[4], rowFour[4];
	//复制状态矩阵的第2，3，4行
	for (int i = 0; i < 4; i++)
	{
		rowTwo[i] = array[1][i];
		rowThree[i] = array[2][i];
		rowFour[i] = array[3][i];
	}
	//循环右移相应的位数
	rightLoop4int(rowTwo, 1);
	rightLoop4int(rowThree, 2);
	rightLoop4int(rowFour, 3);
	//把右移后的行复制回到状态矩阵中
	for (int i = 0; i < 4; i++)
	{
		array[1][i] = rowTwo[i];
		array[2][i] = rowThree[i];
		array[3][i] = rowFour[i];
	}
}
//密钥轮加
void AES::addRoundKey(int array[4][4], int round)
{
	//round是用到的轮密钥顺序
	int warray[4];
	for (int i = 0; i < 4; i++)
	{
		splitIntToArray(w[round * 4 + i], warray);
		for (int j = 0; j < 4; j++)
		{
			array[j][i] ^= warray[j];
		}
	}
}
//列混合用到的矩阵
const int AES::colM[4][4] = {
	0x02, 0x03, 0x01, 0x01,
	0x01, 0x02, 0x03, 0x01,
	0x01, 0x01, 0x02, 0x03,
	0x03, 0x01, 0x01, 0x02 };
//逆列混合用到的矩阵
const int AES::invColM[4][4] = {
	0xe, 0xb, 0xd, 0x9,
	0x9, 0xe, 0xb, 0xd,
	0xd, 0x9, 0xe, 0xb,
	0xb, 0xd, 0x9, 0xe
};
//二元运算
int AES::GMul(int u, int v)
{
	int p = 0;

	for (int i = 0; i < 8; ++i) {
		if (u & 0x01) {    //
			p ^= v;
		}

		int flag = (v & 0x80);
		v <<= 1;
		if (flag) {
			v ^= 0x1B; /* x^8 + x^4 + x^3 + x + 1 */
		}
		u >>= 1;
	}

	return p;
}
//列混合
void AES::mixColumns(int array[4][4])
{
	int tempArray[4][4];

	/* copy state[4][4] to tmp[4][4] */
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			tempArray[i][j] = array[i][j];
		}
	}

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {  //伽罗华域加法和乘法
			array[i][j] = GMul(colM[i][0], tempArray[0][j]) ^ GMul(colM[i][1], tempArray[1][j])
				^ GMul(colM[i][2], tempArray[2][j]) ^ GMul(colM[i][3], tempArray[3][j]);
		}
	}
}
//逆列混合
void AES::invMixColumns(int array[4][4])
{
	int tempArray[4][4];

	/* copy state[4][4] to tmp[4][4] */
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			tempArray[i][j] = array[i][j];
		}
	}

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {  //伽罗华域加法和乘法
			array[i][j] = GMul(invColM[i][0], tempArray[0][j]) ^ GMul(invColM[i][1], tempArray[1][j])
				^ GMul(invColM[i][2], tempArray[2][j]) ^ GMul(invColM[i][3], tempArray[3][j]);
		}
	}
}
//将4*4数组转回字符串
void AES::convertArrayToStr(int array[4][4], char *str)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			*str++ = (char)array[j][i];//注意数组是竖排顺序
		}
	}
}
//检查密钥长度
bool AES::checkKeyLen(int len)
{
	return len == 16;
}
void AES::int2Hex(int x, char array[2])//将十进制整数转换为补码输出
{
	char b[16] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
	if (x < 0)
	{
		x = 256 + x;
		for (int i = 0; i < 2; i++)
		{
			array[i] = 'f';
		}
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			array[i] = '0';
		}
	}
	int n = 0;
	int i = 1;
	while (x > 0.5)
	{
		n = x % 16;
		x = (x - n) / 16;
		array[i] = b[n];
		i = i - 1;
	}
}
int AES::hex2Int(const char *c)//将十六进制字符串转换为有符号的十进制整数
{
	int a;
	sscanf_s(c, "%x", &a);
	return a > 127 ? a - 256 : a;
}
//AES加密
void AES::aesEncrypt(char *p, int plen, char *key)
{
	//p：明文的字符串数组
	//plen：明文的长度
	//key：密钥的字符串数组
	int keylen = strlen(key);
	if (plen == 0 || plen % 16 != 0)
	{
		printf_s("明文字符长度必须为16的倍数！\n");
		system("pause");
		exit(0);
	}
	if (keylen > 16)
	{
		printf_s("密钥字符长度错误！长度必须小于16。当前长度为%d\n", keylen);
		system("pause");
		exit(0);
	}
	else if (keylen < 16)
	{
		//如果key长度小于16，补充key长度，补充的是最后一个字符
		char key1[17] = "";
		for (int i = 0; i < keylen; i++)
		{
			key1[i] = key[i];
		}
		for (int i = keylen; i < 16; i++)
		{
			key1[i] = key[keylen - 1];
		}
		extendKey(key1);//扩展密钥
	}
	else
	{
		extendKey(key);//扩展密钥
	}

	int pArray[4][4];
	for (int k = 0; k < plen; k += 16)
	{
		convertToIntArray(p + k, pArray);
		addRoundKey(pArray, 0);//一开始的密钥轮加
		for (int i = 1; i < 10; i++)
		{
			subBytes(pArray);//字节代换
			shiftRows(pArray);//行移位
			mixColumns(pArray);//列混合
			addRoundKey(pArray, i);//密钥轮加
		}
		//第10轮，没有列混合
		subBytes(pArray);//字节代换
		shiftRows(pArray);//行移位
		addRoundKey(pArray, 10);//密钥轮加
		convertArrayToStr(pArray, p + k);
	}
}
//AES解密
void AES::aesDecrypt(char *c, int clen, char *key)
{
	int cArray[4][4];
	int keylen = strlen(key);
	if (clen == 0 || clen % 16 != 0)
	{
		printf_s("密文字符长度必须为16的倍数！现在的长度为%d\n", clen);
		system("pause");
		exit(0);
	}
	if (keylen > 16)
	{
		printf_s("密钥字符长度错误！长度必须小于16。当前长度为%d\n", keylen);
		system("pause");
		exit(0);
	}
	else if (keylen < 16)
	{
		//如果key长度小于16，补充key长度，补充的是最后一个字符
		char key1[17] = "";
		for (int i = 0; i < keylen; i++)
		{
			key1[i] = key[i];
		}
		for (int i = keylen; i < 16; i++)
		{
			key1[i] = key[keylen - 1];
		}
		extendKey(key1);//扩展密钥
	}
	else
	{
		extendKey(key);//扩展密钥
	}
	//extendKey(key);//扩展密钥
	for (int k = 0; k < clen; k += 16)
	{
		int wArray[4][4];
		convertToIntArray(c + k, cArray);
		addRoundKey(cArray, 10);
		for (int i = 9; i >= 1; i--)
		{
			invShiftRows(cArray);//逆行移位
			invSubBytes(cArray);//逆字节代换
			addRoundKey(cArray, i);//密钥轮加
			invMixColumns(cArray);//逆列混合
		}
		//第10轮，没有逆列混合
		invSubBytes(cArray);//逆字节代换
		invShiftRows(cArray);//逆行移位
		addRoundKey(cArray, 0);//密钥轮加
		convertArrayToStr(cArray, c + k);
	}
}
//AES加密并生成十六进制编码
void AES::aesEncryptCode(char *p, int plen, char *key, char *out)
{
	int outlen = 32;
	if (outlen != plen * 2)
	{
		printf_s("编码字符长度必须为加密字符的两倍！现在的长度为%d\n", outlen);
		system("pause");
		exit(0);
	}
	aesEncrypt(p, plen, key);
	for (int i = 0; i < plen; i++)
	{
		int2Hex(p[i], out + 2 * i);
	}
}
//ASE对十六进制编码进行解密
void AES::aesDecryptCode(char *in, int inlen, char *key, char *out)
{
	if (inlen != 32)
	{
		printf_s("编码字符长度必须为32位！现在的长度为%d\n", inlen);
		system("pause");
		exit(0);
	}
	char c[17] = "";
	char temp[2];
	for (int i = 0; i < inlen / 2; i++)
	{
		temp[0] = in[2 * i];
		temp[1] = in[2 * i + 1];
		c[i] = hex2Int(temp);
	}
	aesDecrypt(c, 16, key);
	memcpy(out, c, 16);
}