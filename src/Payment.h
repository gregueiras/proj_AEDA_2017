
#ifndef PAYMENT_H
#define PAYMENT_H

#include "Date.h"
#include "Hour.h"

#include <string>

using namespace std;

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

  Payment(double value);

  Payment(double value, bool due, Date due_date, Hour due_hour);

  /**
   * Empty Destructor
   */
  virtual ~Payment ();

private:
	// Biil ID Number
	const unsigned int id;

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
	* Get the value of id
	* Biil ID Number
	* @return the value of id
	*/
	unsigned int getId() const;

	/**
	* Get the value of next_id
	* ID number of the next payment requested
	* @return the value of next_id
	*/
	unsigned int getNextId() const;

	/**
	 * Set value of due
	 * Payment is due
	 * @param new_var the value of due
	 */
	 void setDue(bool new_var);

	 /**
	  * Get value of due
	  * Payment is due
	  * @return the value of due
	  */
	 bool getDue() const;

	 /**
	 * Set value of due_date
	 * Payment due date
	 * @param new_var the value of due_date
	 */
	 void setDueDate(Date new_var);

	 /**
	 * Get value of due_date
	 * Payment due date
	 * @return the value of due_date
	 */
	 Date getDueDate() const;

	 /**
	 * Get value of value
	 * Payment's value
	 * @return the value of value
	 */
	 double getValue();

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
	 Hour getDueHour() const;

	 /**
	 * Get string with payment type
	 * @return subclass payment 
	 */
	 virtual string getPayType() = 0;
};

class PaymentRecord {
	// Biil ID Number
	unsigned int id;

	//Client's name
	string name;

	//Pointer to Payment
	Payment* ptr;

public:
	//Constructor
	PaymentRecord(string name, Payment* ptr);

	PaymentRecord(unsigned int ident);

	/**
	* Get the value of name
	* Client's name
	* @return the value of name
	*/
	string getName() const;

	/**
	* Set the value of name
	* Client's name
	* @param new_var the value of name
	*/
	void setName(string new_var);

	unsigned int getId() const;

	bool getDue() const;

	Date getDueDate() const;

	Hour getDueHour() const;

	//Operators overload
	bool operator<(const PaymentRecord &pr1) const;
	bool operator==(const PaymentRecord &pr1) const;

};

#endif // PAYMENT_H
