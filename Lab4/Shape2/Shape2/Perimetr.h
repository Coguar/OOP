#pragma once
#include "Shapes.h"

class CPoint;

struct IPerimetr
{
	virtual ~IPerimetr() {};
	virtual double GetPerimetr() = 0;
};

class CAbstractPerimetrShape : public IPerimetr
{
public:
	virtual double GetPerimetr() override
	{
		return m_perimetr;
	}
	void SetPerimetr(double const& perimetr)
	{
		m_perimetr = perimetr;
	}
private:
	double m_perimetr;
};

class CRectanglePerimetr : public CAbstractPerimetrShape
{
public:
	CRectanglePerimetr(double const& width, double const& height);
};

class CTrianglePerimetr : public CAbstractPerimetrShape
{
public:
	CTrianglePerimetr(double const & side1, double const & side2, double const & side3);
};

class CCirclePerimetr : public CAbstractPerimetrShape
{
public:
	CCirclePerimetr(double const& radius);
};

class CLineSegmentPerimetr : public CAbstractPerimetrShape
{
public:
	CLineSegmentPerimetr(CPoint const& begin, CPoint const& end);
};

class CPointPerimetr : public CAbstractPerimetrShape
{
public:
	CPointPerimetr();

};