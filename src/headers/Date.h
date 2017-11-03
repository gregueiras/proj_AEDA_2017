
#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
/**
  * class Date
  * 
  */

class Date
{
public:

  // Constructors/Destructors
  //  

	Date(unsigned int d, unsigned int m, unsigned int y);

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
  unsigned int getDay () const  {
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
  unsigned int getMonth () const  {
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
  unsigned int getYear () const  {
    return year;
  }
private:


  void initAttributes () ;


public:

  //Other methods
  //


};



bool operator== (const Date& d1, const Date& d2);
std::ostream & operator<< (std::ostream &o, const Date& d1);

bool operator< (const Date& d1, const Date& d2);
bool operator> (const Date& d1, const Date& d2);







class DateInvalidDay {
private:
	unsigned int day;

public:
	DateInvalidDay(unsigned int day) { this->day= day; }
};

class DateInvalidMonth {
private:
	unsigned int month;

public:
	DateInvalidMonth(unsigned int month) { this->month = month; }
};

class DateInvalidYear {
private:
	unsigned int year;

public:
	DateInvalidYear(unsigned int year) { this->year= year; }
};



#endif // DATE_H
