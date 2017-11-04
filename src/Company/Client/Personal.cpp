#include "Personal.h"

// Constructors/Destructors
//  

Personal::Personal () {
}

Personal::~Personal () { }

//  
// Methods
//  

const unsigned int Personal::getId() {
	return this->id;
}

const unsigned int Personal::newId() {
	const unsigned int newId = this->getNextId() * 10 + this->client_id;
	this->incNextId();
	return newId;
}

// Accessor methods
//  


// Other methods
//  


