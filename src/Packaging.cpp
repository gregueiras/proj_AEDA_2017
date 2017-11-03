#include "Packaging.h"

// Constructors/Destructors
//  

Packaging::Packaging () {
initAttributes();
}

Packaging::Packaging(Date start_date, Hour start_hour, Date end_date, Hour end_hour)
{
	this->start_date = start_date;
	this->start_hour = start_hour;
	this->end_date = end_date;
	this->end_hour = end_hour;
}
Packaging::~Packaging () { }

//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  

void Packaging::initAttributes () {
}

