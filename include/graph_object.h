#pragma once

#include <iostream>

class Coord
{
private:
    int x;
    int y;
    
public:
    Coord(int x_, int y_) : x{x_}, y{y_}
    { };
};

class GraphObj
{
  public:
  
    virtual void draw() const = 0;
    virtual ~GraphObj() = default;
};

class Circle : public GraphObj 
{
    Coord centr;
    size_t radius;
    
    public:
  
    Circle(Coord centr_, size_t radius_) : centr{centr_}, radius{radius_}
    { }
    
    ~Circle() override
    {
        std::cout << "dtor circle" << std::endl;
    }
    
    virtual void draw() const override
    {
        std::cout << "draw circle" << std::endl;
    }
};

class Line : public GraphObj 
{
    Coord from;
    Coord to;
    size_t width;
    
  public:
  
    Line(Coord from_, Coord to_, size_t width_) : from{from_}, to{to_}, width{width_}
    { };
  
    ~Line() override
    {
        std::cout << "dtor line" << std::endl;
    }
    
    virtual void draw() const override
    {
        std::cout << "draw line" << std::endl;
    }
};