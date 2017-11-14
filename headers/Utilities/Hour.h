
#ifndef HOUR_H
#define HOUR_H

#include <string>
#include <iostream>
/**
  * class Hour
  * 
  */

class Hour
{
public:

  // Constructors/Destructors
  //  
  Hour(unsigned int h, unsigned int m);

  Hour(unsigned int h, unsigned int m, bool b);

  /**
   * Empty Constructor
   */
  Hour ();

  /**
   * Empty Destructor
   */
  virtual ~Hour ();

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

  // Hour
  unsigned int hour;
  // Minute
  unsigned int minute;
public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of hour
   * Hour
   * @param new_var the new value of hour
   */
  void setHour (unsigned int new_var)   {
      hour = new_var;
  }

  /**
   * Get the value of hour
   * Hour
   * @return the value of hour
   */
  unsigned int getHour ()  const {
    return hour;
  }

  /**
   * Set the value of minute
   * Minute
   * @param new_var the new value of minute
   */
  void setMinute (unsigned int new_var)   {
      minute = new_var;
  }

  /**
   * Get the value of minute
   * Minute
   * @return the value of minute
   */
  unsigned int getMinute () const  {
    return minute;
  }
private:


  void initAttributes () ;

public:



};

std::ostream & operator<< (std::ostream &o, const Hour& h1);
class HourInvalidHour {
private:
	unsigned int hour;

public:
	HourInvalidHour(unsigned int hour) { this->hour = hour; }
};

class HourInvalidMinute {
private:
	unsigned int minute;

public:
	HourInvalidMinute(unsigned int minute) { this->minute = minute; }
};

#endif // HOUR_H
