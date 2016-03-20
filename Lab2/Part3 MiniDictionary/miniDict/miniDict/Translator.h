#pragma once
#include "Dictionary.h"

class CTranslator
{
public:
	CTranslator(CDictionary & dict);

	void DialogWithUser(std::string word);

private:
	CDictionary & m_dict;

	enum state
	{
		findWord, addWord, finish
	} m_state;

};