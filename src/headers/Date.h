
#ifndef DATE_H
#define DATE_H

#include <string>

/**
  * class Date
  * 
  */

class Date
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Date ();

  /**
   * Empty Destructor
   */
  virtual ~Date ();

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

  // Day
  unsigned int day;
  // Month
  unsigned int month;
  // Year
  unsigned int year;
public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of day
   * Day
   * @param new_var the new value of day
   */
  void setDay (unsigned int new_var)   {
      day = new_var;
  }

  /**
   * Get the value of day
   * Day
   * @return the value of day
   */
  unsigned int getDay ()   {
    return day;
  }

  /**
   * Set the value of month
   * Month
   * @param new_var the new value of month
   */
  void setMonth (unsigned int new_var)   {
      month = new_var;
  }

  /**
   * Get the value of month
   * Month
   * @return the value of month
   */
  unsigned int getMonth ()   {
    return month;
  }

  /**
   * Set the value of year
   * Year
   * @param new_var the new value of year
   */
  void setYear (unsigned int new_var)   {
      year = new_var;
  }

  /**
   * Get the value of year
   * Year
   * @return the value of year
   */
  unsigned int getYear ()   {
    return year;
  }
private:


  void initAttributes () ;

};

#endif // DATE_H
