#include "BankTransfer.h"

// Constructors/Destructors
//  

BankTransfer::BankTransfer (double value) : Payment::Payment(value) {}

BankTransfer::BankTransfer(double value, bool due, Date due_date, Hour due_hour) : Payment::Payment(value, due, due_date, due_hour) {}

BankTransfer::~BankTransfer () { }

//  
// Methods
//  

string BankTransfer::getPayType() {
	return "BankTransfer";
}

// Accessor methods
//  


// Other methods
//  


