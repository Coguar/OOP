// FindAndReplace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Replace.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		string subjectLine;
		while (getline(cin, subjectLine))
		{
			if (subjectLine.empty())
			{
				break;
			}
			cout << FindAndReplace(subjectLine, argv[1], argv[2]) << endl;
		}
	}
    return 0;
}

