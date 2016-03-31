#pragma once
#include "IFsmTable.h"


class CMooreTable :	public IFsmTable
{
public:
	virtual void Read(std::istream & in) override;

	struct State
	{
		std::map<char, size_t> transitions;
		char output;
	};


private:
	std::vector<State> m_states;
};

