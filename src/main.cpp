#include<iostream>

#define WIN32_LEAN_AND_MEAN

#include <windows.h>

#include "project.h"

// TODO: Just a little test: https://en.cppreference.com/w/cpp/chrono/parse
void get_date()
{
    std::chrono::year_month_day date;
    //auto manipulator = std::chrono::parse("%d/%m/%Y", date);
    std::cin >> std::chrono::parse("%d/%m/%Y", date);
    // OR: std::chrono::from_stream(std::cin, "%d/%m/%Y", date);

    std::cout << date;

    //PROJECT project { 
    //    .startDate = DATE::year_month_day(std::chrono::year(2023), std::chrono::month(2), std::chrono::day(14))
    //};
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "Helló!\n";
}