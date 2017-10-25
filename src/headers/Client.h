
#ifndef CLIENT_H
#define CLIENT_H
#include "Business.h"

#include <string>
#include vector



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
   * Empty Constructor
   */
  Client ();

  /**
   * Empty Destructor
   */
  virtual ~Client ();

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  


protected:

  // Static Protected attributes
  //  

  // Protected attributes
  //  

public:


  // Protected attribute accessor methods
  //  

protected:

public:


  // Protected attribute accessor methods
  //  

protected:


private:

  // Static Private attributes
  //  

  // Private attributes
  //  

  // Name/company of the client
  string name;
  // Adress of the client
  Address address;
  // NIF of the client
  string nif;
  // History of services of the client
  vector<Services> services;
public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of name
   * Name/company of the client
   * @param new_var the new value of name
   */
  void setName (string new_var)   {
      name = new_var;
  }

  /**
   * Get the value of name
   * Name/company of the client
   * @return the value of name
   */
  string getName ()   {
    return name;
  }

  /**
   * Set the value of address
   * Adress of the client
   * @param new_var the new value of address
   */
  void setAddress (Address new_var)   {
      address = new_var;
  }

  /**
   * Get the value of address
   * Adress of the client
   * @return the value of address
   */
  Address getAddress ()   {
    return address;
  }

  /**
   * Set the value of nif
   * NIF of the client
   * @param new_var the new value of nif
   */
  void setNif (string new_var)   {
      nif = new_var;
  }

  /**
   * Get the value of nif
   * NIF of the client
   * @return the value of nif
   */
  string getNif ()   {
    return nif;
  }

  /**
   * Set the value of services
   * History of services of the client
   * @param new_var the new value of services
   */
  void setServices (vector<Services> new_var)   {
      services = new_var;
  }

  /**
   * Get the value of services
   * History of services of the client
   * @return the value of services
   */
  vector<Services> getServices ()   {
    return services;
  }
private:


  void initAttributes () ;

};

#endif // CLIENT_H
