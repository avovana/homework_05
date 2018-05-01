#include <vector>
#include "graph_editor.h"

int main()
{
	try
	{	
		GraphEditor editor("new project");
		editor.drawLine({1,3}, {2,4});
		editor.drawCircle({5, 7});
		editor.deleteLast();
		
		editor.exportToFile("filePath");
		editor.importFromFile("filePath");
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}    
}