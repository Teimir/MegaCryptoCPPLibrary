#include <string>
#include <algorithm> 
#include <iostream>
#include <cmath> 
#include "Binary.h"

int to_bit(int number) {
	if (number / 2 != 0) to_bit(number / 2);
	return number % 2;
}

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
		i = i / 2;
	}
	reverse(s.begin(), s.end());
	
	int len = s.length();
	len = 8 - len > 0 ? 8 - len : -1;

	if (len != -1) s.insert(0,len, '0');
	else s = s.substr(s.length() - 8,s.length() - 1);

	return s;
}

int to_dec(std::string s) {
	int maxP = s.length()-1, num = 0;
	for (int i = 0; i < s.length(); i++) {
		num = num + ((int)s[i] - 48) * pow(2, maxP - i);
	}
	return num;
}