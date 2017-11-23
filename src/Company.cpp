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

Client * Company::getClient(unsigned int id){
	int clients_size = this->clients.size();
	for(int i = 0; i < clients_size; ++i){
		if(id == this->clients.at(i)->getId()){
			return this->clients.at(i);
			
		}
	}
	return NULL;
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



vector<Services*> Company::readFromFile(const unsigned int id)
{
	vector<Services*> temp_v;
	string country, county, city, street, temp;
	unsigned int door_number, days_in_storage;
	double lat, lon, volume;

	string file = "client" + to_string(id) + "_services.txt";

	ifstream input;
	input.open(file);
	if (input.is_open())
	{
		while (!input.eof())
		{

			getline(input, street);

			getline(input, temp);
			door_number = stoul(temp);

			getline(input, city);
			getline(input, county);
			getline(input, country);

			getline(input, temp);
			lat = stod(temp);

			getline(input, temp);
			lon = stod(temp);

			Address origin(street, country, city, county, door_number, lat, lon);

			getline(input, temp);

			getline(input, street);

			getline(input, temp);
			door_number = stoul(temp);

			getline(input, city);
			getline(input, county);
			getline(input, country);

			getline(input, temp);
			lat = stod(temp);

			getline(input, temp);
			lon = stod(temp);

			Address destination(street, country, city, county, door_number, lat, lon);

			getline(input, temp);

			getline(input, temp);
			Date start_d(stoul(temp.substr(0, 2)), stoul(temp.substr(3, 2)), stoul(temp.substr(6)));

			getline(input, temp);
			Hour start_h(stoul(temp.substr(0, 2)), stoul(temp.substr(3)));

			getline(input, temp);
			days_in_storage = stoul(temp);

			getline(input, temp);
			volume = stod(temp);

			Services* s1 = new Services(origin, volume, destination, start_h, start_d, days_in_storage);

			temp_v.push_back(s1);
		}




		input.close();



		return temp_v;
	}
	else
	{
		return temp_v;
	}
}