#include <string>
#include <sstream>
#include <fstream>
#include "Competitor.h"

CompetitorEnumerator::CompetitorEnumerator(const std::string& filename)
{
	this->_ifs.open(filename);
	if (this->_ifs.fail()) throw NoSuchFileExistsException;
}
void CompetitorEnumerator::first()
{
	this->next();
}
void CompetitorEnumerator::next()
{
	std::string line;
	getline(this->_ifs, line);
	if (!(this->_end = this->_ifs.fail()))
	{
		std::string transfer[2];
		std::string garbage;
		std::stringstream nameSs;
		std::istringstream iss(line);
		iss >> transfer[0] >> transfer[1];
		nameSs << transfer[0] << " " << transfer[1];
		while (
			iss.str()[nameSs.str().length() + 1] != '1' &&
			iss.str()[nameSs.str().length() + 1] != '2' &&
			iss.str()[nameSs.str().length() + 1] != '3' &&
			iss.str()[nameSs.str().length() + 1] != '4' &&
			iss.str()[nameSs.str().length() + 1] != '5' &&
			iss.str()[nameSs.str().length() + 1] != '6' &&
			iss.str()[nameSs.str().length() + 1] != '7' &&
			iss.str()[nameSs.str().length() + 1] != '8' &&
			iss.str()[nameSs.str().length() + 1] != '9')
		{
			iss >> transfer[0];
			nameSs << " " << transfer[0];
		}
		this->_cur.name = nameSs.str();
		iss >> this->_cur.schoolID;
		int placement;
		this->_cur.score = 0;
		iss >> garbage >> placement;
		while (!iss.fail())
		{
			this->_cur.score += 0 < placement && placement < 7 ? (7 - placement) * 2 : 0;
			iss >> transfer[0] >> placement;
		}
	}
}
Competitor CompetitorEnumerator::current() const
{
	return this->_cur;
}
bool CompetitorEnumerator::end() const
{
	return this->_end;
}