#include "graph_object.h"
#include "painter.h"
#include <iostream>

Circle::Circle(Coord centr_, size_t radius_) 
	: centr{ centr_ }, radius{ radius_ }
{ }

Circle::~Circle()
{
	std::cout << "dtor circle" << std::endl;
}

void Circle::drawBy(Painter* painter)
{
	painter->draw(this);
}

Line::Line(Coord from_, Coord to_, size_t width_) 
	: from{ from_ }, to{ to_ }, width{ width_ }
{ };

void Line::drawBy(Painter* painter)
{
	painter->draw(this);
}

Line::~Line()
{
	std::cout << "dtor line" << std::endl;
}

std::ostream& operator<<(std::ostream& os, Coord& coord)
{
	os << coord.x << "," << coord.y;
	return os;
}