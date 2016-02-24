// radix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>


const int MIN_NOTATION = 2;
const int MAX_NOTATION = 36;

int GetNumber(char num, int radix, bool & wasError)
{
	int number = (int)(num);
	if (number > 47 && number < 58)
	{
		if (number - 48 < radix)
			return number - 48;
		else
		{
			wasError = true;
			return -1;
		}
	}
	else if (number > 64 && number < 91)
	{
		number = number - (int)('A') + 10;
		if (number < radix)
			return number;
		else
		{
			wasError = true;
			return -1;
		}
	}
	else
	{
		wasError = true;
		return -1;
	}
}

char GetSymbol(int num)
{
	
	if (num < 10)
	{
		return char(num + 48);
	}
	else
		return char(num - 10 + 65);
}

int StringToInt(std::string str, int radix, bool & wasError)
{
	int len = str.length();
	int64_t number = 0;
	int i = 0;
	char symbol;
	while (str[i] && !wasError)
	{
		symbol = str[i];
		number += int64_t(GetNumber(str[i], radix, wasError) * std::pow(radix, len - i - 1));
		i++;
	}
	if (INT32_MAX < number)
	{
		wasError = true;
		return -1;
	}
	else
		return int(number);
}

std::string IntToString(int n, int radix)
{
	std::string number = "";
	while (n > 0)
	{
		number = GetSymbol(n % radix) + number;
		n = int(n / radix);
	}
	return number;
}

std::string TransferNumber(int present, int future, std::string & value, bool & wasError)
{
	int number = StringToInt(value, present, wasError);
	if (!wasError)
	{
		return IntToString(number, future);
	}
	return "Error";
}

bool IsNumber(char * num)
{
	int i = 0;
	while (num[i])
	{
		if (!(((int)(num[i]) > 64 && (int)(num[i]) < 91) || ((int)(num[i]) > 47 && (int)(num[i]) < 58) || (int)(num[i]) == 45 || (int)(num[i]) == 43))
			return 0;
		i++;
	}
	return true;
}

bool WasMinusSign(std::string & number)
{
	if (number[0] == '-' || number[0] == '+')
	{
		if (number[0] == '-')
		{
			number.erase(0, 1);
			return true;
		}
		else
		{
			number.erase(0, 1);
			return false;
		}
	}
	return false;
}

bool IsPermissibleNotation(char * minNotation, char * maxNotation)
{
	int minNotationNumber = atoi(minNotation);
	int maxNotationNumber = atoi(maxNotation);
	return !(minNotationNumber < MIN_NOTATION || minNotationNumber > MAX_NOTATION 
							|| maxNotationNumber < MIN_NOTATION || maxNotationNumber > MAX_NOTATION);
}

int main(int argc, char * argv[])
{
	std::string value;
	std::string answer;
	bool isMinusNumber = false;
	bool wasError = false;
	if (argc < 4)
	{
		std::cout << "Error! Not enough arguments." << std::endl;
		return 1;
	}
	else if (argc > 4)
	{
		std::cout << "Error! Too many arguments." << std::endl;
		return 1;
	}
	//TO DO :Сделать в функцию
	else if (!IsPermissibleNotation(argv[1], argv[2]))
	{
		std::cout << "Error! Wrong notation (it must be[2;36])." << std::endl;
		return 1;
	}
	else if (!IsNumber(argv[3]))
	{
		std::cout << "Error! This is not number of this notation." << std::endl;
		return 1;
	}
	else
	{
		value = argv[3];
		isMinusNumber = WasMinusSign(value);
		answer = TransferNumber(atoi(argv[1]), atoi(argv[2]), std::ref(value), wasError);
		if (wasError)
		{
			std::cout << "Error! Wrong value!!" << std::endl;
			return 1;
		}
		if (isMinusNumber)
			std::cout << "-" << answer << std::endl;
		else
			std::cout << answer << std::endl;
		
	}
    return 0;
}

