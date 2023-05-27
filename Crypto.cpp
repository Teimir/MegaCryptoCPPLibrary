#include <iostream>
#include "Crypto.h"


int test(bool silent)
{
	int a = 0;
	try {
		std::cout << "standart ASCII" << std::endl;
		int c = 0;
		for (int i = 32; i < 256; i++) {
			std::cout << i << " - " << (unsigned char)i << " ";
			if (c == 10) {
				std::cout << std::endl;
				c = 0;
			}
			c++;
		}
		std::cout << std::endl;
	
	}
	catch(const char* error){
		std::cout << error;
		a = 1;
	}
	return a;
}









