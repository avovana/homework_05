#pragma once

#include "object.h"
#include "view.h"
#include "model.h"

#include <vector>
#include <string>

class GraphEditor
{
    public:
    explicit GraphEditor(const std::string & name_) : projectName{ name_ }
    {
        model = new MyModel();
        canvas = new MyView();
        canvas->setModel(model);
    }

    ~GraphEditor()
    {
        delete model;
        delete canvas;
    }

    void importFromFile(std::string filePath)
    {

    }

    void exportToFile(std::string filePath)
    {

    }

    void drawLine(Coord from, Coord to)
    {
        model->addElement(std::make_unique<Line>(from, to, 555));
    }

    void drawCircle(Coord coord, size_t radius)
    {
        model->addElement(std::make_unique<Circle>(coord, radius));
    }

    void deleteLast()
    {
        model->deleteLast();
    }

private:
    std::string projectName{""};
    MyView* canvas;
    AbstractModel* model;

    GraphEditor (const GraphEditor&) = delete;
    GraphEditor& operator=(const GraphEditor&) = delete;
};
