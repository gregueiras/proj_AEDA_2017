#include "Hour.h"

// Constructors/Destructors
//  

Hour::Hour() {
	initAttributes();
}

Hour::~Hour() {
}

//  
// Methods
//  

// Accessor methods
//  

// Other methods
//  

void Hour::initAttributes() {
}

unsigned int Hour::getHour() {
	return hour;
}

void Hour::setHour (unsigned int new_var)   {
    hour = new_var;
}


void Hour::setMinute (unsigned int new_var)   {
    minute = new_var;
}

unsigned int Hour::getMinute() {
	return minute;
}
