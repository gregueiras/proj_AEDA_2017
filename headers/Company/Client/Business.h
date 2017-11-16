
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
   * Constructor
   */
  Business (string name, Address address, unsigned int nif, string passwd);

  /**
   * Empty Destructor
   */
  virtual ~Business ();

private:
  

public:
	

};

#endif // BUSINESS_H
