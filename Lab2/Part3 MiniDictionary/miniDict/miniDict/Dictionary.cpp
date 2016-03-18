#include "stdafx.h"
#include "Dictionary.h"

void CDictionary::AddNewWord(std::string englishWord, std::string russianWord)
{
	m_dictionaryList.insert(std::pair<std::string, std::string>(englishWord, russianWord));

	m_newCollocations.push_back(englishWord + "=" + russianWord);
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

	std::ifstream dictInputFile(DIC_FILE);
	while (std::getline(dictInputFile, line))
	{

		m_dictionaryList.insert(GetPairOfWords(line));
	}
	dictInputFile.close();
}

void CDictionary::SaveChanges()
{
	std::ofstream dictFile(DIC_FILE, std::ios_base::app);
	for (auto &it : m_newCollocations)
	{
		dictFile << it << std::endl;
	}
	dictFile.close();
}

void CDictionary::Dialog(std::string word)
{
	while (m_state != finish)
	{
		switch (m_state)
		{
		case findWord:
			if (FindWord(word))
			{
				m_state = finish;
			}
			else
			{
				m_state = addWord;
			}
			break;
		case addWord:
			std::cout << "add translate or press Enter to skip" << std::endl;
			std::string translate;
			std::cin >> translate;
			if (!translate.empty())
			{
				AddNewWord(word, translate);
			}

			//AddNewWord(word, translate);
			m_state = finish;
			break;
		}

	}
	m_state = findWord;
}

void CDictionary::DictionarySave()
{
	if (!m_newCollocations.empty())
	{
		SaveChanges();
	}
}