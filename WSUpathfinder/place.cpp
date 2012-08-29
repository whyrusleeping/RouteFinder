#include "place.h"

place::place(string serialized)
{
	vector<string> parts;
	string temp = "";
	for(int i = 0; i < serialized.length(); i++)
	{
		if(serialized[i] != '|')
		{
			temp += serialized[i];
		}
		else
		{
			parts.push_back(temp);
			temp = "";
		}
	}
	parts.push_back(temp);
	ID = atoi(parts[0].c_str());
	Name = parts[1];
	coord = new coordinate(parts[2],parts[3]);
	Elevation = atoi(parts[4].c_str());

}

place::place( string name, string lat, string lon, int elevation, int nId )
{
	Name = name;
	coord = new coordinate(lat, lon);
	ID = nId;
	Elevation = elevation;
}

string place::Serialize()
{
	stringstream ss;
	ss << ID << "|" << Name << "|" << coord->lattitude << "|" << coord->longitude << "|" << Elevation;
	return ss.str();
}

void place::addPath(path *p)
{
	if(p->Aid == ID)
	{
		p->A = this;
		pathsToHere.push_back(p);
	}
	else if(p->Bid == ID)
	{
		p->B = this;
		pathsToHere.push_back(p);
	}
}

 double string_to_double( const std::string& s )
 {
   std::istringstream i(s);
   double x;
   if (!(i >> x))
     return 0;
   return x;
 } 