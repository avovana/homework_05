#pragma once

#include <string>
#include <memory>

class Canvas 
{
public:
    Canvas() = default;   
    
    void drawLine(Coord from, Coord to)
    {
        objects.push_back(std::make_unique<Line>(from, to, brushWidth));
        objects.back()->draw();
    }
    
    void drawCircle(Coord radius)
    {
        objects.push_back(std::make_unique<Circle>(radius, brushWidth));
        objects.back()->draw();        
    }
    
    void deleteLast()
    {
        if(objects.empty())
            return;
        
        objects.pop_back();
    }
    
    void exportToFile(std::string /*filePath*/)
    {
    
    }
    void importFromFile(std::string /*filePath*/)
    {
    
    }
    
private:
    std::vector< std::unique_ptr<GraphObj> > objects;
    size_t brushWidth{1};   
};