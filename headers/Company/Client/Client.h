
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

class Client : public Business
{
public:

  // Constructors/Destructors
  //  

  /**
   * Constructor for registed clients
   */
  Client (string name, Address address, unsigned int nif);

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

public:
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
  virtual const unsigned int newId() = 0;

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
};

#endif // CLIENT_H
