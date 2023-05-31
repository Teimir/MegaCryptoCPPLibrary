#pragma once
//@return string binary number @param int decmical number
std::string to_bin(unsigned int number);
//@return string binary number @param int decmical number @param int length
std::string to_bin(unsigned int number, int wide);
//@return int decmical number @param string binary number 
int to_dec(std::string s);

//@return string encoded str @param string msg @param int wide of one letter in bits (standart is 8)
std::string Bin_encrypt(std::string s, int wide = 8);
//@return string decoded str @param string encoded msg @param int wide of one letter in bits (standart is 8)
std::string Bin_decrypt(std::string s, int wide = 8);

class Binary
{
};

