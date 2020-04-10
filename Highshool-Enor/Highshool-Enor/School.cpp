#include <string>
#include <sstream>
#include <fstream>
#include "School.h"

SchoolEnumerator::SchoolEnumerator(const std::string& filename) : _competitorEnumerator(filename) { }

void SchoolEnumerator::first()
{
	this->_competitorEnumerator.first();
	this->next();
}
void SchoolEnumerator::next()
{
	if (!(this->_end = this->_competitorEnumerator.end()))
	{
		this->_cur.schoolID = this->_competitorEnumerator.current().schoolID;
		this->_cur.score = 0;
		while (!this->_competitorEnumerator.end() && this->_competitorEnumerator.current().schoolID == this->_cur.schoolID) {
			this->_cur.score += this->_competitorEnumerator.current().score;
			this->_competitorEnumerator.next();
		}
	}
}
School SchoolEnumerator::current() const
{
	return this->_cur;
}
bool SchoolEnumerator::end() const
{
	return this->_end;
}