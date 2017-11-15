
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
	// ID number of the client - last digit 1
	// ID number of the group
	const unsigned int client_id = 1;

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

#endif // PERSONAL_H
