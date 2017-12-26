#include "CreditCard.h"

// Constructors/Destructors
//  

CreditCard::CreditCard (double value, unsigned int s_id) : Payment::Payment(value, s_id) {}

CreditCard::CreditCard (double value, unsigned int s_id, bool due, Date due_date, Hour due_hour) : Payment::Payment(value, s_id, due, due_date, due_hour) {}

CreditCard::~CreditCard () { }

//  
// Methods
//  

string CreditCard::getPayType() {
	return "CreditCard";
}

// Accessor methods
//  


// Other methods
//  


