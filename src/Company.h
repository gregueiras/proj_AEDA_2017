
#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <vector>
#include <array>

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


/**
  * class Company
  * 
  */
class Company
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Company ();

  Company(string nib, string entity, string reference);

  /**
   * Empty Destructor
   */
  virtual ~Company ();

 
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

  // Queue of services of the company
  vector<Services*> services_queue;

  // Regist of payments of the company's clients
  vector<Payment*> payments_regist;

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
	Date getCurrentDate();

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
	Hour getCurrentHour();

	/**
	* Set the value of current_hour
	* World Time - Hour
	* @param new_var the new value of current_hour
	*/
	void setCurrentHour(Hour new_var);

	/**
	* Get the value of nib
	* Company nib - 21 digits
	* @return the value of nib
	*/
	string getNib();

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
	string getEntity();

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
	string getReference();

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
	vector<Client*> getClients();

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
	Client * getClient(unsigned int id, string pass);

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
	vector<Services*> getServicesQueue();

	/**
	* Add new service to services_queue vector
	* Queue of services of the company
	* @param new_var the new service
	* @param client_id the client who requested the new service
	*/
	void addService(Services *new_var, unsigned int client_id);

	/**
	* Add new payment to payments_regist vector
	* Regist of payments of the company's clients
	* @param new_var the new payment
	* @param client_id the client who requested the new service
	*/
	void addPayment(Payment *new_var, unsigned int client_id);

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
	* @return Payments read from file
	*/
	vector<Payment*> readPaymentsFromFile(const unsigned int id);

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
	bool checkAllDues(Client * c, double & value);

	/**
	* Set value of due to false and change due_hour/date to current_hour/date
	*/
	void payAllDues(Client * c);

};

#endif // COMPANY_H
