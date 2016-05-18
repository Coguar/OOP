#pragma once

class CPoint;
class CLineSegment;

using GetPerimetrFn = std::function<double()>;

class PerimetrCalculateMethods
{
public:
	static GetPerimetrFn MakeRectanglePerimetrFn(std::reference_wrapper<double> widthRef, std::reference_wrapper<double> heightRef);
	static GetPerimetrFn MakeZeroPerimetrFn();
	static GetPerimetrFn MakeCirclePerimetrFn(std::reference_wrapper<double> radius);
	static GetPerimetrFn MakeTrianglePerimetrFn(std::reference_wrapper<CLineSegment> side1, std::reference_wrapper<CLineSegment> side2, std::reference_wrapper<CLineSegment> side3);
	static GetPerimetrFn MakeLinePerimetrFn(std::reference_wrapper<CPoint> point1, std::reference_wrapper<CPoint> point2);
};
