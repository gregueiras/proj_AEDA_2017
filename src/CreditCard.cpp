#include "CreditCard.h"

// Constructors/Destructors
//  

CreditCard::CreditCard (double value) : Payment::Payment(value), payment_id(newId()) {}

CreditCard::~CreditCard () { }

//  
// Methods
//  

const unsigned int CreditCard::newId() {
	const unsigned int newId = this->getNextId() * 10 + this->payment_id;
	this->incNextId();
	return newId;
}

// Accessor methods
//  


// Other methods
//  


