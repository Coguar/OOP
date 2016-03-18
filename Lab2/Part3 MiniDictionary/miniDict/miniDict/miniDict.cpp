// miniDict.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dictionary.h"

#include <windows.h>



using namespace std;


int main(int argc, char *argv[])
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	if (argc != 1)
	{
		return 0;
	}

	string englishWord;
	CDictionary dictionary;
	dictionary.LoadDictionaryFromFile();
	while (getline(cin, englishWord) && englishWord != EXIT_LINE)
	{
		if (!englishWord.empty())
		{
			dictionary.Dialog(englishWord);
		}
		//действие
	}

	dictionary.DictionarySave();
	return 0;
}

