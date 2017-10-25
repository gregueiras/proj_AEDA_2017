
#ifndef GPS_H
#define GPS_H

#include <string>

/**
  * class GPS
  * 
  */

class GPS
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  GPS ();

  /**
   * Empty Destructor
   */
  virtual ~GPS ();

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

  // Latitude coordinates in decimal degrees format
  long latitude;
  // Longitude coordinates in decimal degrees format
  long longitude;
public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of latitude
   * Latitude coordinates in decimal degrees format
   * @param new_var the new value of latitude
   */
  void setLatitude (long new_var)   {
      latitude = new_var;
  }

  /**
   * Get the value of latitude
   * Latitude coordinates in decimal degrees format
   * @return the value of latitude
   */
  long getLatitude ()   {
    return latitude;
  }

  /**
   * Set the value of longitude
   * Longitude coordinates in decimal degrees format
   * @param new_var the new value of longitude
   */
  void setLongitude (long new_var)   {
      longitude = new_var;
  }

  /**
   * Get the value of longitude
   * Longitude coordinates in decimal degrees format
   * @return the value of longitude
   */
  long getLongitude ()   {
    return longitude;
  }
private:


  void initAttributes () ;

};

#endif // GPS_H
