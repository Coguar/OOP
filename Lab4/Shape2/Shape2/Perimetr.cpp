#include "stdafx.h"
#include "Perimetr.h"

CRectanglePerimetr::CRectanglePerimetr(double const & width, double const & height)
{
	auto perimetr = 2 * (width + height);
	SetPerimetr(perimetr);
}

CCirclePerimetr::CCirclePerimetr(double const & radius)
{
	auto perimetr = 2 * M_PI * pow(radius, 2);
	SetPerimetr(perimetr);
}

CLineSegmentPerimetr::CLineSegmentPerimetr(CPoint const & begin, CPoint const & end)
{
	auto perimetr = begin - end;
	SetPerimetr(perimetr);

}

CPointPerimetr::CPointPerimetr()
{
	SetPerimetr(0);
}

CTrianglePerimetr::CTrianglePerimetr(double const & side1, double const & side2, double const & side3)
{
	auto perimetr = side1 + side2+ side3;
	SetPerimetr(perimetr);

}
