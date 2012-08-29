#ifndef COORDINATE_H
#define COORDINATE_H

#include <string>

using std::string;

class coordinate
{
public:
	coordinate(string lat, string lon);
	string lattitude;
	string longitude;


	coordinate & operator= (coordinate &rhs);
};

#endif 