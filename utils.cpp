//
// Created by qianlei on 2020/6/8.
//
#include "utils.h"

bool isUnsignedInt(const std::string &s) {
    for (char i : s) {
        if (i > '9' || i < '0') {
            return false;
        }
    }
    return true;
}

std::string readLine() {
    std::string s;
    std::getline(std::cin, s);
    return s;
}

bool isDouble(const std::string &s) {
    std::regex pattern(R"(^(\-)?\d+(\.\d{1,2})?$)");
    return std::regex_match(s, pattern);
}
