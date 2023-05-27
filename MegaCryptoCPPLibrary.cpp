// MegaCryptoCPPLibrary.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Crypto.h"
#include "Binary.h"



int main()
{
    try {
        system("chcp 1251");
    }
    catch (const char* error) {
        std::cout << error;
        return 1;
    }
    std::cout << "Hello World!\n";
    std::cout << "Test crypto exit code: " << test();
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
