#include <iostream>
#include <string>
#include "Crypto.h"
#include "Binary.h"
#include "Cesar.h"
#include "Scyt.h"
#include "Affine.h"
#include "atbash.h"

// version
const std::string ver = "0.1.3B";

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
const std::string Bintranstest[][3] = { {"Hello", "0100100001100101011011000110110001101111"}, {"Test", "01010100011001010111001101110100"}, {"Ля", "11111111111111111111111111001011111111111111111111111111111111","32"}};



//Latin A-Z, a-z, Rus A-я, a-я
//const int Letinxs[][2] = { {65,90}, {97,122}, {192,223}, {224,255} };


//TODO:
	// Caesar with fixed symb table (need?) + 
	// Test for Caesar
	// Test for Scytala +
	// Affine crypt +
	// Atbash +
	// Hill
	// Xor
	// Des
	// 3DES
	// RSA
	// using through this file


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

		//Две ошибки на позиции 4 и 5 обязательны и показывают, что программа работает правильно!!!!

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

	

	std::cout << std::endl << "\x1b[33m          Module 3 \x1b[0m" << std::endl << std::endl;
	std::cout << "Cesar operations (Cesar.h) Auto test is INOP" << std::endl;
	/*try { INOP
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
	*/

	std::cout << std::endl << "\x1b[33m          Module 4 \x1b[0m" << std::endl << std::endl;
	std::cout << "Scyt operations (Scyt.h)" << std::endl;


	Scyt cipher(3, 5); // создание объекта шифратора с 3 столбцами и 5 символами в строке

	std::string message = "HELLO WORLD";
	std::string ciphertext = cipher.encrypt(message);
	std::cout << "Ciphertext: " << ciphertext << std::endl;

	std::string plaintext = cipher.decrypt(ciphertext);
	std::cout << "Plaintext: " << plaintext << std::endl;

	std::string message2 = "Привет Мир";
	std::string ciphertext2 = cipher.encrypt(message2);
	std::cout << "Ciphertext: " << ciphertext2 << std::endl;

	std::string plaintext2 = cipher.decrypt(ciphertext2);
	std::cout << "Plaintext: " << plaintext2 << std::endl;

	Scyt cipher2(2, 6); // создание объекта шифратора с 3 столбцами и 5 символами в строке

	std::string message21 = "HELLO WORLD";
	std::string ciphertext21 = cipher2.encrypt(message21);
	std::cout << "Ciphertext: " << ciphertext21 << std::endl;

	std::string plaintext21 = cipher2.decrypt(ciphertext21);
	std::cout << "Plaintext: " << plaintext21 << std::endl;

	std::string message22 = "Привет Мир";
	std::string ciphertext22 = cipher2.encrypt(message22);
	std::cout << "Ciphertext: " << ciphertext22 << std::endl;

	std::string plaintext22 = cipher2.decrypt(ciphertext22);
	std::cout << "Plaintext: " << plaintext22 << std::endl;


	std::cout << std::endl << "\x1b[33m          Module 5 \x1b[0m" << std::endl << std::endl;
	std::cout << "Affine operations (affine.h)" << std::endl;

	Affine acipher;

	// Устанавливаем новый ключ
	acipher.setKey(37, 13);

	// Шифруем сообщение
	string message3 = "hello world";
	string message4 = "Привет Мир";
	string cipherText3 = acipher.encrypt(message3);
	cout << "Cipher text: " << cipherText3 << endl;

	string decryptedMessage3 = acipher.decrypt(cipherText3);
	cout << "Original message: " << decryptedMessage3 << endl;

	string cipherText4 = acipher.encrypt(message4);
	cout << "Cipher text: " << cipherText4 << endl;

	string decryptedMessage4 = acipher.decrypt(cipherText4);
	cout << "Original message: " << decryptedMessage4 << endl;

	std::cout << std::endl << "\x1b[33m          Module 6 \x1b[0m" << std::endl << std::endl;
	std::cout << "Atbash operations (atbash.h)" << std::endl;

	atbash atbash;

	std::cout << "Cipher text: " << atbash.Atbash_encrypt(message3) << endl;
	std::cout << "Original message: " << atbash.Atbash_decrypt(atbash.Atbash_encrypt(message3)) << endl;
	std::cout << "Cipher text: " << atbash.Atbash_encrypt(message4) << endl;
	std::cout << "Original message: " << atbash.Atbash_decrypt(atbash.Atbash_encrypt(message4)) << endl;

	return a;
}









