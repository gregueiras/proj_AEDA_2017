
#ifndef EOMPAYMENT_H
#define EOMPAYMENT_H
#include "Date.h"
#include "Hour.h"

#include <string>

using namespace std;

/**
  * class EOMPayment
  * 
  */

class EOMPayment
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */

	EOMPayment();

  EOMPayment(bool due, Date due_date, Hour due_hour);

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
	//Due is not cleared
	bool due;

	//Limit Date for Payment
	Date due_date;

	//Limit Hour for Payment
	Hour due_hour;

public:
	
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
	bool getDue();

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

	/**
	* Get EOMPayment 
	* @return string with EOMPayment
	*/
	string getEOMPaymentToWrite();

};

#endif // EOMPayment_H
