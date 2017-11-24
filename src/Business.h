
#ifndef BUSINESS_H
#define BUSINESS_H
#include "Client.h"
#include "Address.h"

#include <string>
using std::string;
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

  Business(string name, Address address, unsigned int nif, string passwd, unsigned int id);

  /**
   * Empty Destructor
   */
  virtual ~Business ();

private:
  

public:
	
  bool Sup_pay_bank_transfer() {return true;};
  bool Sup_pay_credit_card() {return true;};
  bool Sup_pay_debit_card() {return true;};
  bool Sup_pay_eom() {return true;};

  std::string getClientType();

  };

#endif // BUSINESS_H
