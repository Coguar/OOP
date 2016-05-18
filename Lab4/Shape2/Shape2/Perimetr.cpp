#include "stdafx.h"
#include "Perimetr.h"
#include "Shapes.h"

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
