#include "stdafx.h"
#include "Shapes.h"


using namespace std;

CPoint::CPoint(Coordinate const & pos)
{
	// TODO: use `constructor initializer list`
	m_pos = pos;
	SetAreaMethod(make_unique<CPointArea>());
	SetPerimetrMethod(make_unique<CPointPerimetr>());
	SetStringMethod(make_unique<CPointStr>(m_pos, GetShapeArea(), GetShapePerimetr()));
}

double CPoint::GetDistance(CPoint const & first, CPoint const & second)
{
	return std::sqrt(std::pow(abs(first.m_pos.x - second.m_pos.x), 2) + std::pow(abs(first.m_pos.y - second.m_pos.y), 2));
}

CLineSegment::CLineSegment(Coordinate const & bPos, Coordinate const & ePos)
{
	m_bPoint = make_unique<CPoint>(bPos);
	m_ePoint = make_unique<CPoint>(ePos);
	SetAreaMethod(make_unique<CLineSegmentArea>());
	SetPerimetrMethod(make_unique<CLineSegmentPerimetr>(*m_bPoint, *m_ePoint));
	SetStringMethod(make_unique<CLineSegmentStr>(bPos, ePos, GetShapePerimetr(), GetShapeArea()));
}

CRectangle::CRectangle(Coordinate const & pos, double const & width, double const & height)
{
	m_width = width;
	m_height = height;
	m_pos = make_unique<CPoint>(pos);
	SetAreaMethod(make_unique<CRectangleArea>(m_height, m_width));
	SetPerimetrMethod(make_unique<CRectanglePerimetr>(m_height, m_width));
	SetStringMethod(make_unique<CRectangleStr>(pos, m_width, m_height, GetShapePerimetr(), GetShapeArea()));
}

double CAbstractShape::GetShapePerimetr()
{
	return m_perimetr->GetPerimetr();
}

double CAbstractShape::GetShapeArea()
{
	return m_area->GetArea();
}

std::string CAbstractShape::ShapeToString()
{
	return m_strRepr->ToString();
}

void CAbstractShape::SetLineColor(std::string const & color)
{
	m_lineColor = color;
}

void CAbstractShape::SetPerimetrMethod(std::unique_ptr<IPerimetr>&& perimetrMethod)
{
	assert(perimetrMethod);
	m_perimetr = move(perimetrMethod);
}

void CAbstractShape::SetAreaMethod(std::unique_ptr<IArea>&& areaMethod)
{
	assert(areaMethod);
	m_area = move(areaMethod);
}

void CAbstractShape::SetStringMethod(std::unique_ptr<IStringRepresentation>&& strMethod)
{
	assert(strMethod);
	m_strRepr = move(strMethod);
}

CCircle::CCircle(Coordinate const & pos, double const & radius)
{
	m_radius = radius;
	m_pos = make_unique<CPoint>(pos);
	SetAreaMethod(make_unique<CCircleArea>(m_radius));
	SetPerimetrMethod(make_unique<CCirclePerimetr>(m_radius));
	SetStringMethod(make_unique<CCircleStr>(pos, m_radius, GetShapePerimetr(), GetShapeArea()));
}

CTriangle::CTriangle(Coordinate const & pos1, Coordinate const & pos2, Coordinate const & pos3)
{
	m_pos1 = make_unique<CPoint>(pos1);
	m_pos2 = make_unique<CPoint>(pos2);
	m_pos3 = make_unique<CPoint>(pos3);

	m_side1 = make_unique<CLineSegment>(pos1, pos2);
	m_side2 = make_unique<CLineSegment>(pos1, pos2);
	m_side3 = make_unique<CLineSegment>(pos1, pos2);

	SetAreaMethod(make_unique<CTriangleArea>(*m_side1, *m_side2, *m_side3));
	SetPerimetrMethod(make_unique<CTrianglePerimetr>(*m_side1, *m_side2, *m_side3));
	SetStringMethod(make_unique<CTriangleStr>(pos1, pos2, pos3, GetShapePerimetr(), GetShapeArea()));
}
