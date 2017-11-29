#include "BankTransfer.h"

// Constructors/Destructors
//  

BankTransfer::BankTransfer (double value) : Payment::Payment(value), payment_id(newId()) {}

BankTransfer::BankTransfer(double value, bool due, Date due_date, Hour due_hour) : Payment::Payment(value, due, due_date, due_hour) {}

BankTransfer::~BankTransfer () { }

//  
// Methods
//  

const unsigned int BankTransfer::newId() {
	const unsigned int newId = this->getNextId() * 10 + this->payment_id;
	this->incNextId();
	return newId;
}

std::string BankTransfer::getPayType() {
	return "BankTransfer";
}

// Accessor methods
//  


// Other methods
//  


