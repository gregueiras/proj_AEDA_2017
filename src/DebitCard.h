
#ifndef DEBITCARD_H
#define DEBITCARD_H
#include "Payment.h"

#include <string>

/**
  * class DebitCard
  * 
  */

class DebitCard : public Payment
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  DebitCard (double value);

  /**
   * Empty Destructor
   */
  virtual ~DebitCard ();

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
	const unsigned int payment_id = 4;

public:
	/**
	* Create new id
	* ID number of the next payment requested
	* @return the value of new id
	*/
	const unsigned int newId();


};

#endif // DEBITCARD_H
