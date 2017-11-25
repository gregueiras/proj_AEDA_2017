#include "EOMPayment.h"

// Constructors/Destructors
//  
EOMPayment::EOMPayment() {
	this->due = false;
}

EOMPayment::EOMPayment(bool due, Date due_date, Hour due_hour) {
	this->due_date = due_date;
	this->due_hour = due_hour;
	this->due = due;
}

EOMPayment::~EOMPayment () { }

//  
// Methods
//  

void EOMPayment::setDue(bool new_var) {
	this->due = new_var;
}

bool EOMPayment::getDue() {
	return this->due;
}

void EOMPayment::setDueDate(Date new_var) {
	this->due_date = new_var;
}

Date EOMPayment::getDueDate() {
	return this->due_date;
}

void EOMPayment::setDueHour(Hour new_var) {
	this->due_hour = new_var;
}

Hour EOMPayment::getDueHour() {
	return this->due_hour;
}

string EOMPayment::getEOMPaymentToWrite()
{
	string ret = "";

	ret += to_string((int)(this->due)) + "\n" + this->due_date.toStr() + "\n" + this->due_hour.toStr() + "\n";

	return ret;
}

// Accessor methods
//  


// Other methods
//  


