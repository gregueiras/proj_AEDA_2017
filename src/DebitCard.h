
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
  DebitCard (double value, unsigned int service_id);

  DebitCard (double value, unsigned int service_id, bool due, Date due_date, Hour due_hour);

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

	std::string getPayType();


};

#endif // DEBITCARD_H
