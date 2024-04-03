#include <iostream>
#include <bitset>
#include "Encode_Hamming.cpp"
#include "Decode_Hamming.cpp"

int main()
{
    int n;
    std::cin >> n;

    std::bitset<8> tmp(n);
    std::bitset<16> encoded_value = Func_1(n);

    int value = static_cast<int>(encoded_value.to_ulong());

	std::cout << n << " = " << tmp << "\n";
    std::cout << "Encoded: " << encoded_value << "  (" << value << ")" << "\n";

	int hamming = value;
	std::cout << "Decoded: " << Func_2(hamming) << "\n";
	

    return 0;
}
