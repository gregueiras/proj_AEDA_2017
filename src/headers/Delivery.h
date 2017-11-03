
#ifndef DELIVERY_H
#define DELIVERY_H
#include "Date.h"
#include "Hour.h"
#include <string>

/**
  * class Delivery
  * 
  */

class Delivery
{
public:

  // Constructors/Destructors
  //  

	Delivery(Date start_date, Hour start_hour, Date end_date, Hour end_hour);

  /**
   * Empty Constructor
   */
  Delivery ();

  /**
   * Empty Destructor
   */
  virtual ~Delivery ();

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
  // Date of start of delivery
  Date start_date;
  // Hour of start of delivery
  Hour start_hour;
  // Date of end of delivery
  Date end_date;
  // Hour of end of delivery
  Hour end_hour;

public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of start_date
   * Date of start of delivery
   * @param new_var the new value of start_date
   */
  void setStart_date (Date new_var)   {
      start_date = new_var;
  }

  /**
   * Get the value of start_date
   * Date of start of delivery
   * @return the value of start_date
   */
  Date getStart_date ()  const {
    return start_date;
  }

  /**
   * Set the value of start_hour
   * Hour of start of delivery
   * @param new_var the new value of start_hour
   */
  void setStart_hour (Hour new_var)   {
      start_hour = new_var;
  }

  /**
   * Get the value of start_hour
   * Hour of start of delivery
   * @return the value of start_hour
   */
  Hour getStart_hour () const  {
    return start_hour;
  }

  /**
   * Set the value of end_date
   * Date of end of delivery
   * @param new_var the new value of end_date
   */
  void setEnd_date (Date new_var)   {
      end_date = new_var;
  }

  /**
   * Get the value of end_date
   * Date of end of delivery
   * @return the value of end_date
   */
  Date getEnd_date () const  {
    return end_date;
  }

  /**
   * Set the value of end_hour
   * Hour of end of delivery
   * @param new_var the new value of end_hour
   */
  void setEnd_hour (Hour new_var)   {
      end_hour = new_var;
  }

  /**
   * Get the value of end_hour
   * Hour of end of delivery
   * @return the value of end_hour
   */
  Hour getEnd_hour ()  const {
    return end_hour;
  }

private:

  friend class Services;
  void initAttributes () ;

};

#endif // DELIVERY_H
