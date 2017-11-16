#include "Unregistered.h"

// Constructors/Destructors
//  

Unregistered::Unregistered (string name, Address address, unsigned int nif, string passwd) : Client::Client(name, address, nif, newId(), passwd),
																							sup_pay_bank_transfer(true), sup_pay_credit_card(false),
																							sup_pay_debit_card(true), sup_pay_eom(false), client_id(3) {}

Unregistered::~Unregistered () { }

//  
// Methods
//  

// Accessor methods
//  


// Other methods
//  


