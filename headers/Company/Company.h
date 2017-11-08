
#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <vector>

#include "Client.h"
#include "Services.h"
#include "Payment.h"


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
  Company (unsigned long cost_km_m, unsigned long cost_day_in_storage);

  /**
   * Empty Destructor
   */
  virtual ~Company ();

 
private:

  // Static Private attributes
  //  

  // Cost of shipping 1 cubic metre of material for 1km.
  // Basis for calculating prices.
  static unsigned long cost_km_m;
  // Price of storing goods in the storage.
  // Service only available for registered clients.
  // Basis for calculating prices
  static unsigned long cost_day_in_storage;

  // Vector of clients of the company
  vector<Client*> clients;

  // Queue of services of the company
  vector<Services*> services_queue;

  // Regist of payments of the company's clients
  vector<Payment*> payments_regist;
public:
  /**
   * Set the value of cost_km_m
   * Cost of shipping 1 cubic metre of material for 1km.
   * Basis for calculating prices.
   * @param new_var the new value of cost_km_m
   */
	void setCost_km_m(unsigned long new_var);

  /**
   * Get the value of cost_km_m
   * Cost of shipping 1 cubic metre of material for 1km.
   * Basis for calculating prices.
   * @return the value of cost_km_m
   */
	unsigned long getCost_km_m();

  /**
   * Set the value of cost_day_in_storage
   * Price of storing goods in the storage.
   * Service only available for registered clients.
   * Basis for calculating prices
   * @param new_var the new value of cost_day_in_storage
   */
	void setCost_day_in_storage(unsigned long new_var);

  /**
   * Get the value of cost_day_in_storage
   * Price of storing goods in the storage.
   * Service only available for registered clients.
   * Basis for calculating prices
   * @return the value of cost_day_in_storage
   */
	unsigned long getCost_day_in_storage();

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
	*/
	bool getClient(unsigned int id, Client *new_var);

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

};

#endif // COMPANY_H
