#include "SHA1.h"
#include <iostream>

#define WORD_SIZE 32

union SizeToChar
{
	size_t Num;
	char chars[8];
};

SHA1::SHA1()
{
	K = new unsigned int[80];
	for (size_t i = 0; i < 80; i++)
	{
		if (i < 20)
			K[i] = 0x5a827999;
		else if (i < 40)
			K[i] = 0x6ed9eba1;
		else if (i < 60)
			K[i] = 0x8f1bbcdc;
		else
			K[i] = 0xca62c1d6;
	}
}

SHA1::~SHA1()
{
	delete[] K;
}

void SHA1::Test(const char* msg, unsigned int len)
{
	char* data = PadMessage(msg, len);
	
	delete[] data;
}

char* SHA1::Digest(const char* msg, unsigned int len)
{
	char* digested = new char[20];
	unsigned int current_len = 0;
	while (current_len < len)
	{
		char message_part[55];
		for (size_t i = 0; i < 55; i++)
			if (current_len + i < len)
				message_part[i] = msg[current_len + i];
			else
				message_part[i] = 0;
		current_len += 55;

		char* padded = PadMessage(message_part, 55);


	}

	return digested;
}

unsigned int SHA1::Parity(unsigned int x, unsigned int y, unsigned int z)
{
	return x ^ y ^ z;
}

char* SHA1::PadMessage(const char* message, unsigned int lenght)
{
	if (lenght > 55)
		return nullptr;
	unsigned int l = lenght * 8;
	unsigned int k = (l + 1) & 511;
	k = k <= 448 ? 448 - k : 512 - (k - 448);

	//char block[64];
	char* block = new char[64];
	for (size_t i = 0; i < lenght; i++)
		block[i] = message[i];

	block[lenght] = 0x80;
	SizeToChar conv;
	conv.Num = k;
	unsigned int count = 0;
	for (size_t i = lenght + 1; i < 64; i++)
		if (i < 56)
			block[i] = 0;
		else
			block[i] = conv.chars[7 - count++];

	return block;
}
