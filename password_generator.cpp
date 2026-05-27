#include <iostream>
#include <string>
#include <random>
#include "password_generator.h"

std:: string generatePassword(int length) {

    if (length <= 0) {

        return "";
    }

    std::string pool = "abcdefghijklmnopqrstuvwxyz""ABCDEFGHIJKLMNOPQRSTUVWXYZ""0123456789""!@#$%^&*()-_=+{}[]";

    static std::random_device rd;
    static std::mt19937 generator(rd());
    std::uniform_int_distribution<int> dist(0, pool.size() - 1);

    std::string result;

    for (int i = 0; i < length; i++) {
        result += pool[dist(generator)];

    }

    return result;
}
