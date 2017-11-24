#include "CreditCard.h"

// Constructors/Destructors
//  

CreditCard::CreditCard (double value) : Payment::Payment(value), payment_id(newId()) {}

CreditCard::CreditCard (double value, bool due, Date due_date, Hour due_hour) : Payment::Payment(value, due, due_date, due_hour) {}

CreditCard::~CreditCard () { }

//  
// Methods
//  

const unsigned int CreditCard::newId() {
	const unsigned int newId = this->getNextId() * 10 + this->payment_id;
	this->incNextId();
	return newId;
}

std::string CreditCard::getPayType() {
	return "CreditCard";
}

// Accessor methods
//  


// Other methods
//  


