#include <queue>
#include "graph_editor.h"

int main()
{
	try
	{
		GraphEditor editor("new project");

		std::queue<Event> events({ Event::drawLine, Event::drawCircle, Event::deleteLast, Event::importFromFile, Event::exportToFile, Event::quit });

		editor.proceed(std::move(events));
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}