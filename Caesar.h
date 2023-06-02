#pragma once
#include <string>
//@return string encoded str @param string msg @param int offset 
std::string Caesar_encrypt(std::string text, int s);
//@return string decoded str @param string encoded msg @param int offset
std::string Caesar_decrypt(std::string text, int s);


class Caesar
{
public:
    std::string Caesar_encrypt(std::string text, int s)
    {
        std::string result = "";

        for (int i = 0; i < text.length(); i++)
        {
            int a = int(text[i]);
            result += char(offset(a, s));
        }
        return result;
    }

    std::string Caesar_decrypt(std::string text, int s)
    {
        std::string result = "";

        for (int i = 0; i < text.length(); i++)
        {
            int a = int(text[i]);
            result += char(offset(a, -1 * s));
        }
        return result;
    }

    std::string Caesar2_encrypt(std::string text, int s)
    {
        std::string result = "";

        for (int i = 0; i < text.length(); i++)
        {
            int a = int(text[i]);
            result += char(a + s);
        }
        return result;
    }

    std::string Caesar2_decrypt(std::string text, int s)
    {
        std::string result = "";

        for (int i = 0; i < text.length(); i++)
        {
            int a = int(text[i]);
            result += char(a - s);
        }
        return result;
    }
private:
    std::string  Letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäå¸æçèéêëìíîïðñòóôõö÷øùúûüýþÿ";
    //Latin A-Z, a-z, Rus A-ÿ, a-ÿ
    const int Letinxs[4][2] = { {0,25}, {26,51}, {52,84}, {85,117} };


    int where_in_letters(int i) {
        for (int o = 0; o < 4; o++) {
            if (i >= Letinxs[o][0] && i <= Letinxs[o][1]) return o;
        }
        return -1;
    }

    int offset(int a, int s) {
        int l = where_in_letters(a);

        switch (l)
        {
        case 0:
            return ((a + s) % 26);
        case 1:
            return 26 + ((a + s) % 26);
        case 2:
            return 52 + ((a + s) % 32);
        case 3:
            return 85 + ((a + s) % 32);
        case -1:
            return a;
        }

    }
};

