#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <vector>
#include <array>
#include <queue>
#include <unordered_set>/*tr1/*/
#include "BST.h"

#include "Services.h"

#include "Client.h"
#include "Business.h"
#include "Personal.h"
#include "Unregistered.h"

#include "Payment.h"
#include "BankTransfer.h"
#include "CreditCard.h"
#include "DebitCard.h"
#include "EOMPayment.h"

#include "Vehicle.h"

struct inactiveClientsHash
{
	int operator() (const ClientRecord& cr) const
	{
		return cr.getId();
	}

	bool operator() (const ClientRecord& cr1, const ClientRecord& cr2) const
	{
		return (cr1.getId() == cr2.getId());
	}
};

typedef /*tr1::*/unordered_set<ClientRecord, inactiveClientsHash, inactiveClientsHash> HashTabClientRecord;

/**
 * class Company
 *
 */
class Company {
public:

	// Constructors/Destructors
	//

	/**
	 * Empty Constructor
	 */
	Company();

	Company(string nib, string entity, string reference);

	/**
	 * Empty Destructor
	 */
	virtual ~Company();

private:

	// Static Private attributes
	//

	//// Cost of shipping 1 cubic meter of material for 1km.
	//// Basis for calculating prices.
	//static unsigned long cost_km_m;

	//// Price of storing goods in the storage.
	//// Service only available for registered clients.
	//// Basis for calculating prices
	//static unsigned long cost_day_in_storage;

	// Vector of clients of the company
	vector<Client*> clients;

	//Hash table of inactive clients of the company
	HashTabClientRecord inactive_clients;

	// Queue of services of the company
	vector<Services*> services_queue;

	// Regist of payments of the company's clients
	BST<Payment*> payments_regist;

	//Queue of next services
	std::queue<Services*> next_services;

	//Heap of available vehicles
	std::priority_queue<Vehicle> vehicles;

	// Company nib - 21 digits
	string nib;

	// Company entity - 5 digits
	string entity;

	// Company reference - 9 digits
	string reference;

	//World Time
	//Date
	Date current_date;

	//Hour
	Hour current_hour;

public:

	/**
	 * Get the value of current_date
	 * World Time - Date
	 * @return the value of current_date
	 */
	Date getCurrentDate() const;

	/**
	 * Set the value of current_date
	 * World Time - Date
	 * @param new_var the new value of current_date
	 */
	void setCurrentDate(Date new_var);

	/**
	 * Get the value of current_hour
	 * World Time - Hour
	 * @return the value of current_hour
	 */
	Hour getCurrentHour() const;

	/**
	 * Set the value of current_hour
	 * World Time - Hour
	 * @param new_var the new value of current_hour
	 */
	void setCurrentHour(Hour new_var);

	/**
	* Get the position of client c from clients vector
	* @param c the client to find
	* @return the position if client c
	*/
	int findClient(Client* c);

	/**
	* Get a client from inactive_clients  hash table to clients vector
	* @param c the client in question
	*/
	void deactivateClientRecord(Client* c);

	/**
	* Get a client from clients vector to inactive_clients hash table
	* @param c the client in question
	*/
	void activateClientRecord(Client* c);

	/**
	 * Get the value of nib
	 * Company nib - 21 digits
	 * @return the value of nib
	 */
	string getNib() const;

	/**
	 * Set the value of nib
	 * Company nib - 21 digits
	 * @param new_var the new value of nib
	 */
	void setNib(string new_var);

	/**
	 * Get the value of entity
	 * Company entity - 5 digits
	 * @return the value of entity
	 */
	string getEntity() const;

	/**
	 * Set the value of entity
	 * Company entity - 5 digits
	 * @param new_var the new value of entity
	 */
	void setEntity(string new_var);

	/**
	 * Get the value of reference
	 * Company reference - 9 digits
	 * @return the value of reference
	 */
	string getReference() const;

	/**
	 * Set the value of reference
	 * Company reference - 9 digits
	 * @param new_var the new value of reference
	 */
	void setReference(string new_var);

	/**
	 * Set the value of clients
	 * Vector of clients of the company
	 * @param new_var the new value of clients vector
	 */
	void setClients(vector<Client*> new_var);

	/**
	 * Get the value of clients
	 * Vector of clients of the company
	 * @return the value of clients
	 */
	vector<Client*> getClients() const;

	/**
	 * Add new client to clients vector
	 * Vector of clients of the company
	 * @param new_var the new client
	 */
	bool addClient(Client *new_var);

