#include <bitset>
#include <iostream>

int decode_Hamming(int c)
{
	int temp = c;

	bool p1 = temp & 0x1;
	bool d1 = temp & 0x2;

	bool p2 = temp & 0x4;
	bool d2 = temp & 0x8;

	bool p3 = temp & 0x10;
	bool d3 = temp & 0x20;

	bool p4 = temp & 0x40;
	bool d4 = temp & 0x80;

	bool A = (p1 + d1 + d3 + d4) % 2;
	bool B = (d1 + p2 + d2 + d4) % 2;
	bool C = (d1 + d2 + p3 + d3) % 2;
	bool D = (p1 + d1 + p2 + d2 + p3 + d3 + p4 + d4) % 2;

	if ((A == 0 || B == 0 || C == 0) && D == 1)
	{
		std::cout << "a bug that cannot be fixed " << std::endl;
		return -1;
	}

	if ((A == 0 || B == 0 || C == 0) && D == 0)
	{
		if (A == 0 && B == 0 && C == 0)
		{
			d1 ^= 1;
		}

		if (A == 1 && B == 0 && C == 0)
		{
			d2 ^= 1;
		}

		if (A = 0 && B == 1 && C == 0)
		{
			d3 ^= 1;
		}

		if (A == 0 && B == 0 && C == 1)
		{
			d4 ^= 1;
		}

	}

	int Hamming = d1 + (d2 << 1) + (d3 << 2) + (d4 << 3);

	return Hamming;
}

int Func_2(short c)
{
	int g = c >> 8;
	int t = c;
	int H = (decode_Hamming(g) << 4) + decode_Hamming(t);

	return H;
}