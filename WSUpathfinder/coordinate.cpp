#include "coordinate.h"

coordinate::coordinate( string lat, string lon )
{
	lattitude = lat;
	longitude = lon;
}

coordinate & coordinate::operator=( coordinate &rhs )
{
	lattitude = rhs.lattitude;
	longitude = rhs.longitude;
	return *this;
}
