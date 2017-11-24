#include "Payment.h"

unsigned int Payment::next_id = 1;

// Constructors/Destructors
//  

Payment::Payment (double value) {
	this->value = value;
	this->due = false;

}

Payment::Payment(double value, bool due, Date due_date, Hour due_hour) {
	this->value = value;
	this->due = due;
	this->due_date = due_date;
	this->due_hour = due_hour;
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

bool Payment::getDue() {
	return this->due;
}

void Payment::setDueDate(Date new_var) {
	this->due_date = new_var;
}

Date Payment::getDueDate() {
	return this->due_date;
}

double Payment::getValue()
{
	return this->value;
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


