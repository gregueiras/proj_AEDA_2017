#include "Company.h"

using namespace std;
// Constructors/Destructors
//  

Company::Company() :
		payments_regist(PaymentRecord(0)) {
	payments_regist.makeEmpty();
	admin_id = 0;
	admin_pass = "0";
}

Company::Company(string nib, string entity, string reference) :
		payments_regist(PaymentRecord(0)) {
	payments_regist.makeEmpty();
	this->nib = nib;
	this->entity = entity;
	this->reference = reference;
}

Company::~Company() {
}

Date Company::getCurrentDate() const {
	return this->current_date;
}

void Company::setCurrentDate(Date new_var) {
	this->current_date = new_var;
}

Hour Company::getCurrentHour() const {
	return this->current_hour;
}

void Company::setCurrentHour(Hour new_var) {
	this->current_hour = new_var;
}

int Company::findClient(Client * c) {
	int pos = -1;
	for (size_t i = 0; i < clients.size(); i++) {
		if (clients.at(i)->getId() == c->getId()) {
			pos = i;
			break;
		}
	}
	return pos;
}

void Company::deactivateClientRecord(Client * c) {
	c->setVisibility(false);

	int pos = findClient(c);

	if (pos == -1)
		return;

	inactive_clients.insert(ClientRecord(c));

	clients.erase(clients.begin() + pos);
}

void Company::activateClientRecord(Client * c) {
	auto it = inactive_clients.find(ClientRecord(c));

	if (it == inactive_clients.end())
		return;

	inactive_clients.erase(it);

	c->setVisibility(true);

	clients.push_back(c);
}

string Company::getNib() const {
	return this->nib;
}

void Company::setNib(string new_var) {
	this->nib = new_var;
}

string Company::getEntity() const {
	return this->entity;
}

void Company::setEntity(string new_var) {
	this->entity = new_var;
}

string Company::getReference() const {
	return this->reference;
}

void Company::setReference(string new_var) {
	this->reference = new_var;
}

//  
// Methods
//  

//unsigned long Company::getCost_km_m() {
//	return this->cost_km_m;
//}
//
//
//
//unsigned long Company::getCost_day_in_storage() {
//	return this->cost_day_in_storage;
//}

void Company::setClients(vector<Client*> new_var) {
	this->clients = new_var;
}

