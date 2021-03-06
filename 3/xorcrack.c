#include "hex.h"
#include "fixedxor.h"
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

bool isPrintable(string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		if (!isprint(text[i]))
			return false;
	}
	return true;
}

int main()
{
	//convert string from hex encoded to normal
	// i.e. 414141 = AAA
	// XOR with a character
	// Convert to ASCII

	string crackMe = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
	for (int i = 0; i < 128; i++)
	{
		string key;
		while (key.length() < crackMe.length())
		{
			key+=intToHexString(i);
		}
		string plaintext = hexToAscii(xorHexString(crackMe,key));
		if (!isPrintable(plaintext))
			continue;
		//cout <<"Key: " << key << endl; 
		cout << "For the character \"" << char(i) << "\" the string is:\"";
		cout << plaintext << "\"" << endl;
	}
}