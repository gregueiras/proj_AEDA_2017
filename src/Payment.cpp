#include "Payment.h"

unsigned int Payment::next_id = 1;

// Constructors/Destructors
//  

Payment::Payment(unsigned int set_id) : id(set_id) {}

Payment::Payment(double value, string name) : id(next_id++) {
	this->name = name;
	this->value = value;
	this->due = false;

}

Payment::Payment(double value, string name, bool due, Date due_date, Hour due_hour) : id(next_id++) {
	this->name = name;
	this->value = value;
	this->due = due;
	this->due_date = due_date;
	this->due_hour = due_hour;
}

Payment::~Payment() { }

//  
// Methods
//  

bool Payment::operator<(const Payment & p1) const
{
	if (name == p1.name) {
		if(this->due_date == p1.due_date)
			return (this->due_hour < p1.due_hour);
		else
			return (this->due_date < p1.due_date);
	}	
	else
		return (name < p1.name);
}

bool Payment::operator==(const Payment & p1) const
{
	return (this->id == p1.id);
}

string Payment::getClientName() {
	return this->name;
}

unsigned int Payment::getId() const
{
	return this->id;
}

unsigned int Payment::getNextId() const{
	return this->next_id;
}

void Payment::setDue(bool new_var) {
	this->due = new_var;
}

bool Payment::getDue() const{
	return this->due;
}

void Payment::setDueDate(Date new_var) {
	this->due_date = new_var;
}

Date Payment::getDueDate() const{
	return this->due_date;
}

double Payment::getValue()
{
	return this->value;
}

void Payment::setDueHour(Hour new_var) {
	this->due_hour = new_var;
}

Hour Payment::getDueHour() const{
	return this->due_hour;
}

// Accessor methods
//  


// Other methods
//  


