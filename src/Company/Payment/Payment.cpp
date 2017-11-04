#include "Payment.h"

unsigned int Payment::next_id = 1;

// Constructors/Destructors
//  

Payment::Payment (double value) {
	this->value = value;
}

Payment::~Payment () { }

//  
// Methods
//  

unsigned int Payment::getNextId() {
	return this->next_id;
}

void Payment::incNextId() {
	++this->next_id;
}

// Accessor methods
//  


// Other methods
//  


