#pragma once
#include "Shapes.h"

struct Coordinate;

struct IStringRepresentation
{
	virtual ~IStringRepresentation() {};
	virtual std::string ToString() = 0;
};

class CAbstractStrShape : public IStringRepresentation
{
public:
	std::string ToString() override
	{
		return m_str;
	}

	void SetStr(std::string const& str)
	{
		m_str = str;
	}
private:
	std::string m_str;
};

class CRectangleStr: public CAbstractStrShape
{
public:
	CRectangleStr(Coordinate const& pos, double const& width, double const& height, double const & P, double const & S);
};


class CCircleStr : public CAbstractStrShape
{
public:
	CCircleStr(Coordinate const& pos, double const& radius, double const & P, double const & S);
};

class CLineSegmentStr : public CAbstractStrShape
{
public:
	CLineSegmentStr(Coordinate const& pos1, Coordinate const& pos2, double const & P, double const & S);
};

class CPointStr : public CAbstractStrShape
{
public:
	CPointStr(Coordinate const& pos, double const & P, double const & S);

};

class CTriangleStr : public CAbstractStrShape
{
public:
	CTriangleStr(Coordinate const& pos1, Coordinate const& pos2, Coordinate const& pos3, double const & P, double const & S);

};