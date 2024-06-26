﻿#include <iostream>
#include <bitset>
#include "Encode_Hamming.cpp"
#include "Decode_Hamming.cpp"
#include <gtest/gtest.h>

TEST(Test, Test1) 
{
	int q = 4;
	int Hamming = 5476;

	ASSERT_EQ(Hamming, Func_1(q));
}


TEST(Test, Test2) 
{
	int encoded = 5476;

	ASSERT_EQ(4, Func_2(encoded));
}

TEST(Test, Test3)
{
	int encoded = 5486;
	int err = -1;
	int q = Func_2(encoded);
	ASSERT_EQ(err, q);
}


int main()
{
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
	

    return 0;
}
