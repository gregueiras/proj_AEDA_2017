#include "Delivery.h"

// Constructors/Destructors
//  

Delivery::Delivery () {
initAttributes();
}

Delivery::Delivery(Date start_date, Hour start_hour, Date end_date, Hour end_hour)
{
	this->start_date = start_date;
	this->start_hour = start_hour;
	this->end_date = end_date;
	this->end_hour = end_hour;
}

Delivery::~Delivery () { }

//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  

void Delivery::initAttributes () {
}

