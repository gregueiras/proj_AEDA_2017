#include "Personal.h"

// Constructors/Destructors
//  

Personal::Personal (string name, Address address, unsigned int nif) : Client::Client(name, address, nif, newId()) {}

Personal::~Personal () { }

//  
// Methods
//  

const unsigned int Personal::newId() {
	const unsigned int newId = this->getNextId() * 10 + this->client_id;
	this->incNextId();
	return newId;
}

// Accessor methods
//  


// Other methods
//  


