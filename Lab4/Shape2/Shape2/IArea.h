#pragma once
using GetAreaFn = std::function<double()>;
class CLineSegment;

class AreaCalculateMethods
{
public:
	static GetAreaFn MakeRectangleAreaFn(std::reference_wrapper<double> widthRef, std::reference_wrapper<double> heightRef);
	static GetAreaFn MakeZeroAreaFn();
	static GetAreaFn MakeCircleAreaFn(std::reference_wrapper<double> radius);
	static GetAreaFn MakeTriangleAreaFn(std::reference_wrapper<CLineSegment> side1, std::reference_wrapper<CLineSegment> side2, std::reference_wrapper<CLineSegment> side3);
};

//структура есть
struct IArea
{
	virtual ~IArea() {};
	//метод есть
	virtual double GetArea() = 0;
};

class CAbstractAreaShape : public IArea
{
public:
	double GetArea() override
	{
		return m_areaFn();
	}
	void SetArea(GetAreaFn const& area)
	{
		m_areaFn = area;
	}
private:
	GetAreaFn m_areaFn;
};

class CRectangleArea : public CAbstractAreaShape
{
public:
	CRectangleArea(double & width, double & height);
};


class CCircleArea : public CAbstractAreaShape
{
public:
	CCircleArea(double & radius);
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
	CTriangleArea(CLineSegment & side1, CLineSegment & side2, CLineSegment & side3);
};