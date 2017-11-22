#include "Unregistered.h"

// Constructors/Destructors
//  

Unregistered::Unregistered (string name, Address address, unsigned int nif, string passwd) : Client::Client(name, address, nif, newId(), passwd)
{}


Unregistered::~Unregistered () { }

//  
// Methods
//  

// Accessor methods
//  


// Other methods
//  


