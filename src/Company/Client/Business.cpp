#include "Business.h"

// Constructors/Destructors
//  

Business::Business (string name, Address address, unsigned int nif, string passwd) : Client::Client(name, address, nif, newId(), passwd) {}

Business::~Business () { }

//  
// Methods
//  
const unsigned int Business::newId() {
//	const unsigned int newId = this->getNextId() * 10 + this->client_id;
	this->incNextId();
	return newId;
}

bool Business::SupportPayBankTransfer() {
	return this->sup_pay_bank_transfer;
}

bool Business::SupportPayCreditCard(){
	return this->sup_pay_credit_card;
}

bool Business::SupportPayDebitCard(){
	return this->sup_pay_debit_card;
}

bool Business::SupportPayEOM(){
	return this->sup_pay_eom;
}
// Accessor methods
//  


// Other methods
//  


