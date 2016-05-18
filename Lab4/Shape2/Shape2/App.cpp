#include "stdafx.h"
#include "App.h"


CApp::CApp()
{
}


CApp::~CApp()
{
}

void CApp::AddShape(std::string const & command)
{
	auto commandsElements = ParseCommand(command);
	RecognizeCommand(commandsElements);
}

void CApp::PrintStats()
{
	std::cout << "Perimetr" << std::endl;
	PrintByPerimetr();
	std::cout << std::endl;
	std::cout << "Area" << std::endl;
	PrintByArea();
	std::cout << std::endl;
}

size_t CApp::GetShapesCount()
{
	return m_shapes.size();
}

std::vector<std::string> CApp::ParseCommand(std::string const& commandLine)
{
	std::vector<std::string> commandElements;
	std::istringstream command(commandLine);
	std::string element;
	while (command)
	{
		command >> element;
		commandElements.push_back(element);
	}
	commandElements.pop_back();
	return commandElements;
}

void CApp::RecognizeCommand(std::vector<std::string> const & commandsElement)
{
	if (commandsElement[0] == "Point")
	{
		AddPoint(commandsElement);
	}
	else if (commandsElement[0] == "Line")
	{
		AddLine(commandsElement);
	}
	else if (commandsElement[0] == "Circle")
	{
		AddCircle(commandsElement);
	}
	else if (commandsElement[0] == "Triangle")
	{
		AddTriangle(commandsElement);
	}
	else if (commandsElement[0] == "Rectangle")
	{
		AddRectangle(commandsElement);
	}
}

void CApp::AddPoint(std::vector<std::string> const & params)
{
	if (params.size() >= 3)
	{
		double x = (isNumber(params[1]) ? ToNumber(params[1]) : 0);
		double y = (isNumber(params[2]) ? ToNumber(params[2]) : 0);
		Coordinate pos = { x, y };
		auto point = std::make_shared<CPoint>(pos);
		if (params.size() > 3)
		{
			point->SetLineColor(params[3]);
		}
		m_shapes.push_back(point);
	}
}

void CApp::AddLine(std::vector<std::string> const & params)
{
	if (params.size() >= 5)
	{
		double fx = (isNumber(params[1]) ? ToNumber(params[1]) : 0);
		double fy = (isNumber(params[2]) ? ToNumber(params[2]) : 0);
		double sx = (isNumber(params[3]) ? ToNumber(params[3]) : 0);
		double sy = (isNumber(params[4]) ? ToNumber(params[4]) : 0);
		Coordinate fPos = { fx, fy };
		Coordinate sPos = { sx, sy };
		auto line = std::make_shared<CLineSegment>(fPos, sPos);
		if (params.size() > 5)
		{
			line->SetLineColor(params[5]);
		}
		m_shapes.push_back(line);
	}
}

void CApp::AddCircle(std::vector<std::string> const & params)
{
	if (params.size() >= 4)
	{
		double x = (isNumber(params[1]) ? ToNumber(params[1]) : 0);
		double y = (isNumber(params[2]) ? ToNumber(params[2]) : 0);
		double radius = (isNumber(params[3]) ? ToNumber(params[3]) : 0);
		Coordinate pos = { x, y };
		auto circle = std::make_shared<CCircle>(pos, radius);
		if (params.size() > 4)
		{
			circle->SetLineColor(params[4]);
		}
		if (params.size() > 5)
		{
			circle->SetFillColor(params[5]);
		}
		m_shapes.push_back(circle);
	}
}

void CApp::AddRectangle(std::vector<std::string> const & params)
{
	if (params.size() >= 5)
	{
		double x = (isNumber(params[1]) ? ToNumber(params[1]) : 0);
		double y = (isNumber(params[2]) ? ToNumber(params[2]) : 0);
		double width = (isNumber(params[3]) ? ToNumber(params[3]) : 0);
		double height = (isNumber(params[4]) ? ToNumber(params[4]) : 0);
		Coordinate pos = { x, y };
		auto rectangle = std::make_shared<CRectangle >(pos, width, height);
		if (params.size() > 5)
		{
			rectangle->SetLineColor(params[5]);
		}
		if (params.size() > 6)
		{
			rectangle->SetFillColor(params[6]);
		}
		m_shapes.push_back(rectangle);
	}
}

void CApp::AddTriangle(std::vector<std::string> const & params)
{
	if (params.size() >= 7)
	{
		double fx = (isNumber(params[1]) ? ToNumber(params[1]) : 0);
		double fy = (isNumber(params[2]) ? ToNumber(params[2]) : 0);
		double sx = (isNumber(params[3]) ? ToNumber(params[3]) : 0);
		double sy = (isNumber(params[4]) ? ToNumber(params[4]) : 0);
		double tx = (isNumber(params[5]) ? ToNumber(params[5]) : 0);
		double ty = (isNumber(params[6]) ? ToNumber(params[6]) : 0);
		Coordinate fPos = { fx, fy };
		Coordinate sPos = { sx, sy };
		Coordinate tPos = { tx, ty };
		auto triangle = std::make_shared<CTriangle>(fPos, sPos, tPos);
		if (params.size() > 8)
		{
			triangle->SetLineColor(params[8]);
		}
		if (params.size() > 9)
		{
			triangle->SetFillColor(params[9]);
		}
		m_shapes.push_back(triangle);
	}
}

void CApp::PrintByPerimetr()
{
	std::vector<std::shared_ptr<IShape>> perimVector;
	for (auto &it : m_shapes)
	{
		for (auto it2 = perimVector.begin(); it2 <= perimVector.end(); ++it2)
		{
			if (it2 == perimVector.end() || it->GetShapePerimetr() <= it2->get()->GetShapePerimetr())
			{
				perimVector.insert(it2, it);
				break;
			}
		}
	}

	for (auto &it : perimVector)
	{
		std::cout << it->ShapeToString() << std::endl;
	}
}

void CApp::PrintByArea()
{
	std::vector<std::shared_ptr<IShape>> areaVector;
	for (auto &it : m_shapes)
	{
		for (auto it2 = areaVector.begin(); it2 <= areaVector.end(); ++it2)
		{
			if (it2 == areaVector.end() || it->GetShapeArea() <= it2->get()->GetShapeArea())
			{
				areaVector.insert(it2, it);
				break;
			}
		}
	}

	for (auto &it : areaVector)
	{
		std::cout << it->ShapeToString() << std::endl;
	}
}

bool CApp::isNumber(std::string const & str)
{
	return std::all_of(str.begin(), str.end(), [](auto &it) {return (it >= '0' && it <= '9'); });
}

size_t CApp::ToNumber(std::string const & str)
{
	std::istringstream ss(str);
	size_t num = 0;
	ss >> num;
	return num;
}
