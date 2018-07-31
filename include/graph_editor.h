#pragma once

#include "object.h"
#include "view.h"
#include "model.h"

#include <vector>
#include <string>

enum class Event {drawLine, drawCircle, deleteLast, importFromFile, exportToFile, quit};

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

    void proceed(std::queue<Event> events)
    {
        bool quit{ false };

        while (!events.empty() && !quit)
        {
            auto event = events.front();
            events.pop();
            std::cout << "Command" << '\n';

            switch (event)
            {
                case Event::drawLine:
                    drawLine({ 1,3 }, { 2,4 });
                    break;

                case Event::drawCircle:
                    drawCircle({ 5, 7 }, 8);
                    break;

                case Event::deleteLast:
                    deleteLast();
                    break;

                case Event::importFromFile:
                    importFromFile("filePath");
                    break;

                case Event::exportToFile:
                    exportToFile("filePath");
                    break;

                case Event::quit:
                    quit = true;
                    break;

                default:
                    break;
            }
        }

    }

    private:
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

    std::string projectName{""};
    MyView* canvas;
    AbstractModel* model;

    GraphEditor (const GraphEditor&) = delete;
    GraphEditor& operator=(const GraphEditor&) = delete;
};
