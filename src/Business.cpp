#include "Business.h"

// Constructors/Destructors
//  

Business::Business (string name, Address address, unsigned int nif, string passwd) : Client::Client(name, address, nif, passwd) {}

Business::Business(string name, Address address, unsigned int nif, string passwd, unsigned int id) : Client::Client(name, address, nif, passwd, id) {}


Business::~Business () { }

//  
// Methods
//  

std::string Business::getClientType() {
	return "Business";
}

// Accessor methods
//  


// Other methods
//  