vector<Client*> Company::getClients() const {
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

Client * Company::getClient(unsigned int id) const {
	int clients_size = this->clients.size();
	for (int i = 0; i < clients_size; ++i) {
		if (id == this->clients.at(i)->getId()
				&& this->clients.at(i)->getVisibility() == true) {
			return this->clients.at(i);
		}
	}
	return NULL;
}

void Company::setServicesQueue(vector<Services*> new_var) {
	this->services_queue = new_var;
}

vector<Services*> Company::getServicesQueue() const {
	return this->services_queue;
}

void Company::addService(Services *new_var, unsigned int client_id) {
	bool client_identified = false;

	int clients_size = this->getClients().size();
	for (int i = 0; i < clients_size; i++) {
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

	if (client_identified)
		this->services_queue.push_back(new_var);
}

void Company::addPayment(Payment *new_var, unsigned int client_id) {
	bool client_identified = false;
	string name;

	int clients_size = this->getClients().size();
	for (int i = 0; i < clients_size; i++) {
		//pointer to client in analisies
		Client *i_Client = this->clients.at(i);
		//if client is found (by id)
		if (i_Client->getId() == client_id) {
			//client is identified 
			client_identified = true;
			name = i_Client->getName();
			//add service to client
			i_Client->addPayment(new_var);
			break;
		}
	}

	if (client_identified) {
		this->payments_regist.insert(PaymentRecord(name, new_var));
	}

}

PaymentRecord Company::getPayment(unsigned int pay_id) {
	return this->payments_regist.find(PaymentRecord(pay_id));
}

vector<Services*> Company::readServicesFromFile(const unsigned int id) {
	vector<Services*> temp_v;
	string country, county, city, street, temp;
	unsigned int door_number, days_in_storage;
	double lat, lon, volume;

	string file = "client" + to_string(id) + "_services.txt";

	ifstream input;
	input.open(file);
	if (input.is_open()) {

		while (!input.eof()) {

			getline(input, street);
			if (street == "")
				return temp_v;
			getline(input, temp);
			door_number = stoul(temp);

			getline(input, city);
			getline(input, county);
			getline(input, country);

			getline(input, temp);
			lat = stod(temp);

			getline(input, temp);
			lon = stod(temp);

			Address origin(street, country, city, county, door_number, lat,
					lon);

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

			Address destination(street, country, city, county, door_number, lat,
					lon);

			getline(input, temp);

			getline(input, temp);
			Date start_d(stoul(temp.substr(0, 2)), stoul(temp.substr(3, 2)),
					stoul(temp.substr(6)));

			getline(input, temp);
			Hour start_h(stoul(temp.substr(0, 2)), stoul(temp.substr(3)));

			getline(input, temp);
			days_in_storage = stoul(temp);

			getline(input, temp);
			volume = stod(temp);

			Services* s1 = new Services(origin, volume, destination, start_h,
					start_d, days_in_storage);

			temp_v.push_back(s1);
		}

		input.close();

		return temp_v;
	} else {
		return temp_v;
	}
}

Client* Company::readClientFromFile(const unsigned int id) {
	Client* ptr = NULL;
	string name, pass, client_type;
	unsigned int nif;

	//Address variables
	string country, county, city, street, temp;
	unsigned int door_number;
	double lat, lon;

	string file = "client" + to_string(id) + ".txt";
	ifstream input;
	input.open(file);
	if (input.is_open()) {
		//get client_type
		getline(input, client_type);
		//////////////////////

		getline(input, temp);

		//get name
		getline(input, name);
		//////////////////////

		getline(input, temp);

		//get Address info
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

		Address address(street, country, city, county, door_number, lat, lon);
		//////////////////////

		getline(input, temp);

		//get nif
		getline(input, temp);
		nif = stoul(temp);
		//////////////////////

		getline(input, temp);

		//get pass
		getline(input, pass);
		//////////////////////	

		if (client_type == "Business")
			ptr = new Business(name, address, nif, pass, id);
		else if (client_type == "Personal")
			ptr = new Personal(name, address, nif, pass, id);
		else if (client_type == "Unregistered")
			ptr = new Unregistered(name, address, nif, id);

		input.close();

	}

	return ptr;
}

vector<Payment*> Company::readPaymentsFromFile(Client* ptr,
		const unsigned int id) {
	vector<Payment*> temp_v;
	Payment* pptr = NULL;
	string temp, pay_type;
	double value;
	bool due;

	string file = "client" + to_string(id) + "_payments.txt";

	ifstream input;
	input.open(file);
	if (input.is_open()) {
		while (!input.eof()) {
			//get pay_type
			getline(input, pay_type);
			//////////////////////

			getline(input, temp);

			//get value
			getline(input, temp);
			value = stod(temp);
			//////////////////////

			getline(input, temp);

			//get due - bool in int format
			getline(input, temp);
			due = stoi(temp);
			//////////////////////

			getline(input, temp);

			//get due_date and due_hour
			getline(input, temp);
			Date due_date(stoul(temp.substr(0, 2)), stoul(temp.substr(3, 2)),
					stoul(temp.substr(6)));
			getline(input, temp);
			Hour due_hour(stoul(temp.substr(0, 2)), stoul(temp.substr(3)));
			//////////////////////

			if (pay_type == "BankTransfer")
				pptr = new BankTransfer(value, due, due_date, due_hour);
			else if (pay_type == "CreditCard")
				pptr = new CreditCard(value, due, due_date, due_hour);
			else if (pay_type == "DebitCard")
				pptr = new DebitCard(value, due, due_date, due_hour);
			else if (pay_type == "EOMPayment")
				pptr = new EOMPayment(value, due, due_date, due_hour);

			temp_v.push_back(pptr);
		}

		input.close();

	}

	return temp_v;

}

vector<Client*> Company::readClientsFromFile() {
	vector<Client*> c_tmp;
	vector<Services*> s_tmp;
	vector<Payment*> p_tmp;
	unsigned int id = 1;
	Client* ptr = NULL;

	do {
		ptr = readClientFromFile(id);

		if (ptr == NULL)
			break;

		s_tmp = readServicesFromFile(id);
		ptr->setServices(s_tmp);
		//add services to company registers
		this->services_queue.insert(this->services_queue.end(), s_tmp.begin(),
				s_tmp.end());

		p_tmp = readPaymentsFromFile(ptr, id);
		ptr->setPayment(p_tmp);

		//add payments to company registers
		for (size_t i = 0; i < p_tmp.size(); i++)
			this->payments_regist.insert(
					PaymentRecord(ptr->getName(), p_tmp.at(i)));

		c_tmp.push_back(ptr);

		++id;
	} while (ptr != NULL);

	this->clients = c_tmp;

	return c_tmp;
}

bool Company::writeClientsToFile() {
	for (size_t i = 0; i < this->getClients().size(); i++) {
		if (!(this->getClients().at(i)->writeClientToFile()))
			return false;

		if (!(this->getClients().at(i)->writeServicesToFile()))
			return false;

		if (!(this->getClients().at(i)->writePaymentsToFile()))
			return false;
	}

	return true;
}

bool Company::writeCompanyToFile() {
	string file = "company.txt";

	ofstream output(file);

	if (output.is_open()) {

		//nib
		//output << this->getNib() << endl << endl;
		output << this->nib << endl << endl;
		//entity
		output << this->getEntity() << endl << endl;
		//reference
		output << this->getReference() << endl << endl;
		//Current Date & Hour
		output << this->getCurrentDate().toStr() << endl;
		output << this->getCurrentHour().toStr() << endl << endl;

	} else
		return false;

	output.close();
	return true;
}

bool Company::readCompanyFromFile() {
	string temp;

	string file = "company.txt";

	ifstream input;
	input.open(file);
	if (input.is_open()) {
		//get nib
		getline(input, temp);
		this->setNib(temp);
		//////////////////////

		getline(input, temp);

		//get entity
		getline(input, temp);
		this->setEntity(temp);
		//////////////////////

		getline(input, temp);

		//get reference
		getline(input, temp);
		this->setReference(temp);
		//////////////////////

		getline(input, temp);

		//get current_date and current_hour
		getline(input, temp);
		try {
			Date current_date(stoul(temp.substr(0, 2)),
					stoul(temp.substr(3, 2)), stoul(temp.substr(6)));
		} catch (DateInvalidDay& d) {
			cout << "Error reading current day \n";
			input.close();
			return false;
		} catch (DateInvalidMonth& d) {
			cout << "Error reading current month \n";
			input.close();
			return false;
		} catch (DateInvalidYear& d) {
			cout << "Error reading current year \n";
			input.close();
			return false;
		}

		Date current_date(stoul(temp.substr(0, 2)), stoul(temp.substr(3, 2)),
				stoul(temp.substr(6)));

		this->setCurrentDate(current_date);
		getline(input, temp);
		Hour current_hour(stoul(temp.substr(0, 2)), stoul(temp.substr(3)));
		this->setCurrentHour(current_hour);
		//////////////////////

		input.close();

		return true;

	}
	return false;
}

bool Company::checkAllDues(Client * c, double &value) {
	value = 0;
	for (size_t i = 0; i < c->getPayment().size(); i++) {
		//Assuming EOMPayment
		if (c->getPayment().at(i)->getDue() == true)
			value += c->getPayment().at(i)->getValue();
	}
	if (value == 0)
		return false;
	else
		return true;
}

void Company::payAllDues(Client * c) {
	for (size_t i = 0; i < c->getPayment().size(); i++) {
		//Assuming EOMPayment
		if (c->getPayment().at(i)->getDue() == true) {
			c->getPayment().at(i)->setDue(false);
			c->getPayment().at(i)->setDueDate(this->current_date);
			c->getPayment().at(i)->setDueHour(this->current_hour);
		}
	}
}

bool Company::removeVehicleMaintenance(string brand, string model,
		string plate) {

	vector<Vehicle> temp;

	Vehicle toFound(plate, brand, model);
	Vehicle v_temp;
	bool found = false;

	while ((!this->vehicles.empty()) && (found == false)) {
		v_temp = vehicles.top();
		vehicles.pop();

		if ((v_temp == toFound) && (v_temp.isAvailable())) {
			v_temp.setAvailable(false);
			found = true;
		}
		temp.push_back(v_temp);
	}

	for (unsigned int i = 0; i < temp.size(); i++)
		vehicles.push(temp.at(i));

	return found;
}

bool Company::addVehicle(Vehicle v1) {

	priority_queue<Vehicle> temp = this->vehicles;

	while (!temp.empty()) {
		Vehicle attempt = temp.top();

		if (attempt == v1)
			return false;

		temp.pop();
	}

	this->vehicles.push(v1);
	return true;
}

bool Company::writeVehiclesToFile() {

	string file = "vehicles.txt";
	ofstream output(file);

	if (output.is_open()) {

		while (!this->vehicles.empty()) {
			Vehicle temp = vehicles.top();

			output << temp.getPlate() << std::endl;

			output << temp.getBrand() << std::endl;

			output << temp.getModel() << std::endl;

			output << temp.getMaintenance() << std::endl;

			output << temp.getBirthday() << std::endl;

			output << temp.getExpectableTime() << std::endl;

			output << ((temp.isAvailable()) ? "1" : "0") << std::endl
					<< std::endl;

			vehicles.pop();
		}
	} else
		return false;

	output.close();
	return true;
}

bool Company::readVehiclesFromFile() {
	string plate, brand, model, temp;

	string file = "vehicles.txt";

	ifstream input;
	input.open(file);
	if (input.is_open()) {

		while (!input.eof()) {

			getline(input, plate);

			if (plate == "")
				break;
			getline(input, brand);

			getline(input, model);

			getline(input, temp);
			Date maintenance(stoul(temp.substr(0, 2)), stoul(temp.substr(3, 2)),
					stoul(temp.substr(6)));

			getline(input, temp);
			Date birthday(stoul(temp.substr(0, 2)), stoul(temp.substr(3, 2)),
					stoul(temp.substr(6)));

			getline(input, temp);
			Hour expectable_time(stoul(temp.substr(0, 2)),
					stoul(temp.substr(3)));

			getline(input, temp);
			bool available;

			((temp[0] == 1) ? available = true : available = false);

			Vehicle v1 = Vehicle(plate, brand, model, birthday, expectable_time,
					maintenance);

			vehicles.push(v1);

			getline(input, temp);
		}

		input.close();

		return true;
	} else {
		return false;
	}
}

bool Company::checkAdminCredentials(unsigned int admin_id, string admin_pass) {
	return (this->admin_id == admin_id && this->admin_pass == admin_pass);
}
