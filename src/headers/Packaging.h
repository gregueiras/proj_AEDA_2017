
#ifndef PACKAGING_H
#define PACKAGING_H
#include "Date.h"
#include "Hour.h"
#include <string>

/**
  * class Packaging
  * 
  */

class Packaging
{
public:

  // Constructors/Destructors
  //  
	Packaging(Date start_date, Hour start_hour, Date end_date, Hour end_hour);


  /**
   * Empty Constructor
   */
  Packaging ();

  /**
   * Empty Destructor
   */
  virtual ~Packaging ();

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

  // Date of start packaging
  Date start_date;
  // Hour of start
  Hour start_hour;
  // Date of end of packaging
  Date end_date;
  // Hour of end of packaging
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
   * Date of start packaging
   * @param new_var the new value of start_date
   */
  void setStart_date (Date new_var)   {
      start_date = new_var;
  }

  /**
   * Get the value of start_date
   * Date of start packaging
   * @return the value of start_date
   */
  Date getStart_date () const{
    return start_date;
  }

  /**
   * Set the value of start_hour
   * Hour of start
   * @param new_var the new value of start_hour
   */
  void setStart_hour (Hour new_var)   {
      start_hour = new_var;
  }

  /**
   * Get the value of start_hour
   * Hour of start
   * @return the value of start_hour
   */
  Hour getStart_hour () const  {
    return start_hour;
  }

  /**
   * Set the value of end_date
   * Date of end of packaging
   * @param new_var the new value of end_date
   */
  void setEnd_date (Date new_var)   {
      end_date = new_var;
  }

  /**
   * Get the value of end_date
   * Date of end of packaging
   * @return the value of end_date
   */
  Date getEnd_date () const  {
    return end_date;
  }

  /**
   * Set the value of end_hour
   * Hour of end of packaging
   * @param new_var the new value of end_hour
   */
  void setEnd_hour (Hour new_var)   {
      end_hour = new_var;
  }

  /**
   * Get the value of end_hour
   * Hour of end of packaging
   * @return the value of end_hour
   */
  Hour getEnd_hour () const  {
    return end_hour;
  }
private:


  void initAttributes () ;

};

#endif // PACKAGING_H
