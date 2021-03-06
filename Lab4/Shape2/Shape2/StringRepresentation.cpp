#include "stdafx.h"
#include "StringRepresentation.h"

CRectangleStr::CRectangleStr(Coordinate const & pos, double const & width, double const & height, double const & P, double const & S)
{
	std::string str = "Rectangle ";
	str += "<";
	str += std::to_string(pos.x);
	str += ", ";
	str += std::to_string(pos.y);
	str += "> W = ";
	str += std::to_string(width);
	str += " H = ";
	str += std::to_string(height);
	str += " S = ";
	str += std::to_string(S);
	str += " P = ";
	str += std::to_string(P);
	SetStr(str);
}

CPointStr::CPointStr(Coordinate const & pos, double const & P, double const & S)
{
	std::string str = "Point ";
	str += "<";
	str += std::to_string(pos.x);
	str += ", ";
	str += std::to_string(pos.y);
	str += "> S = ";
	str += std::to_string(S);
	str += " P = ";
	str += std::to_string(P);
	SetStr(str);
}

CLineSegmentStr::CLineSegmentStr(Coordinate const& pos1, Coordinate const& pos2, double const & P, double const & S)
{
	std::string str = "LineSegment ";
	str += "<";
	str += std::to_string(pos1.x);
	str += ", ";
	str += std::to_string(pos1.y);
	str += "><";
	str += std::to_string(pos2.x);
	str += ", ";
	str += std::to_string(pos2.y);
	str += ">";
	str += " S = ";
	str += std::to_string(S);
	str += " P = ";
	str += std::to_string(P);
	SetStr(str);
}

CCircleStr::CCircleStr(Coordinate const & pos, double const & radius, double const & P, double const & S)
{
	std::string str = "Circle ";
	str += "<";
	str += std::to_string(pos.x);
	str += ", ";
	str += std::to_string(pos.y);
	str += "> R = ";
	str += std::to_string(radius);
	str += " S = ";
	str += std::to_string(S);
	str += " P = ";
	str += std::to_string(P);
	SetStr(str);
}

CTriangleStr::CTriangleStr(Coordinate const & pos1, Coordinate const & pos2, Coordinate const & pos3, double const & P, double const & S)
{
	std::string str = "Triangle ";
	str += "<";
	str += std::to_string(pos1.x);
	str += ", ";
	str += std::to_string(pos1.y);
	str += "><";
	str += std::to_string(pos2.x);
	str += ", ";
	str += std::to_string(pos2.y);
	str += "><";
	str += std::to_string(pos3.x);
	str += ", ";
	str += std::to_string(pos3.y);
	str += ">";
	str += " S = ";
	str += std::to_string(S);
	str += " P = ";
	str += std::to_string(P);
	SetStr(str);

}
