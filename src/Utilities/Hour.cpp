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
	  o << h1.getHour() << ":" << h1.getMinute();
	  return o;
}

Hour::Hour(unsigned int h, unsigned int m, bool b) {
	this->hour = h;
	this->minute = m;
}
