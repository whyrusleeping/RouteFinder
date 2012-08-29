#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "place.h"
#include "path.h"
#include <fstream>
#include <iostream>

using std::ifstream;

class Pathfinder
{
public:
	Pathfinder();
	Pathfinder(string mapInfoFile);


private:
	vector<place*> places;
	vector<path*> paths;


};

#endif