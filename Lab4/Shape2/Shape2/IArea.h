#pragma once
using GetAreaFn = std::function<double()>;
class CLineSegment;

class AreaCalculateMethods
{
public:
	static GetAreaFn MakeRectangleAreaFn(std::reference_wrapper<double> widthRef, std::reference_wrapper<double> heightRef);
	static GetAreaFn MakeZeroAreaFn();
	static GetAreaFn MakeCircleAreaFn(std::reference_wrapper<double> radius);
	static GetAreaFn MakeTriangleAreaFn(std::reference_wrapper<CLineSegment> side1, std::reference_wrapper<CLineSegment> side2, std::reference_wrapper<CLineSegment> side3);
};