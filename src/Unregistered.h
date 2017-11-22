
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
  bool Sup_pay_bank_transfer() {return true;};
  bool Sup_pay_credit_card() {return false;};
  bool Sup_pay_debit_card() {return true;};
  bool Sup_pay_eom() {return false;};

};

#endif // UNREGISTED_H
