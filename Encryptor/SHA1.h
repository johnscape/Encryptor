#pragma once
#include "SHA.h"

class SHA1 : public SHA<unsigned int, 32>
{
public:
	SHA1();
	~SHA1();

	void Test(const char* msg, unsigned int len);

	virtual char* Digest(const char* msg, unsigned int len);

private:
	/*WORD ROTL(WORD x, unsigned int n);
	WORD RORT(WORD x, unsigned int n);
	WORD SHR(WORD x, unsigned int n);*/

	//WORD Ch(WORD x, WORD y, WORD z);
	unsigned int Parity(unsigned int x, unsigned int y, unsigned int z);
	//WORD Maj(WORD x, WORD y, WORD z);

	unsigned int* K;

	char* PadMessage(const char* message, unsigned int lenght);
};

