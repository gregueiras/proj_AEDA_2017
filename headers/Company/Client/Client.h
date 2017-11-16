
#ifndef CLIENT_H
#define CLIENT_H
#include "Business.h"
#include "Services.h"
#include "Payment.h"

#include <string>
#include <vector>



/**
  * class Client
  * 
  */

class Client
{
public:

  // Constructors/Destructors
  //  

  /**
   * Constructor for registed clients
   */
  Client (string name, Address address, unsigned int nif, const unsigned int Id, string pass);

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
  //client id
  const unsigned int id;
  const unsigned int client_id;
  //client visibility - client is accessible if true
  bool visibility;
  //login password
  string pass;

  //supported payment methods
  const bool sup_pay_bank_transfer;
  const bool sup_pay_credit_card;
  const bool sup_pay_debit_card;
  const bool sup_pay_eom;

public:
  /**
   * get value of sup_pay_bank_transfer
   * support payment methods
   * @return true if payment method is supported
   */
  bool SupportPayBankTransfer();

  /**
   * get value of sup_pay_credit_card
   * support payment methods
   * @return true if payment method is supported
   */
  bool SupportPayCreditCard();

  /**
   * get value of sup_pay_debit_card
   * support payment methods
   * @return true if payment method is supported
   */
  bool SupportPayDebitCard();

  /**
   * get value of sup_pay_eom
   * support payment methods
   * @return true if payment method is supported
   */
  bool SupportPayEOM();

  /**
   * Set the value of visibility
   * client visibility - client is accessible if true
   * @param new_var the new value of visibility
   */
  void setVisibility (bool new_var) ;

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
  string getName ();

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
  Address getAddress ();

  /**
  * Get the value of id
  * Client ID
  * @return the value of id
  */
  const unsigned int getId();

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
  unsigned int getNif ();

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
  vector<Services*> getServices ();

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
  Services getServiceById(const unsigned int &id);

  /**
  * Get the value of next_id
  * ID number of the next client added
  * @return the value of next_id
  */
  unsigned int getNextId();

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
  vector<Payment*> getPayment();

  /**
  * Add a new payment to the client
  * History of payments of the client
  * @param new_pay the new last value of payments vector, by push_back
  */
  void addPayment(Payment *new_pay);

  /**
    * Get client info in a string
    * Client
    * @param new_var the client to get info from
    */
  string getInfoDisp(Client new_var);

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
  string getPass ();

};

#endif // CLIENT_H
