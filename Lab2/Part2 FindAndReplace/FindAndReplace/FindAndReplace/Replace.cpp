#include "stdafx.h"
#include "Replace.h"
#include <cassert>
#include <iostream>


std::string FindAndReplace(std::string const& subject, std::string const& search, std::string const& replace)
{
	if (search.empty() || search.length() > subject.length())
	{
		return subject;
	}
	std::string str;

	for (size_t i = 0; i < subject.length();)
	{
		if (i <= subject.length() - search.length() &&
					std::equal(subject.begin() + i, subject.begin() + i + search.size(), search.begin()))
		{
			
			str += replace;
			i += search.size();
		}
		else
		{
			str += subject[i];
			++i;
		}
	}
	return str;
}