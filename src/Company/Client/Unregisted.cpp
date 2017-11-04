#include "Unregisted.h"

// Constructors/Destructors
//  

Unregisted::Unregisted () {
}

Unregisted::~Unregisted () { }

//  
// Methods
//  

const unsigned int Unregisted::getId() {
	return this->id;
}

const unsigned int Unregisted::newId() {
	const unsigned int newId = this->getNextId() * 10 + this->client_id;
	this->incNextId();
	return newId;
}

// Accessor methods
//  


// Other methods
//  


