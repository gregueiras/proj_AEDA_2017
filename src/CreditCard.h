
#ifndef CREDITCARD_H
#define CREDITCARD_H
#include "Payment.h"

#include <string>

/**
  * class CreditCard
  * 
  */

class CreditCard : public Payment
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  CreditCard (double value);

  CreditCard (double value, bool due, Date due_date, Hour due_hour);

  /**
   * Empty Destructor
   */
  virtual ~CreditCard ();

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
	const unsigned int payment_id = 3;


public:
	/**
	* Create new id
	* ID number of the next payment requested
	* @return the value of new id
	*/
	const unsigned int newId();

	std::string getPayType();
};

#endif // CREDITCARD_H
