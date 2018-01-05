#include "Client.h"

using namespace std;

//CLIENT

unsigned int Client::next_id = 2;
// Constructors/Destructors
//  

Client::Client(string name, Address address, unsigned int nif, string pass) {
	this->name = name;
	this->address = address;
	this->nif = nif;
	this->visibility = true;
	this->pass = pass;
	std::vector<Services*> v1;
	this->services = v1;
	this->id = next_id++;
}

Client::Client(string name, Address address, unsigned int nif, string pass,
		unsigned int id) {
	this->name = name;
	this->address = address;
	this->nif = nif;
	this->visibility = true;
	this->pass = pass;
	std::vector<Services*> v1;
	this->services = v1;
	this->id = id;
	this->next_id = id + 1;
}

Client::~Client() {
}

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

void Client::setVisibility(bool new_var) {
	this->visibility = new_var;
}

bool Client::getVisibility() const {
	return this->visibility;
}

void Client::setName(string new_name) {
	this->name = new_name;
}

string Client::getName() const {
	return this->name;
}

void Client::setAddress(Address new_add) {
	this->address = new_add;
}

Address Client::getAddress() const {
	return this->address;
}

unsigned int Client::getId() const {
	return this->id;
}

void Client::setNif(unsigned int new_nif) {
	this->nif = new_nif;
}

unsigned int Client::getNif() const {
	return this->nif;
}

void Client::setServices(vector<Services*> new_serv_vec) {
	this->services = new_serv_vec;
}

vector<Services*> Client::getServices() const {
	return this->services;
}

void Client::addServices(Services *new_serv) {
	this->services.push_back(new_serv);
}

Services Client::getServiceById(const unsigned int &id) const {
	for (unsigned int i = 0; i < this->getServices().size(); i++) {
		if (this->getServices().at(i)->getId() == id)
			return *this->getServices().at(i);
	}

	return Services(Address(), 0, Address());
}

Services* Client::getClientLastService()
{
	Services* ret = services.at(0);
	for (size_t i = 1; i < services.size(); i++)
	{
		if(services.at(i)->getDelivery() < ret->getDelivery())
			ret = services.at(i);
	}
	return ret;
}

unsigned int Client::getNextId() {
	return this->next_id;
}

void Client::setNextId(unsigned int n_id)
{
	next_id = n_id;
}

void Client::incNextId() {
	++this->next_id;
}

const unsigned int Client::newId() {
	//	const unsigned int newId = this->getNextId() * 10 + this->client_id;
	//	this->incNextId();
	//	return newId;

	this->incNextId();
	return this->next_id;
}

void Client::setPayment(vector<Payment*> new_pay_vec) {
	this->payments = new_pay_vec;
}

vector<Payment*> Client::getPayment() const {
	return this->payments;
}

void Client::addPayment(Payment *new_pay) {
	this->payments.push_back(new_pay);
}

unsigned int Client::getPaymentId(unsigned int s_id) {
	for (size_t i = 0; i < payments.size(); i++) {
		if (payments.at(i)->getServiceId() == s_id)
			return payments.at(i)->getId();
	}
	return 0;
}

string Client::getInfoDisp() const {
	string ret = "Client ID: ";
	ret += std::to_string(this->id);
	ret += "\n";
	ret += "Name: " + this->name + "\n";
	ret += "Address: " + this->getAddress().toStr() + "\n";
	ret += "NIF: " + std::to_string(this->nif) + "\n";
	return ret;

}

void Client::setPass(string new_var) {
	this->pass = new_var;
}

string Client::getPass() const {
	return this->pass;
}

