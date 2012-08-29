#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "place.h"
#include "path.h"
#include "route.h"
#include <fstream>
#include <iostream>

using std::ifstream;
using std::ofstream;

using std::cin;
using std::cout;

class Pathfinder
{
public:
	Pathfinder();
	Pathfinder(string mapInfoFile);

	void inputPlace();
	void inputPath();

	void Save(string filename);

	route ShortestRoute(int from, int to);

	vector<place*> places;
	vector<path*> paths;

private:

	place* placeWithID(int pid);
	int getNextId();

};

#endif