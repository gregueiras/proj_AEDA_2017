#include "Business.h"

// Constructors/Destructors
//  

Business::Business (string name, Address address, unsigned int nif, string passwd) : Client::Client(name, address, nif, newId(), passwd) {}


Business::~Business () { }

//  
// Methods
//  

// Accessor methods
//  


// Other methods
//  


