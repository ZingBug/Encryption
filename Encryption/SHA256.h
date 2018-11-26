#ifndef _SHA_256_H  
#define _SHA_256_H  
#include<iostream>  

using namespace std;

typedef unsigned int UInt32;
typedef unsigned __int64 UInt64;
typedef unsigned char UChar;

//�����߼�����  
#define Conditional(x,y,z) ((x&y)^((~x)&z))  
#define Majority(x,y,z) ((x&y)^(x&z)^(y&z))  
#define LSigma_0(x) (rotL(x,30)^rotL(x,19)^rotL(x,10))  
#define LSigma_1(x) (rotL(x,26)^rotL(x,21)^rotL(x,7))  
#define SSigma_0(x) (rotL(x,25)^rotL(x,14)^shR(x,3))  
#define SSigma_1(x) (rotL(x,15)^rotL(x,13)^shR(x,10)) 

#define Max 1000//����ַ���  

//��ϢժҪ�ṹ  
struct Message_Digest {
	UInt32 H[8];
};
//SHA256��
class SHA256
{
public:
	SHA256();
	void shaCoding(char *in, int inlen, char *out);
private:
	Message_Digest deal(UInt32 M[16]);//����512�������ݣ�������ϢժҪ  
	Message_Digest preDeal(UChar Y[Max]);
	static const UInt32 K[64];//64��32�����ֵĳ�����ǰ64��������������С��ǰ32λ�� 
	void init();                //��ʼ�Ӵ�ֵ  
	int rotR(UInt32 W, int n);//����ת  
	UInt32 rotL(UInt32 W, int n);//����ת  
	UInt32 shR(UInt32 W, int n); //����λ  
private:
	//��ϢժҪ  
	Message_Digest MD;
	UInt32 W[Max / 4];//����  
	UInt32 M[16];   //�������Ϣ  
};

#endif  

