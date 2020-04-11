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

#define NORMAL_MODE
#ifdef NORMAL_MODE

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

#else
#define CATCH_CONFIG_MAIN

#include "./Test/src/catch.hpp"

// BlackBox
TEST_CASE("t01_empty")
{
	Competitor c;
	CHECK_FALSE(first_search("./Test/BlackBox/t01_empty.txt", c));

	CHECK("" == second_search("./Test/BlackBox/t01_empty.txt").str());
}

TEST_CASE("t02_1line_2namePart_1sport_0score")
{
	Competitor c;
	CHECK(first_search("./Test/BlackBox/t02_1line_2namePart_1sport_0score.txt", c));
	CHECK(c.name == "Nagyon Péter");
	CHECK(c.schoolID == "1063Szinyei");
	CHECK(c.score == 0);
		
	CHECK("1063Szinyei school has scored 0 points\n" == second_search("./Test/BlackBox/t02_1line_2namePart_1sport_0score.txt").str());
}

TEST_CASE("t03_1line_2namePart_1sport")
{
	Competitor c;
	CHECK(first_search("./Test/BlackBox/t03_1line_2namePart_1sport.txt", c));
	CHECK(c.name == "Ügyes Péter");
	CHECK(c.schoolID == "1063Szinyei");
	CHECK(c.score == 8);

	CHECK("1063Szinyei school has scored 8 points\n" == second_search("./Test/BlackBox/t03_1line_2namePart_1sport.txt").str());
}

TEST_CASE("t04a_1line_2namePart_1+spoert")
{
	Competitor c;
	CHECK(first_search("./Test/BlackBox/t04a_1line_2namePart_1+spoert.txt", c));
	CHECK(c.name == "Nagyon Péter");
	CHECK(c.schoolID == "1063Szinyei");
	CHECK(c.score == 32);

	CHECK("1063Szinyei school has scored 32 points\n" == second_search("./Test/BlackBox/t04a_1line_2namePart_1+spoert.txt").str());
}

TEST_CASE("t04b_1line_2+namePart_1sport")
{
	Competitor c;
	CHECK(first_search("./Test/BlackBox/t04b_1line_2+namePart_1sport.txt", c));
	CHECK(c.name == "Nagyon Ügyes Péter");
	CHECK(c.schoolID == "1063Szinyei");
	CHECK(c.score == 8);

	CHECK("1063Szinyei school has scored 8 points\n" == second_search("./Test/BlackBox/t04b_1line_2+namePart_1sport.txt").str());
}

TEST_CASE("t05_t03_o_t04a_o_t04b")
{
	Competitor c;
	CHECK(first_search("./Test/BlackBox/t05_t03_o_t04a_o_t04b.txt", c));
	CHECK(c.name == "Nagyon Péter");
	CHECK(c.schoolID == "1063Szinyei");
	CHECK(c.score == 32);

	CHECK("1063Szinyei school has scored 48 points\n" == second_search("./Test/BlackBox/t05_t03_o_t04a_o_t04b.txt").str());
}

TEST_CASE("t06_combinated_multipleShool")
{
	Competitor c;
	CHECK(first_search("./Test/BlackBox/t06_combinated_multipleShool.txt", c));
	CHECK(c.name == "Valamilyen János");
	CHECK(c.schoolID == "3021GáborDénes");
	CHECK(c.score == 36);

	CHECK("1063Szinyei school has scored 32 points\n2144Kerepes school has scored 34 points\n3021GáborDénes school has scored 64 points\n" == second_search("./Test/BlackBox/t06_combinated_multipleShool.txt").str());
}

// WhiteBox
TEST_CASE("t07_uglyWhile")
{
	Competitor c;
	CHECK(first_search("./Test/WhiteBox/t07_uglyWhile.txt", c));
	CHECK(c.name == "Valamilyen János");
	CHECK(c.schoolID == "3021GáborDénes");
	CHECK(c.score == 36);

	CHECK("1063Szinyei school has scored 32 points\n2144Kerepes school has scored 34 points\n3021GáborDénes school has scored 36 points\n4021GáborDénes school has scored 28 points\n5268Izé school has scored 6 points\n6012JózsefAttila school has scored 12 points\n7123Ady school has scored 12 points\n8881 school has scored 10 points\n9354Iskola school has scored 4 points\n" == second_search("./Test/WhiteBox/t07_uglyWhile.txt").str());
}

TEST_CASE("t08_scoreCalculation_CriticalValues")
{
	Competitor c;
	CHECK(first_search("./Test/WhiteBox/t08_scoreCalculation_CriticalValues.txt", c));
	CHECK(c.name == "Nagyon Péter");
	CHECK(c.schoolID == "1063Szinyei");
	CHECK(c.score == 14);

	CHECK("1063Szinyei school has scored 14 points\n" == second_search("./Test/WhiteBox/t08_scoreCalculation_CriticalValues.txt").str());
}

#endif //NORMAL_MODE