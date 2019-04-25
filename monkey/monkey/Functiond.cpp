#include "stdafx.h"
#include "Functiond.h"


Functiond::Functiond()
{
}

Functiond::~Functiond()
{
}

bool Functiond::P3(string& currStr, map <string, string>& word) {

	string currWord = GetWordFromString(currStr);
	string value = DefineWord(currWord, word);

	if (value == "w3") 
		return true;

	if ((value == "w4") && P3(currStr, word))
		return true;

	if ((value == "w5") && P4(currStr, word)) {
		currWord = GetWordFromString(currStr);
		value = DefineWord(currWord, word);

		if (value == "w6")
			return true;
	}

	return false;
}

bool Functiond::Y(string& currStr, map <string, string>& word) {

	string savingStr = currStr;

	if ((currStr == "") || (currStr == " ")) 
		return true;
	else {
		string currWord = GetWordFromString(currStr);
		string value = DefineWord(currWord, word);

		if (value == "w2") {
			bool isCorrect = P3(currStr, word);

			if (isCorrect) {
				isCorrect = Y(currStr, word);

				if (isCorrect) 
					return true;
			}
		}
		else {
			currStr = savingStr;
			return true;
		}
	}

	return false;
}

bool Functiond::P2(string& currStr, map <string, string>& word) {

	if (P3(currStr, word)) {
		if (Y(currStr, word))
			return true;
	}

	return false;
}

bool Functiond::X(string& currStr, map <string, string>& word) {

	string savingStr = currStr;

	if ((currStr == "") || (currStr == " ")) 
		return true;
	else {
		string currWord = GetWordFromString(currStr);
		string value = DefineWord(currWord, word);

		if (value == "w1") {
			if (P2(currStr, word)) {
				if (X(currStr, word))
					return true;
			}
		}
		else {
			currStr = savingStr;
			return true;
		}
	}

	return false;
}

bool Functiond::P1(string& currStr, map <string, string>& word) {

	if (P2(currStr, word)) {
		if (X(currStr, word))
			return true;
	}

	return false;
}

bool Functiond::P4(string& currStr, map <string, string>& word) {

	string savingStr = currStr;

	if ((currStr == "") || (currStr == " "))
		return true;
	else {
		string currWord = GetWordFromString(currStr);
		string value = DefineWord(currWord, word);

		if (value == "w7") {

			if (P1(currStr, word)) {
				currWord = GetWordFromString(currStr);
				value = DefineWord(currWord, word);

				if (value == "w8")
					return true;
			}
		}
		else {
			currStr = savingStr;
			return true;
		}
	}

	return false;
}


string Functiond::DefineWord(string currWord, map <string, string>& word) {

	string result;

	auto search = word.find(currWord);

	if (search != word.end())
	{
		if (currWord != "")
			result = search->second;
	}

	return result;
}

string Functiond::GetWordFromString(string& str) {

	string newString = "";
	string wordFromString = "";
	bool isWord = false;

	for (int i = 0; i < str.length(); i++) {

		if ((str[i] != ' ') && !isWord) {
			wordFromString = wordFromString + str[i];
		}
		else {
			if (i != 0) {
				isWord = true;
				newString = newString + str[i];
			}
		}
	}

	str = newString;

	return wordFromString;
}