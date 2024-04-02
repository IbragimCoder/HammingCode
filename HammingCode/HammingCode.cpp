#include <iostream>
#include <bitset>

std::bitset<8> encode_Hamming(std::bitset<4> part)
{
    std::bitset<8> encoded;

    bool d1 = part[0];
    bool d2 = part[1];
    bool d3 = part[2];
    bool d4 = part[3];

    bool p1;
    bool p2;
    bool p3;
    bool p4;

    p1 = (d1 + d3 + d4 + 1) % 2;
    p2 = (d1 + d2 + d4 + 1) % 2;
    p3 = (d1 + d2 + d3 + 1) % 2;
    p4 = (1 + p1 + d1 + p2 + d2 + p3 + d3 + d4) % 2;

    encoded[0] = p1;
    encoded[1] = d1;

    encoded[2] = p2;
    encoded[3] = d2;

    encoded[4] = p3;
    encoded[5] = d3;

    encoded[6] = p4;
    encoded[7] = d4;


    return encoded;
}

std::bitset<16> Func(char sym)
{
    std::bitset<8> bits(sym);
    std::bitset<16> encoded;

    std::bitset<4> first(bits.to_string().substr(0, 4));
    std::bitset<4> second(bits.to_string().substr(4, 4));

    std::bitset<8> encodedFirstPart = encode_Hamming(first);
    std::bitset<8> encodedSecondPart = encode_Hamming(second);

    encoded |= (encodedFirstPart.to_ulong() << 8);

    encoded |= encodedSecondPart.to_ulong();

    return encoded;
}

int main()
{
    int n;
    std::cin >> n;

    std::bitset<8> tmp(n);
    std::bitset<16> temp = Func(n);

    std::cout << n << " = " << tmp;
    std::cout << " Encoded: " << temp;

    return 0;
}
