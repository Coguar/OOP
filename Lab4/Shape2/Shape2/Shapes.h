#pragma once
#include "Perimetr.h"
#include "StringRepresentation.h"
#include "IArea.h"

struct IStringRepresentation;
struct IArea;
struct IPerimetr;

struct Coordinate
{
	double x;
	double y;
};

struct IShape
{
	virtual double GetShapePerimetr() = 0;
	virtual double GetShapeArea() = 0;
	virtual std::string ShapeToString() = 0;
};

// todo rename since its abstract class
class CAbstractShape : public IShape
{
public:
	CAbstractShape()
	{
		SetLineColor("#000000"); 
	}
	double GetShapePerimetr() override; 
	double GetShapeArea() override;
	std::string ShapeToString() override;

	void SetLineColor(std::string const& color);

protected:
	void SetPerimetrMethod(GetPerimetrFn && perimetrMethod);
	void SetAreaMethod(GetAreaFn && areaMethod);
	void SetStringMethod(std::unique_ptr<IStringRepresentation> && strMethod);
private:
	GetPerimetrFn m_perimetr;
	GetAreaFn m_area;
	std::unique_ptr<IStringRepresentation> m_strRepr;

	std::string m_lineColor;
};

class CAbstractSolidShape : public CAbstractShape
{
public:
	CAbstractSolidShape()
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

class CPoint : public CAbstractShape
{
public:
	CPoint(Coordinate const& pos);
	static double GetDistance(CPoint const& first, CPoint const& second);
private:
	Coordinate m_pos;
};

/////CLineSegment/////

class CLineSegment : public CAbstractShape
{
public:
	CLineSegment(Coordinate const& bPos, Coordinate const& ePos);
private:
	std::unique_ptr<CPoint> m_bPoint;
	std::unique_ptr<CPoint> m_ePoint;

};

/////CRectangle/////

class CRectangle : public CAbstractSolidShape
{
public:
	CRectangle(Coordinate const& pos, double const& width, double const& height);
private:
	std::unique_ptr<CPoint> m_pos;
	double m_width;
	double m_height;

};

/////CCircle/////
class CCircle : public CAbstractSolidShape
{
public:
	CCircle(Coordinate const& pos, double const& radius);
private:
	std::unique_ptr<CPoint> m_pos;
	double m_radius;
};

/////CTriangle/////
class CTriangle : public CAbstractSolidShape
{
public:
	CTriangle(Coordinate const& pos1, Coordinate const& pos2, Coordinate const& pos3);
private:
	std::unique_ptr<CPoint> m_pos1;
	std::unique_ptr<CPoint> m_pos2;
	std::unique_ptr<CPoint> m_pos3;
	std::unique_ptr<CLineSegment> m_side1;
	std::unique_ptr<CLineSegment> m_side2;
	std::unique_ptr<CLineSegment> m_side3;
};