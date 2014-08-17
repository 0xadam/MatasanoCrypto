#include <string>
#include <sstream>

using namespace std;

int hexCharToInt(const char hexChar)
{
	unsigned int integer;
	std::stringstream ss;
	ss << hex << hexChar;
	ss >> integer;
	return static_cast<int>(integer);
}

int hexStringToInt(const string hexString)
{
	unsigned int integer;
	std::stringstream ss;
	ss << hex << hexString;
	ss >> integer;
	return static_cast<int>(integer);
}

string hexToAscii(string hex)
{
	string ret;
	for(int i = 0; i < hex.length(); i+=2)
	{
		ret +=(char)hexStringToInt(hex.substr(i,2)); //starting at pos i, take two hex digits and convert to ASCII. i.e. 41 = A
	}
	return ret;
}

string intToHexString(const int hexInteger)
{
	string hexString;
	std::stringstream ss;
	ss << hex << hexInteger;
	ss >> hexString;
	return hexString;
}