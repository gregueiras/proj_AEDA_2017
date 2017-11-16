
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
	Personal (string name, Address address, unsigned int nif, string passwd);

  /**
   * Empty Destructor
   */
  virtual ~Personal ();

private:

public:

};

#endif // PERSONAL_H
