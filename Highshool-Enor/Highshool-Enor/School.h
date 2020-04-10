#pragma once
#include <string>
#include <fstream>
#include "Competitor.h"

//enum Exception
//{
//	NoSuchFileExistsException
//};

struct School
{
	std::string schoolID;
	int score;
};

class SchoolEnumerator
{
private:
	CompetitorEnumerator _competitorEnumerator;
	School _cur;
	bool _end;
public:
	SchoolEnumerator(const std::string& filename) throw (Exception);
	void first();
	void next();
	School current() const;
	bool end() const;
};
