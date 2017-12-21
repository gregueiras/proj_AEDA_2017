#include "CreditCard.h"

// Constructors/Destructors
//  

CreditCard::CreditCard(unsigned int id) : Payment::Payment(id) {}

CreditCard::CreditCard (double value, string name) : Payment::Payment(value, name) {}

CreditCard::CreditCard (double value, string name, bool due, Date due_date, Hour due_hour) : Payment::Payment(value, name, due, due_date, due_hour) {}

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


