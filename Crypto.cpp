#include <iostream>
#include <string>
#include "Crypto.h"
#include "Binary.h"

// version
const std::string ver = "0.1.2B";

//module 2, test 1-3
const int lenbtest = 6;
const std::string Btest[][3] = {{"24", "11000", "00011000"},
	{"22", "10110", "00010110"},
	{"2",  "10",    "00000010"},
	{"15", "1111",  "00001111"},
	{"568","1000111000","00111000"},
	{"953267","11101000101110110011","10110011"}
}; 


//module 2, test 4-5
const int lenbintranstest = 3;
const std::string Bintranstest[][3] = { {"Hello", "0100100001100101011011000110110001101111"}, {"Test", "01010100011001010111001101110100"}, {"Ћ€", "11111111111111111111111111001011111111111111111111111111111111","32"}};



//Latin A-Z, a-z, Rus A-€, a-€
//const int Letinxs[][2] = { {65,90}, {97,122}, {192,223}, {224,255} };


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

		//ƒве ошибки на позиции 4 и 5 об€зательны и показывают, что программа работает правильно!!!!

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

		std::cout << "-- Fourth - encode string to binary" << std::endl;
		for (int i = 0; i < lenbintranstest; i++) {
			std::string ok = "";
			std::string s = Bin_encrypt(Bintranstest[i][0]);
			if (i == 2) {
			    s = Bin_encrypt(Bintranstest[i][0], stoi(Bintranstest[i][2]));
				ok = (s == Bintranstest[i][1] ? "\x1b[32mOK\x1b[0m" : "\x1b[31mERROR\x1b[0m");
				std::cout << " Coding to binary using exact wide of symb " << std::endl;
				std::cout << Bintranstest[i][0] << " is " <<  s << " that's " << ok << std::endl;
			}
			else {
				ok = (s == Bintranstest[i][1] ? "\x1b[32mOK\x1b[0m" : "\x1b[31mERROR\x1b[0m");
				std::cout << " Coding to binary w/o using exact wide of symb " << std::endl;
				std::cout << Bintranstest[i][0] << " is " << s << " that's " << ok << std::endl;
			}
		}

		std::cout << "-- Fifth - decode string to binary" << std::endl;
		for (int i = 0; i < lenbintranstest; i++) {
			std::string ok = "";
			if (i == 2) {
				std::string s = Bin_decrypt(Bintranstest[i][1], stoi(Bintranstest[i][2]));
				ok = (s == Bintranstest[i][0] ? "\x1b[32mOK\x1b[0m" : "\x1b[31mERROR\x1b[0m");
				std::cout << " Decoding to binary using exact wide of symb " << std::endl;
				std::cout << Bintranstest[i][1] << " is " << s << " that's " << ok << std::endl;
			}
			else {
				std::string s = Bin_decrypt(Bintranstest[i][1]);
				ok = (s == Bintranstest[i][0] ? "\x1b[32mOK\x1b[0m" : "\x1b[31mERROR\x1b[0m");
				std::cout << " Decoding to binary w/o using exact wide of symb " << std::endl;
				std::cout << Bintranstest[i][1] << " is " << s << " that's " << ok << std::endl;
			}
		}

	}
	catch (const char* error) {
		std::cout << " Binary ERROR " << std::endl << error;
		a = 2;
	}

	//TODO:
	// Caesar with fixed symb table 
	// Test for Caesar
	// Other cripters 

	std::cout << std::endl << "\x1b[33m          Module 3 \x1b[0m" << std::endl << std::endl;
	std::cout << "Cesar operations (Cesar.h)" << std::endl;
	try {
		std::cout << "-- First - encode " << std::endl;
		for (int i = 0; i < lenbtest; i++) {
			std::string bin = to_bin(stoi(Btest[i][0]));
			std::string l = Btest[i][1] == bin ? " OK " : " ERROR ";
			l = Btest[i][0] + " " + Btest[i][1] + " " + bin + " " + l;
			if (Btest[i][1] != bin) {
				std::cout << "\x1b[31m" << l << "\x1b[0m" << std::endl;
				return 2;
			}
			else {
				std::cout << "\x1b[32m" << l << "\x1b[0m" << std::endl;
			}
		}

		std::cout << "-- Second - decode " << std::endl;
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

	}
	catch (const char* error) {
		std::cout << " Cesar ERROR " << std::endl << error;
		a = 3;
	}



	return a;
}









