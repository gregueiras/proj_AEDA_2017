
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

  bool Sup_pay_bank_transfer() {return true;};
  bool Sup_pay_credit_card() {return false;};
  bool Sup_pay_debit_card() {return true;};
  bool Sup_pay_eom() {return false;};

};

#endif // PERSONAL_H
