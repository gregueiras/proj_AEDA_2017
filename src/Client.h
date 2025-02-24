
#ifndef CLIENT_H
#define CLIENT_H

#include "Services.h"
#include "Payment.h"
#include "Address.h"
#include <string>
#include <vector>
#include <fstream>

using std::vector;
using std::string;


/**
  * class Client
  * 
  */

class Client
{

//	friend class Unregistered;
//	friend class Business;
//	friend class Personal;
public:

	friend class ClientRecord;
  // Constructors/Destructors
  //  

  /**
   * Constructor for registed clients
   */

	Client (string name, Address address, unsigned int nif, string pass);

	Client(string name, Address address, unsigned int nif, string pass, unsigned int id);

  /**
   * Empty Destructor
   */
  virtual ~Client ();


private:
  // Static Private attributes
  //
  // ID number of the next client added
  static unsigned int next_id;
  // Private attributes
  //  
  // Name/company of the client
  string name;
  // Adress of the client
  Address address;
  // NIF of the client
  unsigned int nif;
  // History of services of the client
  vector<Services*> services;
  // History of payments of the client
  vector<Payment*> payments;

  string pass;

private:
  //supported payment methods
  virtual bool Sup_pay_bank_transfer() = 0;
  virtual bool Sup_pay_credit_card()= 0;
  virtual bool Sup_pay_debit_card()= 0;
  virtual bool Sup_pay_eom() = 0;
  //client id
   unsigned int id;
//   unsigned int client_id;
   //client visibility - client is accessible if true
   bool visibility;
   //login password

public:
//  /**
//   * get value of sup_pay_bank_transfer
//   * support payment methods
//   * @return true if payment method is supported
//   */
//  bool SupportPayBankTransfer();
//
//  /**
//   * get value of sup_pay_credit_card
//   * support payment methods
//   * @return true if payment method is supported
//   */
//  bool SupportPayCreditCard();
//
//  /**
//   * get value of sup_pay_debit_card
//   * support payment methods
//   * @return true if payment method is supported
//   */
//  bool SupportPayDebitCard();
//
//  /**
//   * get value of sup_pay_eom
//   * support payment methods
//   * @return true if payment method is supported
//   */
//  bool SupportPayEOM();

  /**
   * Set the value of visibility
   * client visibility - client is accessible if true
   * @param new_var the new value of visibility
   */
  void setVisibility (bool new_var) ;

  /**
   * Get the value of visibility
   * client visibility - client is accessible if true
   * @return the value of visibility
   */
  bool getVisibility() const;

  /**
   * Set the value of name
   * Name/company of the client
   * @param new_name the new value of name
   */
  void setName (string new_name) ;
  /**
   * Get the value of name
   * Name/company of the client
   * @return the value of name
   */
  string getName () const;

  /**
   * Set the value of address
   * Adress of the client
   * @param new_add the new value of address
   */
  void setAddress (Address new_add);

  /**
   * Get the value of address
   * Address of the client
   * @return the value of address
   */
  Address getAddress () const;

  /**
  * Get the value of id
  * Client ID
  * @return the value of id
  */
  unsigned int getId() const;

  /**
   * Set the value of nif
   * NIF of the client
   * @param new_nif the new value of nif
   */
  void setNif (unsigned int new_nif);

  /**
   * Get the value of nif
   * NIF of the client
   * @return the value of nif
   */
  unsigned int getNif () const;

  /**
   * Set the value of services
   * History of services of the client
   * @param new_var the new value of services
   */
  void setServices (vector<Services*> new_serv_vec);

  /**
   * Get the value of services
   * History of services of the client
   * @return the value of services
   */
  vector<Services*> getServices () const;

  /**
    * Add a new service to the client
    * History of services of the client
    * @param new_serv the new last value of services vector, by push_back
    */
  void addServices (Services *new_serv);

  /**
  * Get service based on id
  * History of services of the client
  * @param id the service to get id
  * @return the service with this->id == id or service with volume == 0 if not found any 
  */
  Services getServiceById(const unsigned int &id) const;

  /**
  * Get last service based on date
  * History of services of the client
  * @return the pointer of service with the most recent date
  */
  Services* getClientLastService();

  /**
  * Get the value of next_id
  * ID number of the next client added
  * @return the value of next_id
  */
  unsigned int getNextId();

  /**
  * Set the value of next_id
  * ID number of the next client added
  * @param n_id the new value of next_id
  */
  void setNextId(unsigned int n_id);

  /**
  * ++next_id
  * ID number of the next client added
  */
  void incNextId();

  /**
  * Create new id
  * ID number of the client
  * @return the value of new id
  */
  const unsigned int newId();

  /**
  * Set the value of poyments
  * History of payments of the client
  * @param new_var the new value of services
  */
  void setPayment(vector<Payment*> new_pay_vec);

  /**
  * Get the value of payments
  * History of payments of the client
  * @return the value of payments
  */
  vector<Payment*> getPayment() const;

  /**
  * Add a new payment to the client
  * History of payments of the client
  * @param new_pay the new last value of payments vector, by push_back
  */
  void addPayment(Payment *new_pay);

  /**
  * get payment id
  * History of payments of the client
  * @param s_id the id of the payment service
  * @return the value of the payment id
  */
  unsigned int getPaymentId(unsigned int s_id);

  /**
    * Get client info in a string
    * Client
    */
  string getInfoDisp() const;

  /**
   * Set the value of pass
   * Login password
   * @param new_var the new value of pass
   */
  void setPass (string new_var);

  /**
   * Get the value of pass
   * Login password
   * @return the value of pass
   */
  string getPass () const;

  /**
  * writes all the services to a file named "client" + id +"_services.txt"
  * @return True in case of success, false if failure
  */
  bool writeServicesToFile();

  /**
  * writes all the payments to a file named "client" + id +"_payments.txt"
  * @return True in case of success, false if failure
  */
  bool writePaymentsToFile();

  /**
  * writes client to a file named "client" + id +".txt"
  * @return True in case of success, false if failure
  */
  bool writeClientToFile();

  /**
  * get client's info into a string
  * @param service says if string should include service's info
  * @return string with client's info
  */
  string clientToString(bool service);

  /**
  * Get string with Client type
  * @return subclass payment
  */
  virtual std::string getClientType() = 0;

};

class ClientRecord {
	Client* clientPtr;
	unsigned int id;
public:
	ClientRecord(Client* c);
	ClientRecord(unsigned int id);

	Client* getClientPtr();

	bool getVisibility() const;
	void setVisibility(bool new_var);

	string getName() const;

	Address getAddress() const;

	unsigned int getId() const;
	void setId(unsigned int new_id);

	unsigned int getNif() const;

	vector<Services*> getServices() const;

	vector<Payment*> getPayment() const;

	string getPass() const;
};

#endif // CLIENT_H
