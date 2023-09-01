#pragma once

#include <algorithm>
#include <cctype>
#include <locale>
#include <windows.h>

void move_cursor(int x, int y);

// https://stackoverflow.com/a/217605/21037183
inline void trim_start(std::string &input) {
    input.erase(input.begin(), std::find_if(input.begin(), input.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

inline void trim_end(std::string &input) {
    input.erase(std::find_if(input.rbegin(), input.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), input.end());
}

inline void trim(std::string &input) {
    trim_end(input);
    trim_start(input);
}
