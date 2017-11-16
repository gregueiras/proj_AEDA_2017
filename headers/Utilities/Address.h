
#ifndef ADDRESS_H
#define ADDRESS_H


#include <string>
#include "GPS.h"
#include <vector>
#include <iostream>
#include <sstream>


/**
  * class Address
  * 
  */

class Address
{
public:

  // Constructors/Destructors
  //  
  Address (std::string street, std::string country, std::string city, std::string county, unsigned int door_number, double lat, double lon);
  Address (std::string street, std::string country, std::string city, std::string county, unsigned int door_number);


  /**
   * Empty Constructor
   */
  Address ();

  /**
   * Empty Destructor
   */
  virtual ~Address ();

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

  GPS coordinates;
  std::string street;
  std::string country;
  std::string city;
  std::string county;
  unsigned int door_number;
public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of coordinates
   * @param lat latitude
   * @param lon longitude
   */
  void setCoordinates (double lat, double lon)   {
	  GPS a(lat, lon);
      this->coordinates = a;
  }

  /**
   * Set the value of coordinates
   * @param GPS coordinates
   *
   */
  void setCoordinates (GPS gp1)   {
	  this->coordinates = gp1;
  }

  /**
   * Get the value of coordinates
   * @return the value of coordinates
   */
  GPS getCoordinates () const  {
    return coordinates;
  }

  /**
   * Set the value of street
   * @param new_var the new value of street
   */
  void setStreet (std::string new_var)   {
      street = new_var;
  }

  /**
   * Get the value of street
   * @return the value of street
   */
  std::string getStreet ()  const {
    return street;
  }

  /**
   * Set the value of country
   * @param new_var the new value of country
   */
  void setCountry (std::string new_var)   {
      country = new_var;
  }

  /**
   * Get the value of country
   * @return the value of country
   */
  std::string getCountry () const  {
    return country;
  }

  /**
   * Set the value of city
   * @param new_var the new value of city
   */
  void setCity (std::string new_var)   {
      city = new_var;
  }

  /**
   * Get the value of city
   * @return the value of city
   */
  std::string getCity ()  const {
    return city;
  }

  /**
   * Set the value of county
   * @param new_var the new value of county
   */
  void setCounty (std::string new_var)   {
      county = new_var;
  }

  /**
   * Get the value of county
   * @return the value of county
   */
  std::string getCounty ()  const {
    return county;
  }

  /**
   * Set the value of door_number
   * @param new_var the new value of door_number
   */
  void setDoor_number (unsigned int new_var)   {
      door_number = new_var;
  }

  /**
   * Get the value of door_number
   * @return the value of door_number
   */
  unsigned int getDoor_number () const  {
    return door_number;
  }
private:


  void initAttributes () ;

public:

  /**
   * If city is a district capital of Portugal, returns true and sets its coordinates to gps. Else, returns false
   * @return true if city is in list, false if city is not
   */
  bool cityToGPS();

  /**
   * @return a string with Address Information
   */
  std::string toStr();


};





/**
 * Auxiliary function, to compare a city with a pair <string, GPS>
 * @param city City to be searched
 * @param city2 Pair to compare with city
 * @return Returns true if city1 == city2.first()
 */
bool auxSearch(const std::string city,const std::pair<std::string, GPS> city2);

std::ostream& operator<< (std::ostream& o, const Address& c);
bool operator== (const Address & c1, const Address & c2);
bool operator!= (const Address & c1, const Address & c2);



#endif // ADDRESS_H
