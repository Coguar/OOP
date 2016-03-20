// GeneratorOfPrimeNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Generator.h"

void ShowSetsElements(set<size_t> const& anySet)
{
	for (auto &it : anySet)
	{
		cout << it << endl;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 1)
	{
		std::cout << "The command has no additional parameters" << std::endl;
		return 0;
	}
	string consoleLine;
	size_t range;
	while (std::getline(cin, consoleLine))
	{
		range = atoi(consoleLine.c_str());

		auto setOfPrimeNumbers = CGenerator::GetSetOfPrimeNumbers(range);
		ShowSetsElements(setOfPrimeNumbers);
	}

	return 0;
}

