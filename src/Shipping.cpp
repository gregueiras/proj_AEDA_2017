#include "Shipping.h"

// Constructors/Destructors
//  

Shipping::Shipping () {
initAttributes();
}

Shipping::Shipping(Date start_date, Hour start_hour, Date end_date, Hour end_hour)
{
	this->dispatch_date = start_date;
	this->dispatch_hour = start_hour;
	this->arrival_date = end_date;
	this->arrival_hour = end_hour;
}

Shipping::~Shipping () { }

//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  

void Shipping::initAttributes () {
}

