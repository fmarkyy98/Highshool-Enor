#include <iostream>
#include "Competitor.h"

using namespace std;

bool first_search(const string& filename, Competitor& competitor)
{
	int max = -1;
	CompetitorEnumerator compEnor(filename);
	bool isEmptyFile = true;
	for (compEnor.first(); !compEnor.end(); compEnor.next()) {
		if (isEmptyFile)
		{
			isEmptyFile = false;
		}
		if (max < compEnor.current().score)
		{
			max = compEnor.current().score;
			competitor = compEnor.current();
		}
	}
	return !isEmptyFile;
}

int main()
{
	string filename;
	cout << "Enter the name of the input file:";
	cin >> filename;
	cout << "First  task" << endl;
	try
	{
		Competitor max;
		if (first_search(filename, max)) {
			cout << max.name << " has scored " << max.score << " points " << endl;
		}
		else {
			cout << "Empty file.\n";
		}
	}
	catch (Exception ex)
	{
		cerr << "Wrong path." << endl;
	}

	std::cout << "Hello World!\n";
	return 0;
}
