
#ifndef PERSONAL_H
#define PERSONAL_H
#include "Client.h"

#include <string>

/**
  * class Personal
  * 
  */

class Personal : public Client
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
	Personal (string name, Address address, unsigned int nif);

  /**
   * Empty Destructor
   */
  virtual ~Personal ();

private:
	// ID number of the client - last digit 1
	// ID number of the group
	const unsigned int client_id = 1;
public:
	/**
	* Create new id
	* ID number of the client
	* @return the value of new id
	*/
	const unsigned int newId();


};

#endif // PERSONAL_H
