#include "Unregistered.h"

// Constructors/Destructors
//  

Unregistered::Unregistered (string name, Address address, unsigned int nif) : Client::Client(name, address, nif, "") {}

Unregistered::Unregistered(string name, Address address, unsigned int nif, unsigned int id) : Client::Client(name, address, nif, "", id) {}

Unregistered::~Unregistered () { }

//  
// Methods
//  

std::string Unregistered::getClientType() {
	return "Unregistered";
}

// Accessor methods
//  


// Other methods
//  


