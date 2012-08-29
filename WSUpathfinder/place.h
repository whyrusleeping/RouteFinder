#ifndef PLACE_H
#define PLACE_H

#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "path.h"
#include "coordinate.h"

using std::string;
using std::vector;
using std::stringstream;

class path;

class place
{
public:
	place(string serialized);
	place(string name, string lat, string lon, int elevation, int nId);
	string Serialize();
	void addPath(path *p);
	
	int ID;

private:
	string Name;
	int Elevation;
	coordinate *coord;

	vector<path*> pathsToHere;
};

double string_to_double( const std::string& s );

#endif