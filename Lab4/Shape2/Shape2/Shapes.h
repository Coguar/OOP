#pragma once
#include "Perimetr.h"
#include "IArea.h"
#include "StringRepresentation.h"

struct IStringRepresentation;
struct IArea;
struct IPerimetr;

struct Coordinate
{
	double x;
	double y;
};

class IShape
{
public:
	IShape() 
	{
		SetLineColor("#000000"); 
	}
	double GetShapePerimetr()
	{
		return m_perimetr->GetPerimetr();
	}
	double GetShapeArea()
	{
		return m_area->GetArea();
	}
	std::string ShapeToString()
	{
		return m_strRepr->ToString();
	}
	void SetLineColor(std::string const& color)
	{
		m_lineColor = color;
	}
	void SetPerimetrMethod(std::unique_ptr<IPerimetr> && perimetrMethod)
	{
		assert(perimetrMethod);
		m_perimetr = move(perimetrMethod);
	}
	void SetAreaMethod(std::unique_ptr<IArea> && areaMethod)
	{
		assert(areaMethod);
		m_area = move(areaMethod);
	}
	void SetStringMethod(std::unique_ptr<IStringRepresentation> && strMethod)
	{
		assert(strMethod);
		m_strRepr = move(strMethod);
	}
private:
	std::unique_ptr<IPerimetr> m_perimetr;
	std::unique_ptr<IArea> m_area;
	std::unique_ptr<IStringRepresentation> m_strRepr;

	std::string m_lineColor;
};

class ISolidShape : public IShape
{
public:
	ISolidShape() 
	{ 
		SetFillColor("#000000"); 
	}
	void SetFillColor(std::string const& color)
	{
		m_fillColor = color;
	}
private:
	std::string m_fillColor;
};

/////CPoint/////

class CPoint : public IShape
{
public:
	CPoint(Coordinate const& pos);
	const double operator-(const CPoint& rv) const;

private:
	Coordinate m_pos;
};

/////CLineSegment/////

class CLineSegment : public IShape
{
public:
	CLineSegment(Coordinate const& bPos, Coordinate const& ePos);
private:
	std::unique_ptr<CPoint> m_bPoint;
	std::unique_ptr<CPoint> m_ePoint;

};

/////CRectangle/////

class CRectangle : public IShape
{
public:
	CRectangle(Coordinate const& pos, double const& width, double const& height);
private:
	std::unique_ptr<CPoint> m_pos;
	double m_width;
	double m_height;

};