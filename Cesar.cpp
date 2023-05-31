#include "Cesar.h"
#include <string>

//Latin A-Z, a-z, Rus A-ÿ, a-ÿ
const int Letinxs[4][2] = { {65,90}, {97,122}, {192,223}, {224,255} };

/* Legasy code
bool in_letters(int i) {
	for (int o = 0; o < 4; o++) {
		if (i >= Letinxs[o][0] && i <= Letinxs[o][1]) return true;
	}
	return false;
}
*/

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
        return 65 + ((a + s) % 26);
    case 1:
        return 97 + ((a + s) % 26);
    case 2:
        return 192 + ((a + s) % 32);
    case 3:
        return 224 + ((a + s) % 32);
    case -1:
        return a;
    }

}


std::string Caesar_encrypt(std::string text, int s)
{
    std::string result = "";

    for (int i = 0; i < text.length(); i++)
    {
        int a = int(text[i]);
        result += char(offset(a,s));
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
