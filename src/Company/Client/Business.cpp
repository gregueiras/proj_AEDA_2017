#include "Business.h"

// Constructors/Destructors
//  

Business::Business (string name, Address address, unsigned int nif, string passwd) : Client::Client(name, address, nif, newId(), passwd),
																					sup_pay_bank_transfer(true), sup_pay_credit_card(false),
																					sup_pay_debit_card(true), sup_pay_eom(false), client_id(2) {}


Business::~Business () { }

//  
// Methods
//  

// Accessor methods
//  


// Other methods
//  


