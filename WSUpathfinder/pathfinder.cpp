#include "pathfinder.h"

Pathfinder::Pathfinder()
{

}

Pathfinder::Pathfinder(string mapInfoFile)
{
	ifstream i(mapInfoFile);

	string line;
	place *pl = nullptr;
	
	getline(i, line);
	while(line != "PATHS:")
	{
		pl = new place(line);
		places.push_back(pl);
		getline(i, line);
	}

	getline(i, line);

	path *nPath = nullptr;

	while(i.good())
	{
		nPath = new path(line);
		paths.push_back(nPath);
		placeWithID(nPath->Aid)->addPath(nPath);
		placeWithID(nPath->Bid)->addPath(nPath);
		getline(i, line);
	}
}

place* Pathfinder::placeWithID( int pid )
{
	for(int i = 0; i < places.size(); i++)
	{
		if(places[i]->ID == pid)
		{
			return places[i];
		}
	}
	return nullptr;
}

void Pathfinder::Save( string filename )
{
	ofstream o(filename);
	for(int i = 0; i < places.size(); i++)
	{
		o << places[i]->Serialize() << "\n";
	}
	o << "PATHS:\n";
	for(int i = 0; i < paths.size(); i++)
	{
		o << paths[i]->Serialize() << "\n";
	}
}

void Pathfinder::inputPlace()
{
	string name;
	int id;
	string longitude;
	string lattitude;
	int elevation;
	flushall();
	cout << "Enter a new place!\nName:";
	getline(cin, name);
	cout << "Longitude";
	getline(cin, longitude);
	cout << "Lattitude:";
	getline(cin, lattitude);
	cout << "Elevation (feet):";
	cin >> elevation;
	
	place *p = new place(name, lattitude, longitude, elevation, getNextId());

	places.push_back(p);
}

int Pathfinder::getNextId()
{
	int maxID = -1;
	for(int i = 0; i < places.size(); i++)
	{
		if(places[i]->ID > maxID)
		{
			maxID = places[i]->ID;
		}
	}
	return maxID + 1;
}

void Pathfinder::inputPath()
{
	path *p = new path();
	cout << "Enter a new path!\nfrom (place ID):";
	cin >> p->Aid;
	cout << "To:";
	cin >> p->Bid;
	cout << "Distance:";
	cin >> p->distance;
	//condition
	//type
	paths.push_back(p);
	placeWithID(p->Aid)->addPath(p);
	placeWithID(p->Bid)->addPath(p);
}

