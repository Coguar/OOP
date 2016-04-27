#include "stdafx.h"
#include "Shape.h"

void IShape::SetLineColor(std::string const& color)
{
	std::string tempColorString(color);
	m_lineColor = tempColorString;
}

std::string IShape::GetColor()
{
	return m_lineColor;
}

void ISolidShape::SetFillColor(std::string const& color)
{
	std::string tempColorString(color);
	m_fillColor = tempColorString;
}

CPoint::CPoint(float const & x, float const & y, StrColor const& color)
	: m_xPos(x)
	, m_yPos(y)
{
	SetLineColor(color);
}

std::string CPoint::StringRepresentation()
{
	std::cout << "Point<" << m_xPos << ", " << m_yPos << ">" << std::endl;
	return "";
}

std::pair<float, float> CPoint::GetPosition()
{
	return std::pair<float, float>({m_xPos, m_yPos});
}

std::string CPoint::GetPointPosAsString()
{
	return std::string("<" + std::to_string(m_xPos) + ", " + std::to_string(m_yPos) + ">");
}

const float CPoint::operator-(const CPoint & point) const
{
	return std::sqrt(std::pow(abs(m_xPos - point.m_xPos), 2) + std::pow(abs(m_yPos - point.m_yPos), 2));
}


////////////////////////////////////////////
/////CLineSegment///////////////////////////

CLineSegment::CLineSegment(Ñoordinate const & beginPos, Ñoordinate const & endPos, StrColor const & color)
{
	SetLineColor(color);
	m_beginPoint = std::make_unique<CPoint>(beginPos.first, beginPos.second, color);
	m_endPoint = std::make_unique<CPoint>(endPos.first, endPos.second, color);
}

std::string CLineSegment::StringRepresentation()
{
	std::cout << "LineSegment" << m_beginPoint->GetPointPosAsString() <<
		m_endPoint->GetPointPosAsString() << " length = " << GetPerimetr() << std::endl;
	return "";
}

float CLineSegment::GetPerimetr()
{
	return *m_beginPoint - *m_endPoint;
}

////////////////////////////////////////////
/////CRectangle/////////////////////////////

CRectangle::CRectangle(Ñoordinate const & pos, Size const & size, StrColor const & fillColor, StrColor const & lineColor)
	: m_width(size.first)
	, m_height(size.second)
{
	m_pos = std::make_unique<CPoint>(pos.first, pos.second, fillColor);
	SetFillColor(fillColor);
	SetLineColor(lineColor);
}

std::string CRectangle::StringRepresentation()
{
	std::string str = "Rectangle. Pos= " + m_pos->GetPointPosAsString() + " W= " + std::to_string( m_width) +
		" H= " + std::to_string(m_height) + " S= " + std::to_string(GetArea()) + " P= " + std::to_string(GetPerimetr());
	return str;
}

float CRectangle::GetArea()
{
	return m_height * m_width;
}

float CRectangle::GetPerimetr()
{
	return (2 * (m_height + m_width));
}

////////////////////////////////////////////
/////CTriangle//////////////////////////////

CTriangle::CTriangle(Ñoordinate const & pos1, Ñoordinate const & pos2, Ñoordinate const & pos3, StrColor const & fillColor, StrColor const & lineColor)
{
	m_pick1 = std::make_unique<CPoint>(pos1.first, pos1.second, lineColor);
	m_pick2 = std::make_unique<CPoint>(pos2.first, pos2.second, lineColor);
	m_pick3 = std::make_unique<CPoint>(pos3.first, pos3.second, lineColor);

	m_side1 = std::make_unique<CLineSegment>(pos1, pos2, lineColor);
	m_side2 = std::make_unique<CLineSegment>(pos2, pos3, lineColor);
	m_side3 = std::make_unique<CLineSegment>(pos3, pos1, lineColor);

	SetFillColor(fillColor);
	SetLineColor(lineColor);
}

std::string CTriangle::StringRepresentation()
{
	std::string str = "Triangle. Picks= " +  m_pick1->GetPointPosAsString() + m_pick2->GetPointPosAsString() +
		m_pick3->GetPointPosAsString() + " S= " + std::to_string(GetArea()) + " P= " + std::to_string(GetPerimetr());
	return str;
}

float CTriangle::GetArea()
{
	auto perimetr = GetPerimetr();
	return std::sqrt(perimetr * (perimetr - m_side1->GetPerimetr()) * (perimetr - m_side2->GetPerimetr()) * (perimetr - m_side3->GetPerimetr()));
}

float CTriangle::GetPerimetr()
{
	return m_side1->GetPerimetr() + m_side2->GetPerimetr() + m_side3->GetPerimetr();
}

////////////////////////////////////////////
/////CCircle////////////////////////////////

CCircle::CCircle(Ñoordinate const & pos, float const & radius, StrColor const & fillColor, StrColor const & lineColor)
	: m_radius(radius)
{
	m_pos = std::make_unique<CPoint>(pos.first, pos.second, fillColor);
	SetFillColor(fillColor);
	SetLineColor(lineColor);

}

std::string CCircle::StringRepresentation()
{
	return std::string();
}

float CCircle::GetArea()
{
	return 2 * M_PI * std::pow(m_radius, 2);
}

float CCircle::GetPerimetr()
{
	return 2 * M_PI * m_radius;
}

