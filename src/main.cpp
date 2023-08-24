#include<iostream>

#define WIN32_LEAN_AND_MEAN

#include<windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "Helló!";
}