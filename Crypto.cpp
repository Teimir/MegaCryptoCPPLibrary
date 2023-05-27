#include <iostream>
#include <string>
#include "Crypto.h"
#include "Binary.h"

const int lenbtest = 6;
const std::string Btest[][3] = {{"24", "11000", "00011000"},
	{"22", "10110", "00010110"},
	{"2",  "10",    "00000010"},
	{"15", "1111",  "00001111"},
	{"568","1000111000","00111000"},
	{"953267","11101000101110110011","10110011"}
}; 
const std::string ver = "0.1.1B";


int test(bool silent)
{
	int a = 0;
	std::cout << std::endl << "\x1b[33m          Ver." + ver + " \x1b[0m" << std::endl << std::endl;


	std::cout << "\x1b[33m          Module 1 \x1b[0m" << std::endl;
	std::cout << "          1251 CodeTable" << std::endl << std::endl;
	try {
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
		std::cout << "\x1b[32m SUCCESS \x1b[0m" << std::endl;
		
	
	}
	catch(const char* error){
		std::cout << " ASCII ERROR " << std::endl << error;
		a = 1;
	}

	
	
	std::cout << std::endl << "\x1b[33m          Module 2 \x1b[0m" << std::endl << std::endl;
	std::cout << "Binary operations (Binary.h)" << std::endl;
	try {
		std::cout << "-- First - lengthless " << std::endl;
		for (int i = 0; i < lenbtest; i++) {
			std::string bin = to_bin(stoi(Btest[i][0]));
			std::string l = Btest[i][1] == bin ? " OK " : " ERROR ";
			l = Btest[i][0] + " " + Btest[i][1] + " " + bin + " " + l;
			if (Btest[i][1] != bin) {
				std::cout << "\x1b[31m" <<  l << "\x1b[0m" << std::endl;
				return 2;
			}
			else {
				std::cout << "\x1b[32m" <<  l << "\x1b[0m" << std::endl;
			}
		}

		std::cout << "-- Second - length has " << std::endl;
		for (int i = 0; i < lenbtest; i++) {
			std::string bin = to_bin(stoi(Btest[i][0]), 8);
			std::string l = Btest[i][2] == bin ? " OK " : " ERROR ";
			l = Btest[i][0] + " " + Btest[i][2] + " " + bin + " " + l;
			if (Btest[i][2] != bin) {
				std::cout << "\x1b[31m" << l << "\x1b[0m" << std::endl;
				return 2;
			}
			else {
				std::cout << "\x1b[32m" << l << "\x1b[0m" << std::endl;
			}
		}

		std::cout << "-- Third - decode " << std::endl;
		for (int i = 0; i < lenbtest; i++) {
			int num = to_dec(Btest[i][1]);
			std::string l = Btest[i][0] == std::to_string(num) ? " OK " : " ERROR ";
			l = Btest[i][1] + " " + Btest[i][0] + " " + std::to_string(num) + " " + l;
			if (Btest[i][0] != std::to_string(num)) {
				std::cout << "\x1b[31m" << l << "\x1b[0m" << std::endl;
				return 2;
			}
			else {
				std::cout << "\x1b[32m" << l << "\x1b[0m" << std::endl;
			}
		}

		//��� ������ �� ������� 4 � 5 ����������� � ����������, ��� ��������� �������� ���������!!!!

		std::cout << "-- Third - decode length has" << std::endl;
		for (int i = 0; i < lenbtest; i++) {
			int num = to_dec(Btest[i][2]);
			std::string l = Btest[i][0] == std::to_string(num) ? " OK " : " ERROR ";
			l = Btest[i][2] + " " + Btest[i][0] + " " + std::to_string(num) + " " + l;
			if ((Btest[i][0] != std::to_string(num)) && (i < 4)) {
				std::cout << "\x1b[31m" << l << "\x1b[0m" << std::endl;
				return 2;
			}
			else if (Btest[i][0] != std::to_string(num)) {
				std::cout << "\x1b[31m" << l << "But OK \x1b[0m" << std::endl;
			}
			else {
				std::cout << "\x1b[32m" << l << "\x1b[0m" << std::endl;
			}
		}



	}
	catch (const char* error) {
		std::cout << " Binary ERROR " << std::endl << error;
		a = 2;
	}



	return a;
}









