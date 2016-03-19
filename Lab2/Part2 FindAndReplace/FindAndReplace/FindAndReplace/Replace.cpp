#include "stdafx.h"
#include "Replace.h"
#include <cassert>
#include <iostream>


std::string FindAndReplace(std::string subject, std::string search, std::string replace)
{
	if (search.empty())
	{
		return subject;
	}
	std::string str;

	for (size_t i = 0; i <= subject.length() - search.length();)
	{
		assert(i + search.size() <= subject.length());
		if (std::equal(subject.begin() + i, subject.begin() + i + search.size(), search.begin()))
		{
			
			str += replace;
			i += search.size();
			std::cout << i << "   " <<subject[i] << "   "<<str << std::endl;
		}
		else
		{
			str += subject[i];
			++i;
		}
	}
	return str;
}