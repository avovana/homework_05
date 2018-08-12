#pragma once

#include "graph_object.h"
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
                    model->addElement(std::make_unique<Line>(Coord{1,1}, Coord{2,2}, 555));
                    break;

                case Event::drawCircle:
                    model->addElement(std::make_unique<Circle>(Coord{5,5}, 5));
                    break;

                case Event::deleteLast:
                    model->deleteLast();
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

    std::string projectName{""};
    MyView* canvas;
    AbstractModel* model;

    GraphEditor (const GraphEditor&) = delete;
    GraphEditor& operator=(const GraphEditor&) = delete;
};
