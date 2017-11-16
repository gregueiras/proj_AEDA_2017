
#ifndef UNREGISTERED_H
#define UNREGISTERED_H
#include "Client.h"

#include <string>

/**
  * class Unregisted
  * 
  */

class Unregistered : public Client
{
public:

  // Constructors/Destructors
  //  


  /**
   * Constructor
   */
	Unregistered (string name, Address address, unsigned int nif, string passwd);

  /**
   * Empty Destructor
   */
  virtual ~Unregistered ();

private:
	

public:


};

#endif // UNREGISTED_H
