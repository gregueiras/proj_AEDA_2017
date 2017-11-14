
#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
#include "hour.h"
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

unsigned int operator-(const Date& d1, const Date& d2);
Date operator+(const Date& d1, const Hour& h1);
Date operator+(const Hour& h1 ,const Date& d1);

Date operator+(const unsigned int days, const Date& d1);
Date operator+(const Date& d1, const unsigned int days);


/**
 * Transforms a Date into a integer, counting from 01-01-0001
 * Uses the Rada Die format, https://en.wikipedia.org/wiki/Rata_Die
 * https://www.researchgate.net/publication/316558298_Date_Algorithms#pf2a
 * Rata Die Date
 * @param d1 date to be converted
 * @return no. of days from 01-01-0001 to d1
 */
int rdn(Date d1);




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
