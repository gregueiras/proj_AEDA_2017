
#ifndef UNREGISTED_H
#define UNREGISTED_H
#include "Client.h"

#include <string>

/**
  * class Unregisted
  * 
  */

class Unregisted : public Client
{
public:

  // Constructors/Destructors
  //  


  /**
   * Constructor
   */
	Unregisted (string name, Address address, unsigned int nif);

  /**
   * Empty Destructor
   */
  virtual ~Unregisted ();

private:
	// ID number of the client

	// ID number of the group
	const unsigned int client_id = 0;

public:
	/**
	* Create new id
	* ID number of the client
	* @return the value of new id
	*/
	const unsigned int newId();


};

#endif // UNREGISTED_H
