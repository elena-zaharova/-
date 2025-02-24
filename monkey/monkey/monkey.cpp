#include "stdafx.h"
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Functiond.h"

using namespace std;

vector<string> GetWordsInRaw(string fileName) {

	ifstream ifs(fileName);
	vector<string> wordsInRaw;

	if (!ifs.is_open())
	{
		cout << fileName << endl;
		cout << "Sorry, input file can not be opened." << endl;
	}
	else
	{
		string str;
		while (getline(ifs, str)) {
			wordsInRaw.push_back(str);
		}
	}

	return wordsInRaw;
}
map <string, string>  GetWordDictionary() {

	map <string, string> words = {
		{ "au", "w1" },
		{ "ku", "w2" },
		{ "ux-ti", "w3" },
		{ "ho", "w4" },
		{ "nu", "w5" },
		{ "i_nu", "w6" },
		{ "oi", "w7" },
		{ "kakoy", "w8" }
	};

	return words;
}

void Process(vector<string>& wordsInRaw, map <string, string>& word) {

	int strAmount = wordsInRaw.size();
	string currStr;

	for (int i = 0; i < strAmount; i++) {

		currStr = wordsInRaw[i];
		cout << "Dialogue cue: " << currStr << endl;

		Functiond functions = Functiond();
		bool isCorrect = functions.P1(currStr, word);

		if (isCorrect) 
			cout << " {OK} This monkey from this flock." << endl << endl;
		else 
			cout << " {ERROR} It's an alien monkey" << endl << endl;
	}
}

int main(int argc, char* argv[])
{
	vector<string> wordsInRaw = GetWordsInRaw(argv[1]);
	map <string, string> word = GetWordDictionary();

	Process(wordsInRaw, word);

	system("pause");

    return 0;
}