
#ifndef PAYMENT_H
#define PAYMENT_H

#include "../../Utilities/Date.h"
#include "../../Utilities/Hour.h"

#include <string>

/**
  * class Payment
  * 
  */

class Payment
{
public:

  // Constructors/Destructors
  //  


  /**
   * Constructor
   */
  Payment (double value);

  /**
   * Empty Destructor
   */
  virtual ~Payment ();

private:
	// ID number of the next payment requested
	static unsigned int next_id;

	// Payment's value
	double value;

	// Payment is due
	bool due;

	//Payment due date
	Date due_date;

	//Payment due hour
	Hour due_hour;

public:
	/**
	* Get the value of next_id
	* ID number of the next payment requested
	* @return the value of next_id
	*/
	unsigned int getNextId();

	/**
	* ++next_id
	* ID number of the next payment requested
	*/
	void incNextId();

	/**
	* Create new id
	* ID number of the next payment requested
	* @return the value of new id
	*/
	virtual const unsigned int newId() = 0;

	/**
	 * Set value of due
	 * Payment is due
	 * @param new_var the value of due
	 */
	 void setDue(bool new_var);

	 /**
	  * Set value of due
	  * Payment is due
	  * @return the value of due
	  */
	 bool isDue();

	 /**
	 * Set value of due_date
	 * Payment due date
	 * @param new_var the value of due_date
	 */
	 void setDueDate(Date new_var);

	 /**
	 * Set value of due_date
	 * Payment due date
	 * @return the value of due_date
	 */
	 Date getDueDate();

	 /**
	 * Set value of due_hour
	 * Payment due hour
	 * @param new_var the value of due_hour
	 */
	 void setDueHour(Hour new_var);

	 /**
	 * Set value of due_hour
	 * Payment due hour
	 * @return the value of due_hour
	 */
	 Hour getDueHour();
};

#endif // PAYMENT_H
