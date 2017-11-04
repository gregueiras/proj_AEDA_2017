#include "Client.h"
#include "Company.h"


unsigned int Client::next_id = 1;
// Constructors/Destructors
//  

Client::Client (string name, Address address, unsigned int nif) {
	this->name = name;
	this->address = address;
	this->nif = nif;
}

Client::~Client () { }

//  
// Methods
//  

void Client::setName(string new_name) {
	this->name = new_name;
}

string Client::getName() {
	return this->name;
}

void Client::setAddress(Address new_add) {
	this->address = new_add;
}

Address Client::getAddress() {
	return this->address;
}

void Client::setNif(unsigned int new_nif) {
	this->nif = new_nif;
}

unsigned int Client::getNif() {
	return this->nif;
}

void Client::setServices(vector<Services*> new_serv_vec) {
	this->services = new_serv_vec;
}

vector<Services*> Client::getServices() {
	return this->services;
}

void Client::addServices(Services *new_serv) {
	this->services.push_back(new_serv);
}

unsigned int Client::getNextId() {
	return this->next_id;
}

void Client::incNextId() {
	++this->next_id;
}

void Client::setPayment(vector<Payment*> new_pay_vec) {
	this->payments = new_pay_vec;
}

vector<Payment*> Client::getPayment() {
	return this->payments;
}

void Client::addPayment(Payment *new_pay) {
	this->payments.push_back(new_pay);
}
