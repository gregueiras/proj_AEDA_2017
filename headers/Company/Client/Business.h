
#ifndef BUSINESS_H
#define BUSINESS_H
#include "Client.h"


#include <string>

/**
  * class Business
  * 
  */

class Business : public Client
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Business (string name, Address address, unsigned int nif);

  /**
   * Empty Destructor
   */
  virtual ~Business ();

private:
  // ID number of the client - last digit 2
  const unsigned int id;

  // ID number of the group
  const unsigned int client_id = 2;

public:
	/**
	* Get the value of id
	* ID number of the client
	* @return the value of id
	*/
	const unsigned int getId();

	/**
	* Create new id
	* ID number of the client
	* @return the value of new id
	*/
	const unsigned int newId();


};

#endif // BUSINESS_H
