
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
   * Empty Constructor
   */
  Unregisted ();

  /**
   * Empty Destructor
   */
  virtual ~Unregisted ();

private:
	// ID number of the client
	const unsigned int id;

	// ID number of the group
	const unsigned int client_id = 0;

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

#endif // UNREGISTED_H
