#include "route.h"

route::route()
{

}

bool route::addPoint(int n)
{
	bool contains = false;
	for(int i = 0; i < pointsTraveled.size() && !contains; i++)
	{
		contains |= pointsTraveled[i] == n;
	}
	if(!contains)
	{
		pointsTraveled.push_back(n);
		return true;
	}

	return false;
}

bool route::Contains( int n )
{
	bool contains = false;
	for(int i = 0; i < pointsTraveled.size() && !contains; i++)
	{
		contains |= pointsTraveled[i] == n;
	}
	return contains;
}

int route::operator[]( int val )
{
	return pointsTraveled[val];
}
