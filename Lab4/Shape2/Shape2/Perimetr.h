#pragma once
#include "Shapes.h"

class CPoint;
class CLineSegment;

using GetPerimetrFn = std::function<double()>;

class PerimetrCalculateMethods
{
public:
	static GetPerimetrFn MakeRectanglePerimetrFn(std::reference_wrapper<double> widthRef, std::reference_wrapper<double> heightRef);
	static GetPerimetrFn MakeZeroPerimetrFn();
	static GetPerimetrFn MakeCirclePerimetrFn(std::reference_wrapper<double> radius);
	static GetPerimetrFn MakeTrianglePerimetrFn(std::reference_wrapper<CLineSegment> side1, std::reference_wrapper<CLineSegment> side2, std::reference_wrapper<CLineSegment> side3);
	static GetPerimetrFn MakeLinePerimetrFn(std::reference_wrapper<CPoint> point1, std::reference_wrapper<CPoint> point2);
};

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
		return m_perimetr();
	}
	void SetPerimetr(GetPerimetrFn const& perimetr)
	{
		m_perimetr = perimetr;
	}
private:
	GetPerimetrFn m_perimetr;
};

class CRectanglePerimetr : public CAbstractPerimetrShape
{
public:
	CRectanglePerimetr(double & width, double & height);
};

class CTrianglePerimetr : public CAbstractPerimetrShape
{
public:
	CTrianglePerimetr(CLineSegment & side1, CLineSegment & side2, CLineSegment & side3);
};

class CCirclePerimetr : public CAbstractPerimetrShape
{
public:
	CCirclePerimetr(double & radius);
};

class CLineSegmentPerimetr : public CAbstractPerimetrShape
{
public:
	CLineSegmentPerimetr(CPoint & begin, CPoint & end);
};

class CPointPerimetr : public CAbstractPerimetrShape
{
public:
	CPointPerimetr();

};