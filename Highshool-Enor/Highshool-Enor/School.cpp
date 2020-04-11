#include <string>
#include <sstream>
#include <fstream>
#include "School.h"

SchoolEnumerator::SchoolEnumerator(const std::string& filename) : _compEnor(filename) { }

void SchoolEnumerator::first()
{
	this->_compEnor.first();
	this->next();
}
void SchoolEnumerator::next()
{
	if (!(this->_end = this->_compEnor.end()))
	{
		this->_cur.schoolID = this->_compEnor.current().schoolID;
		this->_cur.score = 0;
		while (!this->_compEnor.end() && this->_compEnor.current().schoolID == this->_cur.schoolID) {
			this->_cur.score += this->_compEnor.current().score;
			this->_compEnor.next();
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