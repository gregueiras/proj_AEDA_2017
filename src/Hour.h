
#ifndef HOUR_H
#define HOUR_H

#include <string>
#include <iostream>
#include <sstream>


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

	unsigned int hour; /*!< Hour*/
	unsigned int minute; /*!< Minute*/
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


	bool operator<(const Hour &v1) const;

private:


	void initAttributes () ;

public:

	std::string toStr() const;

};


/**
 * Overload of operator<<, to send an Hour to a ostream, in format HH:MM
 * @param o ostream
 * @param c Hour to be sent
 * @return Returns the ostream
 */
std::ostream & operator<< (std::ostream &o, const Hour& h1);


/**
 * Overload of operator+, to add 2 Hours
 * @param h1 lhs hour
 * @param h2 rhs hour
 * @return Returns a new hour, with the sum of 2 hours
 */
Hour operator+(const Hour& h1, const Hour& h2);

/**
 * Overload of operator-, to subtract 2 Hours
 * @param h1 lhs hour
 * @param h2 rhs hour
 * @return Returns a new hour, with the difference between 2 hours
 */
Hour operator-(const Hour& h1, const Hour& h2);

/**
 * Overload of operator+, to add an Hour to an amount of hours
 * @param h1 lhs hour
 * @param add amount of hours to be added
 * @return Returns a new hour, with the sum
 */
Hour operator+(const Hour& h1, const unsigned int add);

/**
 * Overload of operator+, to add an Hour to an amount of hours
 * @param add amount of hours to be added
 * @param h1 rhs hour
 * @return Returns a new hour, with the sum
 */
Hour operator+(const unsigned int add ,const Hour& h1);



/**
 * class HourInvalidHour
 *
 */
class HourInvalidHour {
private:
	unsigned int hour;

public:
	HourInvalidHour(unsigned int hour) { this->hour = hour; }
};

/**
 * class HourInvalidMinute
 *
 */
class HourInvalidMinute {
private:
	unsigned int minute;

public:
	HourInvalidMinute(unsigned int minute) { this->minute = minute; }
};

#endif // HOUR_H
