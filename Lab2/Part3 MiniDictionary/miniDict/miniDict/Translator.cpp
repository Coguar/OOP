#include "stdafx.h"
#include "Translator.h"

CTranslator::CTranslator(CDictionary & dict)
	:m_dict(dict)
{
	m_state = findWord;
}

void CTranslator::DialogWithUser(std::string word)
{

	while (m_state != finish)
	{
		switch (m_state)
		{
		case findWord:
			if (m_dict.FindWord(word))
			{
				m_state = finish;
			}
			else
			{
				m_state = addWord;
			}
			break;
		case addWord:
			std::cout << WHETHER_ADD_WORD_STRING << std::endl;
			std::string translate;
			std::getline(std::cin, translate);
			if (!translate.empty())
			{
				m_dict.AddNewWord(word, translate);
			}

			m_state = finish;
			break;
		}

	}
	m_state = findWord;
}

