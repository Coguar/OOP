#pragma once
#include <fstream>
#include <vector>
#include <map>

class IFsmTable
{
public:
	virtual ~IFsmTable() = default;
	virtual void Read(std::istream & in) = 0;
};

