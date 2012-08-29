#include "pathfinder.h"

Pathfinder::Pathfinder()
{

}

Pathfinder::Pathfinder(string mapInfoFile)
{
	ifstream i(mapInfoFile);

	string line;
	
	getline(i, line);
	while(line != "!PATHS:")
	{
		
		getline(i, line);
	}

}