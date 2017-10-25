
#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

/**
  * class Address
  * 
  */

class Address
{
public:

  // Constructors/Destructors
  //  


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
  string street;
  string country;
  string city;
  string county;
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
   * @param new_var the new value of coordinates
   */
  void setCoordinates (GPS new_var)   {
      coordinates = new_var;
  }

  /**
   * Get the value of coordinates
   * @return the value of coordinates
   */
  GPS getCoordinates ()   {
    return coordinates;
  }

  /**
   * Set the value of street
   * @param new_var the new value of street
   */
  void setStreet (string new_var)   {
      street = new_var;
  }

  /**
   * Get the value of street
   * @return the value of street
   */
  string getStreet ()   {
    return street;
  }

  /**
   * Set the value of country
   * @param new_var the new value of country
   */
  void setCountry (string new_var)   {
      country = new_var;
  }

  /**
   * Get the value of country
   * @return the value of country
   */
  string getCountry ()   {
    return country;
  }

  /**
   * Set the value of city
   * @param new_var the new value of city
   */
  void setCity (string new_var)   {
      city = new_var;
  }

  /**
   * Get the value of city
   * @return the value of city
   */
  string getCity ()   {
    return city;
  }

  /**
   * Set the value of county
   * @param new_var the new value of county
   */
  void setCounty (string new_var)   {
      county = new_var;
  }

  /**
   * Get the value of county
   * @return the value of county
   */
  string getCounty ()   {
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
  unsigned int getDoor_number ()   {
    return door_number;
  }
private:


  void initAttributes () ;

};

#endif // ADDRESS_H
