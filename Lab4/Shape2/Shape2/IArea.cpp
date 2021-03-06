#include "stdafx.h"
#include "IArea.h"
#include "Shapes.h"

// TODO: add functional behavior or remove behaviors at all.
GetAreaFn AreaCalculateMethods::MakeRectangleAreaFn(std::reference_wrapper<double> widthRef, std::reference_wrapper<double> heightRef)
{
	return [=]() {
		return widthRef.get() * heightRef.get();
	};
}

GetAreaFn AreaCalculateMethods::MakeZeroAreaFn()
{
	return [=]() {
		return 0;
	};
}

GetAreaFn AreaCalculateMethods::MakeCircleAreaFn(std::reference_wrapper<double> radius)
{
	return [=]() {
		return M_PI * pow(radius, 2);
	};
}

GetAreaFn AreaCalculateMethods::MakeTriangleAreaFn(std::reference_wrapper<CLineSegment> side1, std::reference_wrapper<CLineSegment> side2, std::reference_wrapper<CLineSegment> side3)
{
	return [=]() {
		auto perimetr = side1.get().GetShapePerimetr() + side2.get().GetShapePerimetr() + side3.get().GetShapePerimetr();
		return sqrt(perimetr * (perimetr - side1.get().GetShapePerimetr()) * (perimetr - side2.get().GetShapePerimetr()) * (perimetr - side3.get().GetShapePerimetr()));
	};
}