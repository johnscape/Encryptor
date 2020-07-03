#pragma once
template <class WORD, int WORD_SIZE>
class SHA
{
public:
	SHA() {}
	~SHA() {}

	virtual char* Digest(const char* msg, unsigned int len) = 0;

protected:
	WORD ROTL(WORD x, unsigned int n)
	{
		return (x << n) | (x >> (WORD_SIZE - n));
	}

	WORD ROTR(WORD x, unsigned int n)
	{
		return (x >> n) | (x << (WORD_SIZE - n));
	}

	WORD SHR(WORD x, unsigned int n)
	{
		return x >> n;
	}

	WORD Ch(WORD x, WORD y, WORD z)
	{
		return (x & y) ^ (~x & z);
	}

	WORD Maj(WORD x, WORD y, WORD z)
	{
		return (x & y) ^ (x & z) ^ (y & z);
	}
};