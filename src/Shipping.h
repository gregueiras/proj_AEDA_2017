
#ifndef SHIPPING_H
#define SHIPPING_H
#include "Date.h"
#include "Hour.h"
#include <string>

/**
  * class Shipping
  * 
  */

class Shipping
{
public:

  // Constructors/Destructors
  //  
	Shipping(Date start_date, Hour start_hour, Date end_date, Hour end_hour);


  /**
   * Empty Constructor
   */
  Shipping ();

  /**
   * Empty Destructor
   */
  virtual ~Shipping ();

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  


protected:

  // Static Protected attributes
  //  

  // Protected attributes
  //  

public:


  // Protected attribute accessor methods
  //  

protected:

public:


  // Protected attribute accessor methods
  //  

protected:


private:

  // Static Private attributes
  //  

  // Private attributes
  //  

  // Date of dispatch
  Date dispatch_date;
  // Hour of dispatch
  Hour dispatch_hour;
  // Date of arrival
  Date arrival_date;
  // Hour of arrival
  Hour arrival_hour;
public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of dispatch_date
   * Date of dispatch
   * @param new_var the new value of dispatch_date
   */
  void setDispatch_date (Date new_var)   {
      dispatch_date = new_var;
  }

  /**
   * Get the value of dispatch_date
   * Date of dispatch
   * @return the value of dispatch_date
   */
  Date getDispatch_date ()  const {
    return dispatch_date;
  }

  /**
   * Set the value of dispatch_hour
   * Hour of dispatch
   * @param new_var the new value of dispatch_hour
   */
  void setDispatch_hour (Hour new_var)   {
      dispatch_hour = new_var;
  }

  /**
   * Get the value of dispatch_hour
   * Hour of dispatch
   * @return the value of dispatch_hour
   */
  Hour getDispatch_hour ()  const {
    return dispatch_hour;
  }

  /**
   * Set the value of arrival_date
   * Date of arrival
   * @param new_var the new value of arrival_date
   */
  void setArrival_date (Date new_var)   {
      arrival_date = new_var;
  }

  /**
   * Get the value of arrival_date
   * Date of arrival
   * @return the value of arrival_date
   */
  Date getArrival_date ()  const {
    return arrival_date;
  }

  /**
   * Set the value of arrival_hour
   * Hour of arrival
   * @param new_var the new value of arrival_hour
   */
  void setArrival_hour (Hour new_var)   {
      arrival_hour = new_var;
  }

  /**
   * Get the value of arrival_hour
   * Hour of arrival
   * @return the value of arrival_hour
   */
  Hour getArrival_hour () const  {
    return arrival_hour;
  }
private:


  void initAttributes () ;

};

#endif // SHIPPING_H
