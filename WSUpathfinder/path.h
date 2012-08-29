#ifndef PATH_H
#define PATH_H

#include "place.h"

class path
{
public:
	path();
	path(string serialized);

	string Serialize();

	double distance;
	int condition;
	int type;
	place *A;
	place *B;

	int Aid;
	int Bid;


};

#endif