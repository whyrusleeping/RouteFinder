#ifndef ROUTE_H
#define ROUTE_H

#include <vector>

using std::vector;

class route
{
public:
	route();

	bool addPoint(int n);
	bool Contains(int n);

	int operator[] (int val);

private:
	vector<int> pointsTraveled;
};

#endif