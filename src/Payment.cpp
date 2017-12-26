#include "Payment.h"

unsigned int Payment::next_id = 1;

//PAYMENTS

// Constructors/Destructors
//  

Payment::Payment(double value, unsigned int s_id) : id(next_id++), service_id(s_id) {
	this->value = value;
	this->due = false;
}

Payment::Payment(double value, unsigned int s_id, bool due, Date due_date, Hour due_hour) : id(next_id++), service_id(s_id) {
	this->value = value;
	this->due = due;
	this->due_date = due_date;
	this->due_hour = due_hour;
}

Payment::~Payment() { }

//  
// Methods
//  

unsigned int Payment::getServiceId() const
{
	return service_id;
}

unsigned int Payment::getId() const
{
	return this->id;
}

unsigned int Payment::getNextId() const{
	return this->next_id;
}

void Payment::setDue(bool new_var) {
	this->due = new_var;
}

bool Payment::getDue() const{
	return this->due;
}

void Payment::setDueDate(Date new_var) {
	this->due_date = new_var;
}

Date Payment::getDueDate() const{
	return this->due_date;
}

double Payment::getValue()
{
	return this->value;
}

void Payment::setDueHour(Hour new_var) {
	this->due_hour = new_var;
}

Hour Payment::getDueHour() const{
	return this->due_hour;
}

// Accessor methods
//  


// Other methods
//  

//PAYMENTS RECORD

PaymentRecord::PaymentRecord(string name, Payment * ptr)
{
	this->name = name;
	this->ptr = ptr;

	if (ptr != NULL)
		this->id = ptr->getId();
}

PaymentRecord::PaymentRecord(unsigned int ident)
{
	id = ident;
}

string PaymentRecord::getName() const
{
	return name;
}

void PaymentRecord::setName(string new_var)
{
	name = new_var;
}

unsigned int PaymentRecord::getId() const
{
	return ptr->getId();
}

unsigned int PaymentRecord::getServiceId() const
{
	return ptr->getServiceId();
}

bool PaymentRecord::getDue() const
{
	return ptr->getDue();
}

void PaymentRecord::setDue(bool new_due)
{
	ptr->setDue(new_due);
}

Date PaymentRecord::getDueDate() const
{
	return ptr->getDueDate();
}

Hour PaymentRecord::getDueHour() const
{
	return ptr->getDueHour();
}

bool PaymentRecord::operator<(const PaymentRecord & pr1) const
{
	if (name == pr1.name) {
		if (this->ptr->getDueDate() == pr1.ptr->getDueDate())
			return (this->ptr->getDueHour() < pr1.ptr->getDueHour());
		else
			return (this->ptr->getDueDate() < pr1.ptr->getDueDate());
	}
	else
		return (name < pr1.name);
}

bool PaymentRecord::operator==(const PaymentRecord & pr1) const
{
	return (this->id == pr1.id);
}