#include "EOMPayment.h"

// Constructors/Destructors
//  

EOMPayment::EOMPayment (double value, unsigned int s_id) : Payment::Payment(value, s_id) {}

EOMPayment::EOMPayment(double value, unsigned int s_id, bool due, Date due_date, Hour due_hour) : Payment::Payment(value, s_id, due, due_date, due_hour) {}

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


