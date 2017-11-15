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

void Payment::setDue(bool new_var) {
	this->due = new_var;
}

string Payment::getDue() {
	return this->due;
}

// Accessor methods
//  


// Other methods
//  


