
#ifndef EOMPAYMENT_H
#define EOMPAYMENT_H
#include "Payment.h"

#include <string>

/**
  * class EOMPayment
  * 
  */

class EOMPayment : public Payment
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  EOMPayment (double value);

  EOMPayment(double value, bool due, Date due_date, Hour due_hour);

  /**
   * Empty Destructor
   */
  virtual ~EOMPayment ();

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

#endif // EOMPayment_H
