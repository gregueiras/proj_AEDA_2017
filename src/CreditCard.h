
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
};

#endif // CREDITCARD_H
