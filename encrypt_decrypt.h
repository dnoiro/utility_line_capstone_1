#ifndef ENCRYPT_DECRYPT_H
#define ENCRYPT_DECRYPT_H

#include <string>

std::string encrypt (std::string text, int shift);
std::string decrypt (std::string text, int shift);

#endif
