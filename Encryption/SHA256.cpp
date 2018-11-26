#include "SHA256.h"

//64��32�����ֵĳ�����ǰ64��������������С��ǰ32λ��  
const UInt32 SHA256::K[64] = {
		0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
		0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
		0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
		0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
		0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
		0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
		0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
		0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2,
};
//���캯��
SHA256::SHA256()
{
	init();
}
//����512�������ݣ�������ϢժҪ  
Message_Digest SHA256::deal(UInt32 M[16])
{
	int i;
	UInt32 T1 = 0, T2 = 0;
	UInt32 W[64] = { 0 };
	UInt32 A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, G = 0, H = 0;
	for (i = 0; i < 16; i++) {
		W[i] = M[i];
	}
	for (i = 16; i < 64; i++) {
		W[i] = SSigma_1(W[i - 2]) + W[i - 7] + SSigma_0(W[i - 15]) + W[i - 16];
	}
	A = MD.H[0];
	B = MD.H[1];
	C = MD.H[2];
	D = MD.H[3];
	E = MD.H[4];
	F = MD.H[5];
	G = MD.H[6];
	H = MD.H[7];
	//cout << "��ʼ:";
	//cout << hex << A << " " << B << " " << C << " " << D << " " << E << " " << F << " " << G << " " << H << endl;
	for (i = 0; i < 64; i++) {
		T1 = H + LSigma_1(E) + Conditional(E, F, G) + K[i] + W[i];
		T2 = LSigma_0(A) + Majority(A, B, C);
		H = G;
		G = F;
		F = E;
		E = D + T1;
		D = C;
		C = B;
		B = A;
		A = T1 + T2;
		//cout << dec << i << ":";
		//cout << hex << A << " " << B << " " << C << " " << D << " " << E << " " << F << " " << G << " " << H << endl;
	}
	MD.H[0] = (MD.H[0] + A) & 0xFFFFFFFF;
	MD.H[1] = (MD.H[1] + B) & 0xFFFFFFFF;
	MD.H[2] = (MD.H[2] + C) & 0xFFFFFFFF;
	MD.H[3] = (MD.H[3] + D) & 0xFFFFFFFF;
	MD.H[4] = (MD.H[4] + E) & 0xFFFFFFFF;
	MD.H[5] = (MD.H[5] + F) & 0xFFFFFFFF;
	MD.H[6] = (MD.H[6] + G) & 0xFFFFFFFF;
	MD.H[7] = (MD.H[7] + H) & 0xFFFFFFFF;

	return MD;
}

Message_Digest SHA256::preDeal(UChar Y[Max])
{
	UInt32 i, j;
	UInt32 T1 = 0, T2 = 0, T3 = 0, T4 = 0;
	UChar temp[Max] = { 0 };
	UInt64 x = strlen((char *)Y);//���ݳ���  
	UInt32 d = abs((int)(55 - x)) % 64;   //��䳤��  
	UInt32 n = (x + 8) / 64 + 1; //������  
	UInt32 m = x % 64;       //��������ݳ���  
	UInt32 l = 8;
	Message_Digest tmpMd;
	//�����  
	for (i = 0; i < x; i++) {
		temp[i] = Y[i];
	}
	//���1��1000 0000  
	temp[x] = 0x80;
	//���d��0000 0000  
	for (i = x + 1; i < x + d + 1; i++) {
		temp[i] = 0x00;
	}
	//��䳤�ȵ�63-0λ  
	for (i = 1; i <= l; i++) {
		temp[(n * 64) - i] = (UChar)(8 * x >> (i - 1) * 8);
	}
	//�޷����ַ�ת��Ϊ�޷�������  
	for (i = 0; i < Max / 4; i++) {
		for (j = 0; j < 4; j++) {
			if (j == 0)
				T1 = temp[4 * i + j];
			if (j == 1)
				T2 = temp[4 * i + j];
			if (j == 2)
				T3 = temp[4 * i + j];
			if (j == 3)
				T4 = temp[4 * i + j];
		}
		W[i] = (T1 << 24) + (T2 << 16) + (T3 << 8) + T4;
	}
	//���鴦��  
	for (i = 0; i < n; i++) {
		for (j = 0; j < 16; j++) {
			M[j] = W[(i * 16) + j];
		}
		tmpMd = deal(M);
	}
	return tmpMd;
}

void SHA256::shaCoding(char * in, int inlen, char * out)
{
	UChar Y[Max] = "";
	for (int i = 0; i < inlen; i++)
	{
		Y[i] = (UChar)in[i];
	}
	Message_Digest md = preDeal(Y);
	char str[24];
	int len = 0;
	for (int i = 0; i < 8; i++)
	{
		sprintf_s(str, 24, "%08x", md.H[i]);
		for (int j = 0; j < 24; j++)
		{
			if (str[j] == 0)
			{
				break;
			}
			*(out + len) = str[j];
			len++;
		}
	}
}

void SHA256::init()
{
	MD.H[0] = 0x6a09e667;
	MD.H[1] = 0xbb67ae85;
	MD.H[2] = 0x3c6ef372;
	MD.H[3] = 0xa54ff53a;
	MD.H[4] = 0x510e527f;
	MD.H[5] = 0x9b05688c;
	MD.H[6] = 0x1f83d9ab;
	MD.H[7] = 0x5be0cd19;
}
//����ת
int SHA256::rotR(UInt32 W, int n)
{
	return ((W >> n) & 0xFFFFFFFF) | (W) << (32 - (n));
}
//����ת
UInt32 SHA256::rotL(UInt32 W, int n)
{
	return ((W << n) & 0xFFFFFFFF) | (W) >> (32 - (n));
}
//����λ
UInt32 SHA256::shR(UInt32 W, int n)
{
	return ((W >> n) & 0xFFFFFFFF);
}
