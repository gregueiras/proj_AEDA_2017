#include "Unregistered.h"

// Constructors/Destructors
//  

Unregistered::Unregistered (string name, Address address, unsigned int nif, string passwd) : Client::Client(name, address, nif, passwd) {}

Unregistered::Unregistered(string name, Address address, unsigned int nif, string passwd, unsigned int id) : Client::Client(name, address, nif, passwd, id) {}

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


