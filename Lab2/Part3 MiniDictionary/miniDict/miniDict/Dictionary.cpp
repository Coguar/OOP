#include "stdafx.h"
#include "Dictionary.h"

CDictionary::CDictionary()
{
	m_dictionaryFile = DIC_FILE;
	LoadDictionaryFromFile();
}

void CDictionary::AddNewWord(std::string englishWord, std::string russianWord)
{
	m_dictionaryList.insert(std::pair<std::string, std::string>(englishWord, russianWord));

	m_newCollocations.push_back(englishWord + "=" + russianWord);

	std::cout << FINISH_ADD_WORD_STRING << russianWord << std::endl;
}

bool CDictionary::FindWord(std::string englishWord)
{
	auto word = m_dictionaryList.find(englishWord);
	if (word == m_dictionaryList.end())
	{
		return false;
	}

	std::cout << word->second << std::endl;
	return true;
}

Collocation GetPairOfWords(std::string line)
{
	bool isSecondWord = false;

	std::string rusWord;
	std::string engWord;

	for (auto &it : line)
	{
		if (it == DELIMITER && isSecondWord == false)
		{
			isSecondWord = true;
		}
		switch (isSecondWord)
		{
		case false: engWord += it;	break;
		case true: if (it != DELIMITER) rusWord += it;	break;
		}
	}
	return Collocation(engWord, rusWord);
}

void CDictionary::LoadDictionaryFromFile()
{
	std::string line;

	std::ifstream dictInputFile(m_dictionaryFile);
	while (std::getline(dictInputFile, line))
	{

		m_dictionaryList.insert(GetPairOfWords(line));
	}
	dictInputFile.close();
}

void CDictionary::SaveChanges()
{
	std::ofstream dictFile(m_dictionaryFile, std::ios_base::app);
	for (auto &it : m_newCollocations)
	{
		dictFile << it << std::endl;
	}
	dictFile.close();
}

void CDictionary::DictionarySave()
{
	if (!m_newCollocations.empty())
	{
		SaveChanges();
	}
}

void CDictionary::SetDictionaryFile(std::string fileName)
{
	m_dictionaryFile = fileName;
}