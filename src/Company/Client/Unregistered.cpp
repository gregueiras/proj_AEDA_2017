#include "../../../headers/Company/Client/Unregistered.h"

// Constructors/Destructors
//  

Unregistered::Unregistered (string name, Address address, unsigned int nif, string passwd) : Client::Client(name, address, nif, newId(), passwd) {}

Unregistered::~Unregistered () { }

//  
// Methods
//  
const unsigned int Unregistered::newId() {
	const unsigned int newId = this->getNextId() * 10 + this->client_id;
	this->incNextId();
	return newId;
}

bool Unregistered::SupportPayBankTransfer() {
	return this->sup_pay_bank_transfer;
}

bool Unregistered::SupportPayCreditCard(){
	return this->sup_pay_credit_card;
}

bool Unregistered::SupportPayDebitCard(){
	return this->sup_pay_debit_card;
}

bool Unregistered::SupportPayEOM(){
	return this->sup_pay_eom;
}

// Accessor methods
//  


// Other methods
//  


