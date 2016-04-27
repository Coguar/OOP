#include "stdafx.h"
#include "Shapes.h"

using namespace std;

CPoint::CPoint(Coordinate const & pos)
{
	m_pos = pos;
	SetAreaMethod(make_unique<CPointArea>());
	SetPerimetrMethod(make_unique<CPointPerimetr>());
	SetStringMethod(make_unique<CPointStr>(m_pos, GetShapeArea(), GetShapePerimetr()));
}

const double CPoint::operator-(const CPoint & point) const
{
	return std::sqrt(std::pow(abs(m_pos.x - point.m_pos.x), 2) + std::pow(abs(m_pos.y - point.m_pos.y), 2));
}

CLineSegment::CLineSegment(Coordinate const & bPos, Coordinate const & ePos)
{
	m_bPoint = make_unique<CPoint>(bPos);
	m_ePoint = make_unique<CPoint>(ePos);
	SetAreaMethod(make_unique<CLineSegmentArea>());
	SetPerimetrMethod(make_unique<CLineSegmentPerimetr>(*m_bPoint, *m_ePoint));
	SetStringMethod(make_unique<CLineSegmentStr>(bPos, ePos, GetShapeArea(), GetShapePerimetr()));
}

CRectangle::CRectangle(Coordinate const & pos, double const & width, double const & height)
{
	m_width = width;
	m_height = height;
	SetAreaMethod(make_unique<CRectangleArea>(m_height, m_width));
	SetPerimetrMethod(make_unique<CRectanglePerimetr>(m_height, m_width));

}
