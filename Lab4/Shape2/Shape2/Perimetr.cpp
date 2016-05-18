#include "stdafx.h"
#include "Perimetr.h"

CRectanglePerimetr::CRectanglePerimetr(double & width, double & height)
{
	auto perimetr = PerimetrCalculateMethods::MakeRectanglePerimetrFn(width, height);
	SetPerimetr(perimetr);
}

CCirclePerimetr::CCirclePerimetr(double & radius)
{
	auto perimetr = PerimetrCalculateMethods::MakeCirclePerimetrFn(radius);
	SetPerimetr(perimetr);
}

CLineSegmentPerimetr::CLineSegmentPerimetr(CPoint & begin, CPoint & end)
{
	auto perimetr = PerimetrCalculateMethods::MakeLinePerimetrFn(begin, end);
	SetPerimetr(perimetr);

}

CPointPerimetr::CPointPerimetr()
{
	SetPerimetr(PerimetrCalculateMethods::MakeZeroPerimetrFn());
}

CTrianglePerimetr::CTrianglePerimetr(CLineSegment & side1, CLineSegment & side2, CLineSegment & side3)
{
	auto perimetr = PerimetrCalculateMethods::MakeTrianglePerimetrFn(side1, side2, side3);
	SetPerimetr(perimetr);

}

GetPerimetrFn PerimetrCalculateMethods::MakeRectanglePerimetrFn(std::reference_wrapper<double> widthRef, std::reference_wrapper<double> heightRef)
{
	return [=]() {
		return 2 * (widthRef.get() + heightRef.get());
	};
}

GetPerimetrFn PerimetrCalculateMethods::MakeZeroPerimetrFn()
{
	return [=]() {
		return 0;
	};
}

GetPerimetrFn PerimetrCalculateMethods::MakeCirclePerimetrFn(std::reference_wrapper<double> radius)
{
	return [=]() {
		return 	2 * M_PI * radius;
	};
}

GetPerimetrFn PerimetrCalculateMethods::MakeTrianglePerimetrFn(std::reference_wrapper<CLineSegment> side1, std::reference_wrapper<CLineSegment> side2, std::reference_wrapper<CLineSegment> side3)
{
	return [=]() {
		return side1.get().GetShapePerimetr() + side2.get().GetShapePerimetr() + side3.get().GetShapePerimetr();
	};
}

GetPerimetrFn PerimetrCalculateMethods::MakeLinePerimetrFn(std::reference_wrapper<CPoint> point1, std::reference_wrapper<CPoint> point2)
{
	return [=]() {
		return CPoint::GetDistance(point1, point2);
	};
}
