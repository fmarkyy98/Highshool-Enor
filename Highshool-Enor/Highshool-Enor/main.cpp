#include <iostream>
#include <sstream>
#include "Competitor.h"
#include "School.h"

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

stringstream second_search(const string& filename)
{
	stringstream result;
	SchoolEnumerator schoolEnor(filename);
	for (schoolEnor.first(); !schoolEnor.end(); schoolEnor.next())
	{
		result << schoolEnor.current().schoolID << " school has scored " << schoolEnor.current().score << " points" << endl;
	}
	return result;
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
		if (first_search(filename, max))
		{
			cout << max.name << " has scored " << max.score << " points " << endl;
		}
		else
		{
			cout << "Empty file.\n";
		}
	}
	catch (Exception ex)
	{
		cerr << "Wrong path." << endl;
	}

	cout << "Second task\n";

	try
	{
		cout << second_search(filename).str();
	}
	catch (Exception ex)
	{
		cerr << "Can't find the input file:" << filename << endl;
	}
	return 0;

	std::cout << "Hello World!\n";
	return 0;
}
