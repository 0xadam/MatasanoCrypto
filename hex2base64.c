#include <string>
#include <iostream>
#include <sstream>
#include <cctype>

using namespace std;

static char encoding_table[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
'w', 'x', 'y', 'z', '0', '1', '2', '3',
'4', '5', '6', '7', '8', '9', '+', '/' };

int hex2int(string hex)
{
	unsigned int integer;
	std::stringstream ss;
	ss << std::hex << hex;
	ss >> integer;
	return static_cast<int>(integer);
}

string hex2base64(string hex)
{
	int hexLength = hex.length();
	for (int i = 0; i < hexLength; i++)
	{
		if (!isxdigit(hex[i]))
		{
			return "Invalid character in hex string";
		}
	}
	/* Hex strings must be even in length */
	if (hexLength % 2 != 0)
	{
		return "Hex length must be even!";
	}
	string base64;
	for (int i = 0; i < hexLength; i += 6)
	{
		//convert the first 6 characters (24 bits) to hex
		string hexChars = hex.substr(i, 6);
		long binary = hex2int(hexChars);
		int padding = 24 - hexChars.length() * 4;
		//binary = binary << 12 + (6 - ((numberOfBits) % 6)); //convert to number of bits, work out how many are left over, and pad to 6-leftOver.
		binary = binary << padding; //convert to number of bits, work out how many are left over, and pad to 6-leftOver.
		for (int j = 0; j < (4 - padding/6); j++)
		{
			char bits = (binary >> (18 - 6*j)); //shift a maximum of 18 bits to the left, and a minimum of 0
			int sixbits = bits & 0b111111; //the last 6 bits
			base64 += encoding_table[sixbits]; //look up the appropriate character
		}
		int bitCount;
		if ((bitCount = (hexChars.length() * 4) % 6) != 0)
		{
			switch (bitCount)
			{
			case 2: base64 += "=="; break; //remainder two means we have 4 bits to pad
			case 4: base64 += "="; break;
			}
		}
	}
	return base64;
}

int main(int argc, char *argv[])
{
	string base64 = hex2base64("49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d");
	cout << "The reference base64 encoded hex is: " << base64 << endl;
	if (argc > 1)
	{
		cout << "The base64 encoded hex for the parameter provided is: " << hex2base64(string(argv[1])) << endl;
	}
	return 0;
}