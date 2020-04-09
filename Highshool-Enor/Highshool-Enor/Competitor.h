#pragma once
#include <string>
#include <fstream>

enum Exception
{
	NoSuchFileExistsException
};

struct Competitor
{
	std::string name;
	int score;
};

class CompetitorEnumerator
{
private:
	std::ifstream _ifs;
	Competitor _cur;
	bool _end;
public:
	CompetitorEnumerator(const std::string& filename) throw (Exception);
	void first();
	void next();
	Competitor current() const;
	bool end() const;
};

