#include "Client.h"


unsigned int Client::next_id = 1;
// Constructors/Destructors
//  

Client::Client (string name, Address address, unsigned int nif, string pass) : id(next_id++) {
	this->name = name;
	this->address = address;
	this->nif = nif;
	this->visibility = true;
	this->pass = pass;
	std::vector<Services*> v1;
	this->services = v1;
}

Client::~Client () { }

//  
// Methods
//  

//bool Client::SupportPayBankTransfer() {
//	return this->sup_pay_bank_transfer;
//}
//
//bool Client::SupportPayCreditCard() {
//	return this->sup_pay_credit_card;
//}
//
//bool Client::SupportPayDebitCard() {
//	return this->sup_pay_debit_card();
//}
//
//bool Client::SupportPayEOM() {
//	return this->sup_pay_eom;
//}

void Client::setVisibility (bool new_var){
	this->visibility = new_var;
}

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

const unsigned int Client::getId(){
	return this->id;
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
	std::cout << "d1" << std::endl;

	std::cout << (*new_serv) << std::endl;
	
	//std::cout << this->services.size() << std::endl;
	this->services.push_back(new_serv);
	std::cout << "d2" << std::endl;
}

Services Client::getServiceById(const unsigned int &id) {
	for (unsigned int i = 0; i < this->getServices().size(); i++)
	{
		if (this->getServices().at(i)->getId() == id)
			return *this->getServices().at(i);
	}

	return Services(Address(), 0, Address());
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

string Client::getInfoDisp(){
	string ret = "Client ID: ";
	ret += std::to_string(this->id);
	ret += "\n";
	ret += "Name: " + this->name + "\n";
	ret += "Address: " + this->getAddress().toStr() + "\n";
	ret += "NIF: " + std::to_string(this->nif) + "\n";
	return ret;

}

void Client::setPass (string new_var) {
	this->pass = new_var;
}

string Client::getPass () {
	return this->pass;
}


