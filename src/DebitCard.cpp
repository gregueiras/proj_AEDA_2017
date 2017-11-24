#include "DebitCard.h"

// Constructors/Destructors
//  

DebitCard::DebitCard (double value) : Payment::Payment(value), payment_id(newId()) {}

DebitCard::DebitCard (double value, bool due, Date due_date, Hour due_hour) : Payment::Payment(value, due, due_date, due_hour) {}

DebitCard::~DebitCard () { }

//  
// Methods
//  

const unsigned int DebitCard::newId() {
	const unsigned int newId = this->getNextId() * 10 + this->payment_id;
	this->incNextId();
	return newId;
}

std::string DebitCard::getPayType() {
	return "DebitCard";
}

// Accessor methods
//  


// Other methods
//  


