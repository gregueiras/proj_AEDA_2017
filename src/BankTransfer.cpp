#include "BankTransfer.h"

// Constructors/Destructors
//  

BankTransfer::BankTransfer (double value) : Payment::Payment(value), payment_id(newId()) {}

BankTransfer::~BankTransfer () { }

//  
// Methods
//  

const unsigned int BankTransfer::newId() {
	const unsigned int newId = this->getNextId() * 10 + this->payment_id;
	this->incNextId();
	return newId;
}

// Accessor methods
//  


// Other methods
//  


