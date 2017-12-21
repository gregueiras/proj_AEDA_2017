#include "DebitCard.h"

// Constructors/Destructors
//  

DebitCard::DebitCard(unsigned int id) : Payment::Payment(id) {}

DebitCard::DebitCard (double value, string name) : Payment::Payment(value, name) {}

DebitCard::DebitCard (double value, string name, bool due, Date due_date, Hour due_hour) : Payment::Payment(value, name, due, due_date, due_hour) {}

DebitCard::~DebitCard () { }

//  
// Methods
//  

std::string DebitCard::getPayType() {
	return "DebitCard";
}

// Accessor methods
//  


// Other methods
//  


