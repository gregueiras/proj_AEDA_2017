#include "EOMPayment.h"

// Constructors/Destructors
//  

EOMPayment::EOMPayment (double value) : Payment::Payment(value), payment_id(newId()) {}

EOMPayment::EOMPayment(double value, bool due, Date due_date, Hour due_hour) : Payment::Payment(value, due, due_date, due_hour) {}

EOMPayment::~EOMPayment () { }

//  
// Methods
//  

const unsigned int EOMPayment::newId() {
	const unsigned int newId = this->getNextId() * 10 + this->payment_id;
	this->incNextId();
	return newId;
}

std::string EOMPayment::getPayType() {
	return "EOMPayment";
}

// Accessor methods
//  


// Other methods
//  


