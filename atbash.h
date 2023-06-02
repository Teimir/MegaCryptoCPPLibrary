#pragma once
#include <string>


class atbash
{
	
	
public:
	std::string Atbash_encrypt(std::string s) {
		std::string o = "";

		for (int i = 0; i < s.length(); i++)
		{
			int a = get_let_index(s[i]);
			o = o + (a != -1 ? Letters[118 - a + 1] : s[i]);
	
		}

		return o;
	}

	std::string Atbash_decrypt(std::string s) {
		std::string o = "";

		for (int i = 0; i < s.length(); i++)
		{
			int a = get_let_index(s[i]);
			o = o + (a != -1 ? Letters[118 - a + 1] : s[i]);
			
		}

		return o;
	}


private:
	std::string Letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäå¸æçèéêëìíîïðñòóôõö÷øùúûüýþÿ";
	int get_let_index(char letter) {
		for (int i = 0; i < 118; i++) {
			if (Letters[i] == letter) return i;
		}
		return -1;
	}
	
};

