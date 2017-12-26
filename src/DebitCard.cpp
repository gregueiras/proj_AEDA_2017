#include "DebitCard.h"

// Constructors/Destructors
//  

DebitCard::DebitCard (double value, unsigned int s_id) : Payment::Payment(value, s_id) {}

DebitCard::DebitCard (double value, unsigned int s_id, bool due, Date due_date, Hour due_hour) : Payment::Payment(value, s_id, due, due_date, due_hour) {}

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


