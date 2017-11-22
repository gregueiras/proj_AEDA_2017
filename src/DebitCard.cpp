#include "DebitCard.h"

// Constructors/Destructors
//  

DebitCard::DebitCard (double value) : Payment::Payment(value), payment_id(newId()) {}

DebitCard::~DebitCard () { }

//  
// Methods
//  

const unsigned int DebitCard::newId() {
	const unsigned int newId = this->getNextId() * 10 + this->payment_id;
	this->incNextId();
	return newId;
}

// Accessor methods
//  


// Other methods
//  


