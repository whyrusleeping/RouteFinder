#include "path.h"

path::path()
{

}

path::path(string serialized)
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

	Aid = atoi(parts[0].c_str());
	Bid = atoi(parts[1].c_str());
	distance = string_to_double(parts[2]);
	condition = atoi(parts[3].c_str());
	type = atoi(parts[4].c_str());
}

string path::Serialize()
{
	stringstream ss;
	ss << A->ID << "|" << B->ID << "|" << distance << "|" << condition << "|" << type;
	return ss.str();
}

