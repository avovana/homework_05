#pragma once
#include <iostream>

class Coord
{
public:
	int x;
	int y;

	Coord(int x_, int y_) : x{ x_ }, y{ y_ }
	{ };
};

std::ostream& operator<<(std::ostream& os, Coord& coord);

class Painter;

class GraphObj
{
public:

	virtual void drawBy(Painter*) = 0;
	virtual ~GraphObj() = default;
};

class Circle : public GraphObj
{
public:
	Coord centr;
	size_t radius;

	Circle(Coord centr_, size_t radius_);
	~Circle();

	void drawBy(Painter*) override;
};

class Line : public GraphObj
{
public:
	Coord from;
	Coord to;
	size_t width;

	Line(Coord from_, Coord to_);
	~Line();

	void drawBy(Painter*) override;
};