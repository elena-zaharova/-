#pragma once
#include <string>
#include <map>

#include <iostream>
using namespace std;

class Functiond
{
public:
	Functiond();
	~Functiond();

	bool P1(string& currStr, map <string, string>& word);
	bool P2(string& currStr, map <string, string>& word);
	bool P3(string& currStr, map <string, string>& word);
	bool P4(string& currStr, map <string, string>& word);
	bool X(string& currStr, map <string, string>& word);
	bool Y(string& currStr, map <string, string>& word);

	string GetWordFromString(string& str);
	string DefineWord(string currWord, map <string, string>& word);
};