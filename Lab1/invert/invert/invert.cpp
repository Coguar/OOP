// invert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <fstream>
#include <string>
#include <io.h>
#include <algorithm>
#include <iostream>

using namespace std;

const int MATRIX_SIZE = 3;
typedef vector<vector<float>> Matrix;

float GetMinor(Matrix const& arr, int i, int j)
{
	size_t arrSize = arr.size();
	vector<float> minor;
	for (int x = 0; x < arrSize; x++)
	{
		for (int y = 0; y < arrSize; y++)
		{
			if (x != i && y != j)
			{
				minor.push_back(arr[x][y]);
			}
		}
	}
	return minor[0] * minor[3] - minor[1] * minor[2];
}

Matrix GetMinorMatrix(Matrix const& arr)
{
	size_t arrSize = arr.size();
	Matrix minorArr = arr;
	for (int i = 0; i <= arrSize; i++)
	{
		for (int j = 0; j <= arrSize; j++)
		{
			minorArr[i][j] = GetMinor(arr, i, j) * float(pow(-1, i + j));
		}
	}
	return minorArr;
}

float GetDeterminant(Matrix const& arr)
{
	size_t arrSize = arr.size();
	int plusPeacePos;
	int minusPeacePos;
	float determinant = 0;
	float plusPart = 1;
	float minusPart = 1;
	for (int k = 0; k < arrSize; k++)
	{
		plusPeacePos = k;
		minusPeacePos = k;
		for (int i = 0; i < arrSize; i++)
		{
			plusPart *= arr[i][plusPeacePos];
			minusPart *= arr[i][minusPeacePos];
			plusPeacePos++;
			minusPeacePos--;

			if (plusPeacePos > arrSize)
				plusPeacePos = 0;

			if (minusPeacePos < 0)
				minusPeacePos = arrSize;

		}
		determinant += plusPart - minusPart;
	}
	return determinant;
}

bool isInvertable(Matrix const& arr)
{
	return GetDeterminant(arr) != 0;
}

void showInvertMatrix(Matrix const& arr, float determinant)
{
	int arrSize = int(arr.size() - 1);
	for (int i = 0; i <= arrSize; i++)
	{
		for (int j = 0; j <= arrSize; j++)
		{
			printf("%6.3f  ", (float(arr[j][i]) / determinant));
		}
		cout << endl;
	}
}

Matrix GetMatrixFromFile(std::string inputFile)
{
	ifstream matrixFile(inputFile);
	Matrix arr(3);
	float number;
	int arrSize = 3;

	for (int i = 0; i < arrSize; i++)
		for (int j = 0; j < arrSize; j++)
		{
			number = 0;
			matrixFile >> number;
			arr[i].push_back(number);
		}
	matrixFile.close();
	return arr;
}

bool isCorrectFile(string inputFile)
{
	auto checkSymbol = [](char & symbol) 
	{
		return !(symbol >= '0' && symbol <= '9' || symbol == '-' || symbol == ' ' || symbol == '.');

	};

	string line;
	ifstream matrixFile(inputFile);
	int lineCount = 0;
	while (getline(matrixFile, line))
	{
		lineCount++;	
		if (std::any_of(line.begin(), line.end(), checkSymbol))
		{
			matrixFile.close();
			return false;
		}
	}
	matrixFile.close();
	if (lineCount != MATRIX_SIZE)
	{
		return false;
	}
	return true;
}

int main(int argc, char * argv[])
{
	if (argc < 2)
	{
		cout << "Error! Not enough arguments." << endl;
		return 1;
	}
	else if (argc > 2)
	{
		cout << "Error! Too many arguments." << endl;
		return 1;
	}
	else if (_access(argv[1], 0) == -1)
	{
		cout << "Error! File " << argv[1] << " not found." << endl;
		return 1;
	}
	else if (!isCorrectFile(argv[1]))
	{
		cout << "Error! Wrong file." << endl;
		return 1;
	}
	else
	{
		Matrix arr = GetMatrixFromFile(argv[1]);
		if (isInvertable(arr))
			showInvertMatrix(GetMinorMatrix(arr), GetDeterminant(arr));
		return 0;
	}
	cout << "Matrix can not be inverted." << endl;
	return 0;
}

