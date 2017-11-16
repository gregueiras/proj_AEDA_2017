#include "Personal.h"

// Constructors/Destructors
//  

Personal::Personal (string name, Address address, unsigned int nif, string passwd) : Client::Client(name, address, nif, newId(), passwd), 
																					sup_pay_bank_transfer(true), sup_pay_credit_card(false), 
																					sup_pay_debit_card(true), sup_pay_eom(false), client_id(1){}

Personal::~Personal () { }

//  
// Methods
//  

// Accessor methods
//  


// Other methods
//  


