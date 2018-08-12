#include "painter.h"
#include "graph_object.h"
#include <iostream>

void Painter::draw(Circle* circle)
{
	std::cout << "Draw circle with centr at: " << circle->centr << ", radius: " << circle->radius << '\n';
}

void Painter::draw(Line* line)
{
	std::cout << "Draw line from: " << line->from << " to " << line->to << '\n';
}