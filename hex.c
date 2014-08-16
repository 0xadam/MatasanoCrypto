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

string intToHexString(const int hexInteger)
{
	string hexString;
	std::stringstream ss;
	ss << hex << hexInteger;
	ss >> hexString;
	return hexString;
}