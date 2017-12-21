#include "CreditCard.h"

// Constructors/Destructors
//  

CreditCard::CreditCard (double value) : Payment::Payment(value) {}

CreditCard::CreditCard (double value, bool due, Date due_date, Hour due_hour) : Payment::Payment(value, due, due_date, due_hour) {}

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


