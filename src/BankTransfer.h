
#ifndef BANKTRANSFER_H
#define BANKTRANSFER_H
#include "Payment.h"

#include <string>

/**
  * class BankTransfer
  * 
  */

class BankTransfer : public Payment
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  BankTransfer (double value);

  BankTransfer(double value, bool due, Date due_date, Hour due_hour);

  /**
   * Empty Destructor
   */
  virtual ~BankTransfer ();

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  

private:
	// ID number of the Payment
	const unsigned int payment_id = 5;

public:
	/**
	* Create new id
	* ID number of the next payment requested
	* @return the value of new id
	*/
	const unsigned int newId();

	std::string getPayType();


};

#endif // BANKTRANSFER_H
