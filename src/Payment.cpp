#include "Payment.h"

unsigned int Payment::next_id = 1;

// Constructors/Destructors
//  

Payment::Payment (double value) {
	this->value = value;
	this->due = false;

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

bool Payment::isDue() {
	return this->due;
}

void Payment::setDueDate(Date new_var) {
	this->due_date = new_var;
}

Date Payment::getDueDate() {
	return this->due_date;
}

void Payment::setDueHour(Hour new_var) {
	this->due_hour = new_var;
}

Hour Payment::getDueHour() {
	return this->due_hour;
}

// Accessor methods
//  


// Other methods
//  


