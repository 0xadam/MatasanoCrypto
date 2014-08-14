#include "hex.h"
#include <string>
#include <iostream>

using namespace std;

string xorHexString(string a, string b)
{
	if (a.length() != b.length())
	{
		return "String lengths are different!";
	}

	string result;
	for(int i = 0; i < a.length(); i++)
	{
		result += intToHexString(hexCharToInt(a[i]) ^ hexCharToInt(b[i]));
	}
	return result;
}

int main ()
{
	cout << xorHexString("1c0111001f010100061a024b53535009181c", "686974207468652062756c6c277320657965") << endl;
	return 0;
}