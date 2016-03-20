#pragma once
#include <string>
#include <map>
#include <vector>

const std::string DIC_FILE = "dictionary.txt";

const std::string FINISH_ADD_WORD_STRING = "new word remebered like ";
const std::string WHETHER_ADD_WORD_STRING = "add translate or press Enter to skip";

const char DELIMITER = '=';
const std::string EXIT_LINE = "...";

typedef std::pair<std::string, std::string> Collocation;

Collocation GetPairOfWords(std::string line);

class CDictionary
{
public:
	CDictionary();

	void DictionarySave();

	void LoadDictionaryFromFile();

	bool FindWord(std::string englishWord);

	void AddNewWord(std::string englishWord, std::string russianWord);

	void SetDictionaryFile(std::string fileName);

	bool DictListStat() { return m_dictionaryList.empty(); }

	bool DictsNewWordsStat() { return m_newCollocations.empty(); }


private:

	void SaveChanges();

	std::vector<std::string> m_newCollocations;

	std::map<std::string, std::string> m_dictionaryList;

	std::string m_dictionaryFile;

};