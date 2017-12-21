#include "EOMPayment.h"

// Constructors/Destructors
//  

EOMPayment::EOMPayment (double value) : Payment::Payment(value) {}

EOMPayment::EOMPayment(double value, bool due, Date due_date, Hour due_hour) : Payment::Payment(value, due, due_date, due_hour) {}

EOMPayment::~EOMPayment () { }

//  
// Methods
//  

std::string EOMPayment::getPayType() {
	return "EOMPayment";
}

// Accessor methods
//  


// Other methods
//  


