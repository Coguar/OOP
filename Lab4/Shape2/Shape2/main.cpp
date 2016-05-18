// Shape2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "App.h"

enum ShapeClass{Dot, Line, Triangle, Rectangle, Circle};

int main()
{
	CApp myApp;
	std::string str;
	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		std::getline(std::cin, str);
		if (!std::cin.fail())
		{
			myApp.AddShape(str);
		}
	}
	myApp.PrintStats();
    return 0;
}

