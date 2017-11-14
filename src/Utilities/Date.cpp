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

unsigned int operator -(const Date& d1, const Date& d2) {
	unsigned int i = 0;

	if (d1 == d2)
		return i;
	else
	{
		i += abs((d1.getYear() - d2.getYear()))*365;
		i += abs((d1.getMonth() - d2.getMonth()))*30;
		i += abs((d1.getDay() - d2.getDay()));
	}

	return i;
}

Date operator +(const Date& d1, const Hour& h1) {
	unsigned int hrs = h1.getHour();
	Date d2 = d1;

	unsigned int days = hrs / 24;
	return d2 + days;
}

Date operator +(const Hour& h1, const Date& d1) {
	return d1 + h1;
}

Date operator +(const unsigned int days, const Date& d1) {
	return d1 + days;
}

Date operator +(const Date& d1, const unsigned int days) {
	unsigned int d_new = d1.getDay() + days;

	Date d2 = d1;
	//	d2.setDay(d_new);
	//
	//	return d2;
	while(1)
	{
		unsigned int m = d2.getMonth(), y = d2.getYear();

		if (m == 4 || m == 6 || m == 9 || m == 11)
		{
			if (d_new > 30)
			{
				d_new -= 30;
				d2.setDay(1);
				d2.setMonth(d2.getMonth()+1);

			} else
			{

				d2.setDay(d_new);
				return d2;
			}

		} else if (m == 2)
		{
			if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
			{
				if (d_new > 28)
				{
					d_new -= 28;
					d2.setDay(1);
					d2.setMonth(d2.getMonth()+1);

				}else
				{
					d2.setDay(d_new);
					return d2;
				}
			} else
				if (d_new > 29)
				{
					d_new -= 28;
					d2.setDay(1);
					d2.setMonth(d2.getMonth()+1);

				} else
				{
					d2.setDay(d_new);
					return d2;
				}
		} else
			if (d_new > 31)
			{
				d_new -= 31; //TODO
				d2.setDay(1);
				d2.setMonth(d2.getMonth()+1);

			} else
			{
				d2.setDay(d_new);
				return d2;
			}
	}

}
