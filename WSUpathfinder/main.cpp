#include "pathfinder.h"

int main()
{
	Pathfinder *p = new Pathfinder("places.ppf");

	int choice = 0;

	do 
	{
		cout << "1 place\n2 path\n3 print\n4 exit\n>";
		cin >> choice;
		if(choice == 1)
			p->inputPlace();
		if(choice == 2)
			p->inputPath();
		if(choice == 3)
		{
			cout << "Places:\n";
			for(int i = 0; i < p->places.size(); i++)
			{
				cout << p->places[i]->Serialize() << "\n";
			}
			cout << "Paths:\n";
			for(int i = 0; i < p->paths.size(); i++)
			{
				cout << p->paths[i]->Serialize() << "\n";
			}

		}
	} while (choice != 4);
	p->Save("places.ppf");
	return 0;

}