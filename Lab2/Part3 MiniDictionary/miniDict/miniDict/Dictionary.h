#pragma once
#include <string>
#include <map>
#include <vector>

const std::string DIC_FILE = "dictionary.txt";

const char DELIMITER = '=';
const std::string EXIT_LINE = "...";

typedef std::pair<std::string, std::string> Collocation;

class CDictionary
{
public:

	void Dialog(std::string word);

	void DictionarySave();

	void LoadDictionaryFromFile();

private:
	void AddNewWord(std::string englishWord, std::string russianWord);

	bool FindWord(std::string englishWord);


	void SaveChanges();

	std::vector<std::string> m_newCollocations;

	std::map<std::string, std::string> m_dictionaryList;

	enum state 
	{findWord, addWord, finish} m_state;

};