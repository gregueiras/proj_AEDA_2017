#include "DebitCard.h"

// Constructors/Destructors
//  

DebitCard::DebitCard (double value) : Payment::Payment(value) {}

DebitCard::DebitCard (double value, bool due, Date due_date, Hour due_hour) : Payment::Payment(value, due, due_date, due_hour) {}

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


