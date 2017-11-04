#include "Company.h"

// Constructors/Destructors
//  

Company::Company (unsigned long cost_km_m, unsigned long cost_day_in_storage) {
	this->cost_km_m = cost_km_m;
	this->cost_day_in_storage = cost_day_in_storage;
}

Company::~Company () { }

//  
// Methods
//  

void Company::setCost_km_m(unsigned long new_var) {
	this->cost_km_m = new_var;
}

unsigned long Company::getCost_km_m() {
	return this->cost_km_m;
}

void Company::setCost_day_in_storage(unsigned long new_var) {
	this->cost_day_in_storage = new_var;
}

unsigned long Company::getCost_day_in_storage() {
	return this->cost_day_in_storage;
}

void Company::setClients(vector<Client*> new_var) {
	this->clients = new_var;
}

vector<Client*> Company::getClients() {
	return this->clients;
}

void Company::addClient(Client *new_var) {
	this->clients.push_back(new_var);
}

void Company::setServicesQueue(vector<Services*> new_var) {
	this->services_queue = new_var;
}

vector<Services*> Company::getServicesQueue() {
	return this->services_queue;
}

void Company::addService(Services *new_var, unsigned int client_id) {
	bool client_identified = false;

	int clients_size = this->getClients().size();
	for (size_t i = 0; i < clients_size; i++)
	{
		//pointer to client in analisies
		Client *i_Client = this->clients.at(i);
		//if client is found (by id)
		if (i_Client->getId() == client_id) {
			//client is identified 
			client_identified = true;
			//add service to client
			i_Client->addServices(new_var);
			break;
		}
	}

	if(client_identified)
		this->services_queue.push_back(new_var);
}

void Company::addPayment(Payment *new_var, unsigned int client_id) {
	bool client_identified = false;

	int clients_size = this->getClients().size();
	for (size_t i = 0; i < clients_size; i++)
	{
		//pointer to client in analisies
		Client *i_Client = this->clients.at(i);
		//if client is found (by id)
		if (i_Client->getId() == client_id) {
			//client is identified 
			client_identified = true;
			//add service to client
			i_Client->addPayment(new_var);
			break;
		}
	}

	if (client_identified)
		this->payments_regist.push_back(new_var);
}