#include "stdafx.h"
#include "Replace.h"

void Replace(std::string & subject, std::string const& search, std::string const& replace, size_t & i)
{
	subject += replace;
	i += search.size() - 1;
}

std::string FindAndReplace(std::string subject, std::string search, std::string replace)
{
	std::string str;
	for (size_t i = 0; i < subject.size();  ++i)
	{
		std::string test = subject.substr(i, i + search.size());
		if (subject[i] == search[0] && subject.substr(i, search.size()) == search)
		{
			Replace(str, search, replace, i);
		}
		else
		{
			str += subject[i];
		}
	}
	return str;
}