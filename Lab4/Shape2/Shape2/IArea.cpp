#include "stdafx.h"
#include "IArea.h"

CRectangleArea::CRectangleArea(double const & width, double const & height)
{
	auto area = width * height;
	SetArea(area);
}

CCircleArea::CCircleArea(double const & radius)
{
	auto area = M_PI * pow(radius, 2);
	SetArea(area);

}

CLineSegmentArea::CLineSegmentArea()
{
	SetArea(0);

}

CPointArea::CPointArea()
{
	SetArea(0);

}

CTriangleArea::CTriangleArea(double const & side1, double const & side2, double const & side3)
{
	auto perimetr = side1 + side2 + side3;
	auto area = sqrt(perimetr * (perimetr - side1) * (perimetr - side2) * (perimetr - side3));
	SetArea(area);
}
