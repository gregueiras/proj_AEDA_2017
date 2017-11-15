#include "../../../headers/Company/Client/Unregistered.h"

// Constructors/Destructors
//  

Unregisted::Unregisted (string name, Address address, unsigned int nif) : Client::Client(name, address, nif, newId()) {}

Unregisted::~Unregisted () { }

//  
// Methods
//  
const unsigned int Unregisted::newId() {
	const unsigned int newId = this->getNextId() * 10 + this->client_id;
	this->incNextId();
	return newId;
}

// Accessor methods
//  


// Other methods
//  


