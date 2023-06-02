#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;




class Affine
{
    public:
        Affine() {
        srand(time(NULL));
        initCipher();
    }

    // Установить новый ключ
    void setKey(int a, int b) {
        mA = a;
        mB = b;
        mInverseA = findInverseModulo118(mA);
    }

    // Зашифровать сообщение
    string encrypt(const string & message) {
        string cipherText;
        for (const char& c : message) {
            int l = get_let_index(c);
            if (l == -1) cipherText.push_back(c);
            else cipherText.push_back(Letters[(mA * l + mB) % 118]);
        }
        return cipherText;
    }

    // Расшифровать сообщение
    string decrypt(const string & cipherText) {
        string message;
        for (const char& c : cipherText) {
            int l = get_let_index(c);
            if (l == -1) message.push_back(c);
            else message.push_back(Letters[((get_let_index(c) - mB) * findInverseModulo118(mA)) % 118]);
            
        }
        return message;
    }

    private:
        std::string Letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
        int mA; // коэффициент "a" в шифровальной функции
        int mB; // сдвиг "b" в шифровальной функции
        int mInverseA; // обратный элемент "a" по модулю 118

        int get_let_index(char letter) {
            for (int i = 0; i < 118; i++) {
                if (Letters[i] == letter) return i;
            }
            return -1;
        }

        void initCipher() {
            while (true) {
                // Генерируем случайное "a" и проверяем, что оно и 118 взаимно простые
                mA = rand() % 118;
                if (gcd(mA, 118) == 1) {
                    break;
                }
            }

            // Генерируем случайное "b"
            mB = rand() % 118;

            // Вычисляем обратный элемент по модулю 118
            mInverseA = findInverseModulo118(mA);
        }

        // Нахождение наибольшего общего делителя двух чисел
        int gcd(int a, int b) {
            if (a == 0) {
                return b;
            }
            return gcd(b % a, a);
        }

        // Нахождение обратного элемента по модулю 118
        int findInverseModulo118(int a) {
            for (int i = 1; i < 118; i++) {
                if ((a * i % 118) == 1) {
                    return i;
                }
            }
            return -1;
        }


};

