
#ifndef DELIVERY_H
#define DELIVERY_H
#include "Services.h"

#include <string>

/**
  * class Delivery
  * 
  */

class Delivery : public Services
{
public:

  // Constructors/Destructors
  //  


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
  Date getStart_date ()   {
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
  Hour getStart_hour ()   {
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
  Date getEnd_date ()   {
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
  Hour getEnd_hour ()   {
    return end_hour;
  }
private:


  void initAttributes () ;

};

#endif // DELIVERY_H
