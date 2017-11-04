#include "Date.h"

// Constructors/Destructors
//  

Date::Date () {
	initAttributes();
}

Date::Date(unsigned int d, unsigned int m, unsigned int y)
{
	if ((m < 0) || (m > 12))
		throw DateInvalidMonth(m);

	if (y < 0)
		throw DateInvalidYear(y);

	if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		if (d > 30)
			throw DateInvalidDay(d);
	} else if (m == 2)
	{
		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		{
			if (d > 28)
				throw DateInvalidDay(d);
		} else
			if (d > 29)
				throw DateInvalidDay(d);
	} else
		if (d > 31)
			throw DateInvalidDay(d);




	this->day = d;
	this->month = m;
	this->year = y;
}

Date::~Date () { }

//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  

void Date::initAttributes () {
	this->day = 0;
	this->month = 0;
	this->year = 0;
}

bool operator== (const Date& d1, const Date& d2)
{
	if ((d1.getYear() != d2.getYear()) || (d1.getMonth() != d2.getMonth()) || (d1.getDay() != d2.getDay()))
		return false;
	else
		return true;
}

bool operator< (const Date& d1, const Date& d2)
{
	if (d1.getYear() < d2.getYear())
		return true;
	else if (d1.getYear() > d2.getYear())
		return false;
	else if (d1.getMonth() < d2.getMonth())
		return true;
	else if (d1.getMonth() > d2.getMonth())
		return false;
	else if (d1.getDay() < d2.getDay())
		return true;
	else if (d1.getDay() > d2.getDay())
		return false;
	else if (d1 == d2)
		return false;
}

bool operator> (const Date& d1, const Date& d2)
{
	if (d1 < d2)
		return false;
	else if (d1 == d2)
		return false;

	return true;
}

std::ostream & operator<< (std::ostream &o, const Date& d1)
{
	  o << d1.getDay() << "/" << d1.getMonth() << "/" << d1.getYear();
	  return o;
}
