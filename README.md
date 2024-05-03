Hamming Code Encoder/Decoder

This code is an implementation of Hamming encoding and decoding. It consists of two main functions: Func_1 and Func_2, as well as auxiliary functions encode_Hamming and decode_Hamming.

encode_Hamming
This function takes a 4-bit number and encodes it into an 8-bit number using a Hamming code. It calculates four control bits (p1, p2, p3, p4) based on the input data (d1, d2, d3, d4), and then returns an 8-bit number consisting of these control and data bits.

decode_Hamming
This function takes an 8-bit number, decodes it using a Hamming code, and returns a 4-bit number. If an error is found that cannot be fixed, it outputs an error message and returns -1
