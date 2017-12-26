#include "BankTransfer.h"

// Constructors/Destructors
//  

BankTransfer::BankTransfer (double value, unsigned int s_id) : Payment::Payment(value, s_id) {}

BankTransfer::BankTransfer(double value, unsigned int s_id, bool due, Date due_date, Hour due_hour) : Payment::Payment(value, s_id, due, due_date, due_hour) {}

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


