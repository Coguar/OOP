// Shape.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Shape.h"

using namespace std;
template <typename T>
static void AppendIntoAreaVector(vector<T> & vec, T & shapePtr)
{
	for (auto it = vec.begin(); it <= vec.end(); ++it)
	{
		if (it->get()->GetArea() >= shapePtr->GetArea() || it == vec.end())
		{
			vec.insert(it, shapePtr);
		}
	}
}

template <typename T>;
static void AppendIntoPerimetrVector(vector<shared_ptr<IShape>> && vec, shared_ptr<IShape> && shapePtr)
{
	for (auto it = vec.begin(); it <= vec.end(); ++it)
	{
		if (it->get()->GetPerimetr() >= shapePtr->GetPerimetr() || it == vec.end())
		{
			vec.insert(it, shapePtr);
		}
	}
}

int main()
{
	vector<shared_ptr<IShape>> peremitrVec;

	std::shared_ptr<CPoint> circle = std::make_shared<CPoint>(4, 6, "ggg");
	Ñoordinate pos = { 10, 20 };
	Size size = { 4, 12 };
	std::shared_ptr<CRectangle> rect = std::make_shared<CRectangle>(pos, size, "ggg", "2323");

	peremitrVec.push_back(circle);
	peremitrVec.push_back(rect);

	AppendIntoPerimetrVector(peremitrVec, circle);
return 0;
}

