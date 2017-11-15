#include "Personal.h"

// Constructors/Destructors
//  

Personal::Personal (string name, Address address, unsigned int nif, string passwd) : Client::Client(name, address, nif, newId(), passwd) {}

Personal::~Personal () { }

//  
// Methods
//  

const unsigned int Personal::newId() {
	const unsigned int newId = this->getNextId() * 10 + this->client_id;
	this->incNextId();
	return newId;
}

bool Personal::SupportPayBankTransfer() {
	return this->sup_pay_bank_transfer;
}

bool Personal::SupportPayCreditCard(){
	return this->sup_pay_credit_card;
}

bool Personal::SupportPayDebitCard(){
	return this->sup_pay_debit_card;
}

bool Personal::SupportPayEOM(){
	return this->sup_pay_eom;
}
// Accessor methods
//  


// Other methods
//  


