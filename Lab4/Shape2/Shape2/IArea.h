#pragma once
#include "Shapes.h"
//структура есть
struct IArea
{
	virtual ~IArea() {};
	//методд есть
	virtual double GetArea() = 0;
};

class CAbstractAreaShape : public IArea
{
public:
	double GetArea() override
	{
		return m_area;
	}
	void SetArea(double const& area)
	{
		m_area = area;
	}
private:
	double m_area;
};

class CRectangleArea : public CAbstractAreaShape
{
public:
	CRectangleArea(double const& width, double const& height);
};


class CCircleArea : public CAbstractAreaShape
{
public:
	CCircleArea(double const& radius);
};

class CLineSegmentArea : public CAbstractAreaShape
{
public:
	CLineSegmentArea();
};

class CPointArea : public CAbstractAreaShape
{
public:
	CPointArea();

};

class CTriangleArea : public CAbstractAreaShape
{
public:
	CTriangleArea(double const & side1, double const & side2, double const & side3);
};