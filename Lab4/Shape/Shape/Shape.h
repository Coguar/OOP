#pragma once

typedef std::pair<float, float> Ñoordinate;
typedef std::pair<float, float> Size;
typedef std::string StrColor;

struct IShape
{
	virtual float GetArea() = 0;
	virtual float GetPerimetr() = 0;
	virtual std::string StringRepresentation() = 0;
	void SetLineColor(std::string const& color);
	std::string GetColor();
	std::string  m_lineColor;
};

struct ISolidShape : public IShape
{
	void SetFillColor(std::string const& color);
	std::string m_fillColor;
};

class CPoint : public IShape
{
public:
	CPoint(float const& x, float const& y, StrColor const& color);
	std::string StringRepresentation() override;
	float GetArea() override { return 0; };
	float GetPerimetr() override { return 0; };

	std::pair<float, float> GetPosition();
	std::string GetPointPosAsString();
	const float operator-(const CPoint& rv) const;

private:
	float m_xPos;
	float m_yPos;
};

class CLineSegment : public IShape
{
public:
	CLineSegment(Ñoordinate const& beginPos, Ñoordinate const& endPos, StrColor const& color);

	std::string StringRepresentation() override;
	float GetArea() override { return 0; };
	float GetPerimetr() override;

private:

	std::unique_ptr<CPoint> m_beginPoint;
	std::unique_ptr<CPoint> m_endPoint;
};

class CRectangle : public ISolidShape
{
public:
	CRectangle(Ñoordinate const& pos, Size const& size, StrColor const& fillColor, StrColor const& lineColor);
	std::string StringRepresentation() override;
	float GetArea() override;
	float GetPerimetr() override;
private:
	float m_width;
	float m_height;
	std::unique_ptr<CPoint> m_pos;

};

class CTriangle : public ISolidShape
{
public:
	CTriangle(Ñoordinate const& pos1, Ñoordinate const& pos2, Ñoordinate const& pos3, StrColor const & fillColor, StrColor const & lineColor);
	std::string StringRepresentation() override;
	float GetArea() override;
	float GetPerimetr() override;
private:
	std::unique_ptr<CPoint> m_pick1;
	std::unique_ptr<CPoint> m_pick2;
	std::unique_ptr<CPoint> m_pick3;

	std::unique_ptr<CLineSegment> m_side1;
	std::unique_ptr<CLineSegment> m_side2;
	std::unique_ptr<CLineSegment> m_side3;
};

class CCircle : public ISolidShape
{
public:
	CCircle(Ñoordinate const& pos, float const& radius, StrColor const & fillColor, StrColor const & lineColor);
	std::string StringRepresentation() override;
	float GetArea() override;
	float GetPerimetr() override;
private:
	std::unique_ptr<CPoint> m_pos;
	float m_radius;
};
