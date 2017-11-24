#include "Personal.h"

// Constructors/Destructors
//  

Personal::Personal (string name, Address address, unsigned int nif, string passwd) : Client::Client(name, address, nif, passwd) {}

Personal::Personal(string name, Address address, unsigned int nif, string passwd, unsigned int id) : Client::Client(name, address, nif, passwd, id) {}

Personal::~Personal () { }

//  
// Methods
//  

std::string Personal::getClientType() {
	return "Personal";
}

// Accessor methods
//  


// Other methods
//  


