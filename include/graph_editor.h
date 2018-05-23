#pragma once

#include <vector>
#include <string>

#include "graph_object.h"
#include "canvas.h"

class GraphEditor
{
public:
    explicit GraphEditor (const std::string & name_) : projectName{name_}
    { }

    void importFromFile(std::string filePath)
    {
        canvas.importFromFile(filePath);
    }

    void exportToFile(std::string filePath)
    {
        canvas.exportToFile(filePath);
    }

    void drawLine(Coord from, Coord to)
    {
        canvas.drawLine(from, to);
    }

    void drawCircle(Coord coord, size_t radius)
    {
        canvas.drawCircle(coord, radius);
    }

    void deleteLast()
    {
        canvas.deleteLast();
    }
    
private:
    std::string projectName{""};
    Canvas canvas;
    
    GraphEditor (const GraphEditor&) = delete;
    GraphEditor& operator=(const GraphEditor&) = delete;
};
