#include <iostream>
#include <string>
#include <cctype>
#include "encrypt_decrypt.h"


std::string encrypt(std::string text, int shift) {

    std::string result;

    for (char c : text) {
        /* The variable <shift> normalizes the variable input if it were negative and then corrects it
        for postive inputs also. In c++ for example, if you put in -3 modulo 26, you get -3 back which is incorrect.
        What the arithmetic does below is add 26 to the -3 which puts you at 23 and in the normal range, then modulo 26 again corrects
        it for postive inputs.*/
        shift = ((shift % 26) + 26) % 26;
        if (std::isupper(c)) {
            result += static_cast<char>('A' + (c - 'A' + shift) % 26);
        } else if (std::islower(c)) {
            result += static_cast<char>('A' + (c - 'a' + shift) % 26);
        } else {
            result += c;
        }
    }

    return result;
}


std::string decrypt(std::string text, int shift) {

    return encrypt(text, -shift); // This is where normalizing shift in the encrypt function comes in handy you can just reuse the function.
}
