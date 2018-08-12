#pragma once

class Circle;
class Line;

class Painter
{
public:
	void draw(Circle *obj);
	void draw(Line *obj);

private:
	unsigned int color{0};
	unsigned int brushType{0};
	unsigned int brushWidth{1};
};