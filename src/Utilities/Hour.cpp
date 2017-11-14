#include "Hour.h"

// Constructors/Destructors
//  

Hour::Hour(unsigned int h, unsigned int m)
{
	if ( h > 24 || h < 0)
		throw HourInvalidHour(h);

	if ( m > 60 || m < 0)
		throw HourInvalidMinute(m);



	this->hour = h;
	this->minute = m;
}

Hour::Hour () {
	initAttributes();
}

Hour::~Hour () { }

//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  

void Hour::initAttributes () {
	this->hour = 0;
	this->minute = 0;
}

std::ostream & operator<< (std::ostream &o, const Hour& h1)
{
	if (h1.getHour() < 10)
		o << "0";
	o << h1.getHour() << ":";

	if (h1.getMinute() < 10)
		o << "0";
	o << h1.getMinute();

	return o;
}

Hour::Hour(unsigned int h, unsigned int m, bool b) {
	this->hour = h;
	this->minute = m;
}

Hour operator +(const Hour& h1, const Hour& h2) {
	unsigned int min = h1.getMinute() + h2.getMinute();
	Hour hf;
	hf.setHour( (h1.getHour() + h2.getHour() + (min/60)) % 24);
	hf.setMinute(min % 60);

	return hf;
}

Hour operator +(const Hour& h1, const unsigned int add) {
	Hour hf;
	hf.setHour( (h1.getHour() + add) % 24);

	return hf;

}

Hour operator +(const unsigned int add, const Hour& h1) {
	return h1 + add;
}
