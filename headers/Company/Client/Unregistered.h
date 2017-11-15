
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
	// ID number of the client

	// ID number of the group
	const unsigned int client_id = 3;

	//support payment methods
	const bool sup_pay_bank_transfer = true;
	const bool sup_pay_credit_card = false;
	const bool sup_pay_debit_card = true;
	const bool sup_pay_eom = false;

public:
	/**
	* Create new id
	* ID number of the client
	* @return the value of new id
	*/
	const unsigned int newId();

	/**
	 * get value of sup_pay_bank_transfer
	 * support payment methods
	 * @return true if payment method is supported
	 */
	bool SupportPayBankTransfer();

	/**
	 * get value of sup_pay_credit_card
	 * support payment methods
	 * @return true if payment method is supported
	 */
	bool SupportPayCreditCard();

	/**
	 * get value of sup_pay_debit_card
	 * support payment methods
	 * @return true if payment method is supported
	 */
	bool SupportPayDebitCard();

	/**
	 * get value of sup_pay_eom
	 * support payment methods
	 * @return true if payment method is supported
	 */
	bool SupportPayEOM();
};

#endif // UNREGISTED_H
