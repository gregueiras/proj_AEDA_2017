#include "Company.h"

using namespace std;
// Constructors/Destructors
//  

unsigned long Company::cost_day_in_storage = 2;
unsigned long Company::cost_km_m = 1.5;

Company::Company () {}


Company::~Company () { }

//  
// Methods
//  



unsigned long Company::getCost_km_m() {
	return this->cost_km_m;
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

bool Company::addClient(Client *new_var) {
	unsigned int new_client_id = new_var->getId();

//	int clients_size = this->clients.size();
//	for(int i = 0; i < clients_size; ++i){
//		if(new_client_id == this->clients.at(i)->getId())
//			return false;
//	}
	this->clients.push_back(new_var);
	return true;
}

bool Company::getClient(unsigned int id, Client *new_var){
	int clients_size = this->clients.size();
	for(int i = 0; i < clients_size; ++i){
		if(id == this->clients.at(i)->getId()){
			new_var = this->clients.at(i);
			return true;
		}
	}
	return false;
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
