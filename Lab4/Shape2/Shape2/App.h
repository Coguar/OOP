#pragma once
#include "Shapes.h"

class CApp
{
public:
	CApp();
	~CApp();
	void AddShape(std::string const& command);
	void PrintStats();
	size_t GetShapesCount();
private:
	std::vector<std::string> ParseCommand(std::string const& commandLine);
	void RecognizeCommand(std::vector<std::string> const& commandsElement);
	void AddPoint(std::vector<std::string> const& params);
	void AddLine(std::vector<std::string> const& params);
	void AddCircle(std::vector<std::string> const& params);
	void AddRectangle(std::vector<std::string> const& params);
	void AddTriangle(std::vector<std::string> const& params);

	void PrintByPerimetr();
	void CApp::PrintByArea();

	bool isNumber(std::string const& str);
	size_t ToNumber(std::string const& str);

	std::vector<std::shared_ptr<IShape>> m_shapes;

};

