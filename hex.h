#ifndef HEX_H
#define HEX_H

#include <string>

int hexCharToInt(const char hexChar);
int hexStringToInt(const std::string hexString);
std::string intToHexString(const int hexInteger);

#endif