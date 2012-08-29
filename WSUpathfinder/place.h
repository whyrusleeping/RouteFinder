#ifndef PLACE_H
#define PLACE_H

#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "path.h"

using std::string;
using std::vector;
using std::stringstream;


class place
{
public:
	place(string serialized);
	string Serialize();
	void addPath(path *p);
	
	int ID;

private:
	string name;
	int elevation;
	double Lat;
	double Long;

	vector<path*> pathsToHere;
	


};

double string_to_double( const std::string& s );

#endif