	/**
	 * Get client from clients vector using id as reference
	 * Vector of clients of the company
	 * @param new_var the client, if found
	 * @param id the client id
	 * @param pass the client pass
	 */
	Client * getClient(unsigned int id, string pass) const;

	/**
	 * Set the vector of services_queue
	 * Queue of services of the company
	 * @param new_var the new value of services vector
	 */
	void setServicesQueue(vector<Services*> new_var);

	/**
	 * Get the vector of services_queue
	 * Queue of services of the company
	 * @return the value of services vector
	 */
	vector<Services*> getServicesQueue() const;


	/**
	 * Get the queue of next services
	 * Queue of  next services of the company
	 * @return next_services queue
	 */
	const std::queue<Services*>& getNextServices() const {
		return next_services;
	}

	/**
	 * Set the queue of next services
	 * Queue of  next services of the company
	 */
	void setNextServices(const std::queue<Services*>& nextServices) {
		next_services = nextServices;
	}

	/**
	 * Get the priority_queue of vehicles, ordered by least expectable time
	 * Queue of vehicles of the company
	 * @return vehicles priority_queue
	 */
	const std::priority_queue<Vehicle>& getVehicles() const {
		return vehicles;
	}

	/**
	 * Set the priority_queue of vehicles, ordered by least expectable time
	 * Queue of vehicles of the company
	 * @return vehicles priority_queue
	 */
	void setVehicles(const std::priority_queue<Vehicle>& vehicles) {
		this->vehicles = vehicles;
	}

	/**
	 * Add new service to services_queue vector
	 * Queue of services of the company
	 * @param new_var the new service
	 * @param client_id the client who requested the new service
	 */
	void addService(Services *new_var, unsigned int client_id);

	/**
	 * Add new payment to payments_regist BST
	 * Regist of payments of the company's clients
	 * @param new_var the new payment
	 * @param client_id the client who requested the new service
	 */
	void addPayment(Payment *new_var, unsigned int client_id);

	/**
	* Get payment pointer from payments_regist BST
	* Regist of payments of the company's clients
	* @param pay_id the payment id
	*/
	Payment* getPayment(unsigned int pay_id);

	/**
	 * Reads all the services from a file named "client" + id +"_services.txt"
	 * @param id Id of the client to be read
	 * @return Services read from file
	 */
	vector<Services*> readServicesFromFile(const unsigned int id);

	/**
	 * Reads all clients from a files named "client" + id +".txt"
	 * @return Clients read from file
	 */
	vector<Client*> readClientsFromFile();

	/**
	 * Reads a client from a file named "client" + id +".txt"
	 * @param id Id of the client to be read
	 * @return Clients read from file
	 */
	Client* readClientFromFile(const unsigned int id);

	/**
	 * Reads all the payments from a file named "client" + id +"_payments.txt"
	 * @param id Id of the client to be read
	 * @param ptr pointer of the client to be read
	 * @return Payments read from file
	 */
	vector<Payment*> readPaymentsFromFile(Client* ptr, const unsigned int id);

	/**
	 * writes client to a file named "client" + id +".txt"
	 * Vector of clients of the company
	 * @return True in case of success, false if failure
	 */
	bool writeClientsToFile();

	/**
	 * writes company to a file named "company.txt"
	 * @return True in case of success, false if failure
	 */
	bool writeCompanyToFile();

	/**
	 * read company from a file named "company.txt"
	 * @return True in case of success, false if failure
	 */
	bool readCompanyFromFile();

	/**
	 * Check if client as dues
	 * @param value the value of total due
	 * @return true if has dues
	 */
	bool checkAllDues(Client * c, double &value);

	/**
	 * Set value of due to false and change due_hour/date to current_hour/date
	 */
	void payAllDues(Client * c);

	/**
	 * If vehicle exists with that characteristics set its "available" flag to false
	 * @param brand brand of car
	 * @param model model of car
	 * @param plate plate of car
	 * @return true if that vehicle was found, false if not
	 */
	bool removeVehicleMaintenance(string brand, string model, string plate);

	/**
		 * Try to add vehicle, to vehicles priority_queue
		 * @param v1 vehicle to be added
		 * @return true if vehicle didn't exist in priority_queue, false if it already existed
		 */
	bool addVehicle(Vehicle v1);

	/**
		 * writes vehicles to a file named "vehicles.txt"
		 * @return True in case of success, false if failure
		 */
	bool writeVehiclesToFile();

	/**
		 * read vehicles from a file named "vehicles.txt"
		 * @return True in case of success, false if failure
		 */
	bool readVehiclesFromFile();
};

#endif // COMPANY_H
