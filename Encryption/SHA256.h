#ifndef _SHA_256_H  
#define _SHA_256_H  
#include<iostream>  

using namespace std;

typedef unsigned int UInt32;
typedef unsigned __int64 UInt64;
typedef unsigned char UChar;

//六个逻辑函数  
#define Conditional(x,y,z) ((x&y)^((~x)&z))  
#define Majority(x,y,z) ((x&y)^(x&z)^(y&z))  
#define LSigma_0(x) (rotL(x,30)^rotL(x,19)^rotL(x,10))  
#define LSigma_1(x) (rotL(x,26)^rotL(x,21)^rotL(x,7))  
#define SSigma_0(x) (rotL(x,25)^rotL(x,14)^shR(x,3))  
#define SSigma_1(x) (rotL(x,15)^rotL(x,13)^shR(x,10)) 

#define Max 1000//最大字符数  

//信息摘要结构  
struct Message_Digest {
	UInt32 H[8];
};
//SHA256类
class SHA256
{
public:
	SHA256();
	void shaCoding(char *in, int inlen, char *out);
private:
	Message_Digest deal(UInt32 M[16]);//处理512比特数据，返回信息摘要  
	Message_Digest preDeal(UChar Y[Max]);
	static const UInt32 K[64];//64个32比特字的常数（前64个素数的立方根小数前32位） 
	void init();                //初始杂凑值  
	int rotR(UInt32 W, int n);//右旋转  
	UInt32 rotL(UInt32 W, int n);//左旋转  
	UInt32 shR(UInt32 W, int n); //右移位  
private:
	//信息摘要  
	Message_Digest MD;
	UInt32 W[Max / 4];//整型  
	UInt32 M[16];   //存分组信息  
};

#endif  