bool Client::writeServicesToFile() {
	string file = "client" + to_string(id) + "_services.txt";

	ofstream output(file);

	if (output.is_open()) {

		for (unsigned int i = 0; i < this->services.size(); i++) {

			output << this->services.at(i)->getOriginAddress().getStreet()
					<< endl;
			output
					<< to_string(
							this->services.at(i)->getOriginAddress().getDoor_number())
					<< endl;
			output << this->services.at(i)->getOriginAddress().getCity()
					<< endl;
			output << this->services.at(i)->getOriginAddress().getCounty()
					<< endl;
			output << this->services.at(i)->getOriginAddress().getCountry()
					<< endl;
			output
					<< to_string(
							this->services.at(i)->getOriginAddress().getCoordinates().getLatitude())
					<< endl;
			output
					<< to_string(
							this->services.at(i)->getOriginAddress().getCoordinates().getLongitude())
					<< endl << endl;

			output << this->services.at(i)->getDestinationAddress().getStreet()
					<< endl;
			output
					<< to_string(
							this->services.at(i)->getDestinationAddress().getDoor_number())
					<< endl;
			output << this->services.at(i)->getDestinationAddress().getCity()
					<< endl;
			output << this->services.at(i)->getDestinationAddress().getCounty()
					<< endl;
			output << this->services.at(i)->getDestinationAddress().getCountry()
					<< endl;
			output
					<< to_string(
							this->services.at(i)->getDestinationAddress().getCoordinates().getLatitude())
					<< endl;
			output
					<< to_string(
							this->services.at(i)->getDestinationAddress().getCoordinates().getLongitude())
					<< endl << endl;

			output
					<< this->services.at(i)->getPackaging().getStart_date().toStr()
					<< endl;
			output
					<< this->services.at(i)->getPackaging().getStart_hour().toStr()
					<< endl;

			output
					<< to_string(
							this->services.at(i)->getDelivery().getStart_date()
									- this->services.at(i)->getShipping().getArrival_date())
					<< endl;

			output << this->services.at(i)->getVehiclePlate() << endl;

			output << this->services.at(i)->getExpectedTime() << endl;

			if ((i + 1) != this->services.size())
				output << this->services.at(i)->getVolume() << endl;
			else
				output << this->services.at(i)->getVolume();

		}

	} else
		return false;

	output.close();
	return true;
}

bool Client::writePaymentsToFile() {
	string file = "client" + to_string(id) + "_payments.txt";

	ofstream output(file);

	if (output.is_open()) {

		for (unsigned int i = 0; i < this->payments.size(); i++) {
			//Pay Type
			output << this->getPayment().at(i)->getPayType() << endl << endl;
			//Service id
			output << to_string(this->getPayment().at(i)->getServiceId())
					<< endl << endl;
			//Value
			output << to_string(this->getPayment().at(i)->getValue()) << endl
					<< endl;
			//Due
			output << to_string((int) this->getPayment().at(i)->getDue())
					<< endl << endl;
			//Due Date & Hour
			output << this->getPayment().at(i)->getDueDate().toStr() << endl;
			output << this->getPayment().at(i)->getDueHour().toStr() << endl
					<< endl;
		}

	} else
		return false;

	output.close();
	return true;
}

bool Client::writeClientToFile() {
	string file = "client" + to_string(id) + ".txt";

	ofstream output(file);

	if (output.is_open()) {

		//for (unsigned int i = 0; i < this->payments.size(); i++) {
		//Client Type
		output << this->getClientType() << endl << endl;
		//Name
		output << this->getName() << endl << endl;
		//Address info
		output << this->getAddress().getStreet() << endl;
		output << to_string(this->getAddress().getDoor_number()) << endl;
		output << this->getAddress().getCity() << endl;
		output << this->getAddress().getCounty() << endl;
		output << this->getAddress().getCountry() << endl;
		output << to_string(this->getAddress().getCoordinates().getLatitude())
				<< endl;
		output << to_string(this->getAddress().getCoordinates().getLongitude())
				<< endl << endl;
		//nif
		output << to_string(this->getNif()) << endl << endl;
		//pass
		output << this->getPass() << endl << endl;
		//}

	} else
		return false;

	output.close();
	return true;
}

string Client::clientToString(bool service) {
	string ret;
	ret = to_string(id) + '\t' + name + '\n';
	if (service)
		for (size_t i = 0; i < services.size(); i++)
			ret += '\t' + services.at(i)->toStrShort();
	return ret;
}

//CLIENT RECORD

ClientRecord::ClientRecord(Client * c) {
	this->clientPtr = c;
	this->id = clientPtr->getId();
}

ClientRecord::ClientRecord(unsigned int id)
{
	this->clientPtr = NULL;
	this->id = id;
}

Client * ClientRecord::getClientPtr()
{
	return clientPtr;
}

bool ClientRecord::getVisibility() const {
	return this->clientPtr->visibility;
}

void ClientRecord::setVisibility(bool new_var) {
	this->clientPtr->visibility = new_var;
}

string ClientRecord::getName() const {
	return this->clientPtr->name;
}

Address ClientRecord::getAddress() const {
	return this->clientPtr->address;
}

unsigned int ClientRecord::getId() const {
	return this->id;
}

void ClientRecord::setId(unsigned int new_id)
{
	id = new_id;
}

unsigned int ClientRecord::getNif() const {
	return this->clientPtr->nif;
}

vector<Services*> ClientRecord::getServices() const {
	return this->clientPtr->services;
}

vector<Payment*> ClientRecord::getPayment() const {
	return this->clientPtr->payments;
}

string ClientRecord::getPass() const {
	return this->clientPtr->pass;
}
