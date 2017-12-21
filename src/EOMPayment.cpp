#include "EOMPayment.h"

// Constructors/Destructors
//  

EOMPayment::EOMPayment(unsigned int id) : Payment::Payment(id) {}

EOMPayment::EOMPayment (double value, string name) : Payment::Payment(value, name) {}

EOMPayment::EOMPayment(double value, string name, bool due, Date due_date, Hour due_hour) : Payment::Payment(value, name, due, due_date, due_hour) {}

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


