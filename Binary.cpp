#include <string>
#include <algorithm> 
#include <iostream>
#include <cmath> 
#include "Binary.h"

//Latin A-Z, a-z, Rus A-я, a-я
const int Letinxs[4][2] = { {65,90}, {97,122}, {192,223}, {224,255} };

int to_bit(int number) {
	if (number / 2 != 0) to_bit(number / 2);
	return number % 2;
}


/* LEGASY  */
/*
std::string to_bin(int number) {
	std::string s = "";
	for (int i = number; i > 0; ) {
		s = s + std::to_string(to_bit(i));
		i = i / 2;
	}
	reverse(s.begin(), s.end());
	return s;
}

std::string to_bin(int number, int length) {
	std::string s = "";
	for (int i = number; i > 0; ) {
		s = s + std::to_string(to_bit(i));
		std::cout << s << " HUIL " << std::endl;
		i = i / 2;
	}
	
	reverse(s.begin(), s.end());
	

	int len = s.length();
	len = length - len > 0 ? length - len : -1;

	if (len != -1) s.insert(0,len, '0');
	else s = s.substr(s.length() - length,s.length() - 1);
	return s;
}

*/

std::string to_bin(unsigned int n)
{
	std::string buffer; // символы ответа в обратном порядке
	// выделим память заранее по максимуму
	buffer.reserve(std::numeric_limits<unsigned int>::digits);
	do
	{
		buffer += char('0' + n % 2); // добавляем в конец
		n = n / 2;
	} while (n > 0);
	return std::string(buffer.crbegin(), buffer.crend()); // разворачиваем результат
}

std::string to_bin(unsigned int n, int wide) {
	std::string s = to_bin(n);
	int len = s.length();
	len = wide - len > 0 ? wide - len : -1;

	if (len != -1) s.insert(0, len, '0');
	else s = s.substr(s.length() - wide, s.length() - 1);
	return s;
}



int to_dec(std::string s) {
	int maxP = s.length()-1, num = 0;
	for (int i = 0; i < s.length(); i++) {
		num = num + ((int)s[i] - 48) * pow(2, maxP - i);
	}
	return num;
}

bool in_letters(int i) {
	for (int o = 0; o < 4; o++) {
		if (i >= Letinxs[o][0] && i <= Letinxs[o][1]) return true;
	}
	return false;
}

std::string Bin_encrypt(std::string s, int wide) {
	std::string a = "";
	for (int i = 0; i < s.length(); i++) {
		a = a + to_bin((unsigned int)s[i], wide);
	}
	return a;
}

std::string Bin_decrypt(std::string s, int wide) {
	std::string a = "";
	for (int i = 0; i < s.length();) {
		a = a + (char)to_dec(s.substr(i, wide));
		i += wide;
	}
	return a;
}
