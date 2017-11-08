#include "Business.h"

// Constructors/Destructors
//  

Business::Business (string name, Address address, unsigned int nif) : Client::Client(name, address, nif, newId()) {}

Business::~Business () { }

//  
// Methods
//  
const unsigned int Business::newId() {
//	const unsigned int newId = this->getNextId() * 10 + this->client_id;
	this->incNextId();
	return newId;
}

// Accessor methods
//  


// Other methods
//  


