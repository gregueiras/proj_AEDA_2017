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
	else
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
	if (d1.getDay() < 10)
		o << "0" << d1.getDay() << "/";
	else
		o << d1.getDay() << "/";
	if (d1.getMonth() < 10)
		o << "0" << d1.getMonth() << "/";
	else
		o << d1.getMonth() << "/";
	if (d1.getYear() < 10)
		o << "000" << d1.getYear();
	else if (d1.getYear() < 100)
		o << "00" << d1.getYear();
	else if (d1.getYear() < 1000)
		o << "0" << d1.getYear();
	else
		o << d1.getYear();
	return o;
}

unsigned int operator -(const Date& d1, const Date& d2) {
	unsigned int i = 0;

	if (d1 == d2)
		return i;
	//	else if (d1.getMonth() == d2.g)
	//	{
	//		if (d1.getYear() != d2.getYear())
	//			i += abs((d1.getYear() - d2.getYear()) - 1)*365;
	//
	//		if (d1.getMonth() != d2.getMonth())
	//			i += abs((d1.getMonth() - d2.getMonth()) - 1)*30;
	//
	//		if (d1.getDay() != d2.getDay())
	//		i += abs((d1.getDay() - d2.getDay()));
	//	}
	else
	{
		i = abs(rdn(d1) - rdn(d2));
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

bool operator <=(const Date& d1, const Date& d2) {
	return (d1 < d2 || d1 == d2);
}

/* Rata Die day one is 0001-01-01 */
int rdn(Date d1)
{
	int year = d1.getYear(), month = d1.getMonth();
	if (month < 3)
		{
			year--;
			month += 12;
		}
	return d1.getDay() + (153*month - 457)/5 + 365*year + year/4 - year/100 + year/400 - 306;
}

std::string Date::toStr() const{
	std::stringstream s1;
	s1 << *this;
	return s1.str();
}
