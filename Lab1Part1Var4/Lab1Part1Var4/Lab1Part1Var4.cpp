// Lab1Part1Var4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <io.h>
#include <fstream>
#include <string>
#include <iostream>
#include <sys/stat.h>

const int64_t MAX_SIZE = 2147483648;

bool IsNormalSize(char  * inputFile) 
{
	struct stat fi;
	stat(inputFile, &fi);
	return int(fi.st_size) < MAX_SIZE;
}

void RewriteWithoutReplace(char  * inputFile, char * outputFile) 
{
	std::string line;
	std::ifstream input(inputFile);
	std::ofstream output(outputFile);
	while (std::getline(input, line)) 
	{
		output << line << std::endl;
	}
	input.close();
	output.close();
}

void FindAndReplace(const char  * inputFile, const char * outputFile, std::string word, std::string wordToReplace)
{
	std::string line;
	std::string newLine;
	std::ifstream input(inputFile);
	std::ofstream output(outputFile);

	size_t pos = 0;
	
	std::string findWord(word);
	std::string newWord(wordToReplace);

	while (std::getline(input, line))
	{
		for (size_t i = 0; i < line.length();)
		{
			if (i <= line.length() - findWord.length() && line.substr(i, findWord.length()) == findWord)
			{
				i += findWord.length();
				output << newWord;
			}
			else
			{
				output << line[i];
				i++;
			}
		}
	}
	input.close();
	output.close();
}

bool CheckFileOnCorrect(const char * outputFile, const char  * inputFile)
{
	std::string oFile(outputFile);
	std::string iFile(inputFile);
	if (iFile.substr(iFile.length() - 4, iFile.length()) != ".txt") 
	{
		std::cout << "Error! File %s not correct."<< inputFile << std::endl;;
		return false;
	}
	else if (oFile.substr(oFile.length() - 4, oFile.length()) != ".txt")
	{
		std::cout << "Error! File %s not correct."<< outputFile << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}

int main(int argc, char * argv[])
{

	if (argc < 4)
	{
		if (argc == 2 && std::string(argv[1]) == "help")
		{
			std::cout << "replace.exe <InputFile> <OutputFile> <ToFind> <ToReplace>" << std::endl;
		}
		else
		{
			std::cout << "Error! Not enough arguments." << std::endl;
		}
		return 0;
	}
	else if (argc > 5)
	{
		std::cout << "Error! Too many arguments." << std::endl;
		return 0;
	}
	else if (_access(argv[1], 0) == -1) 
	{
		std::cout << "Error! File " << argv[1] << "not found." << std::endl;
		return 0;
	}
	else if(!CheckFileOnCorrect(argv[2], argv[1]))
	{
		return 0;
	}
	else {
		if (IsNormalSize(argv[1]))
		{
			if (argc == 5) {
				FindAndReplace(argv[1], argv[2], argv[3], argv[4]);
			}
			else {
				RewriteWithoutReplace(argv[1], argv[2]);
			}
		}
		else
		{
			std::cout << "Error! File too big." << std::endl;
			return 0;
		}
	}
    return 0;
}

