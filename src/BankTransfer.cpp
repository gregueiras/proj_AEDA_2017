#include "BankTransfer.h"

// Constructors/Destructors
//  

BankTransfer::BankTransfer(unsigned int id) : Payment::Payment(id) {}

BankTransfer::BankTransfer (double value, string name) : Payment::Payment(value, name) {}

BankTransfer::BankTransfer(double value, string name, bool due, Date due_date, Hour due_hour) : Payment::Payment(value, name, due, due_date, due_hour) {}

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


