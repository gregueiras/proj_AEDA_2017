#include "Personal.h"

// Constructors/Destructors
//  

Personal::Personal (string name, Address address, unsigned int nif, string passwd) : Client::Client(name, address, nif, newId(), passwd) {}

Personal::~Personal () { }

//  
// Methods
//  

// Accessor methods
//  


// Other methods
//  


