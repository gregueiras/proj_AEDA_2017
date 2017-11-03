
#ifndef GPS_H
#define GPS_H

#include <string>
#include <cmath>
#include <iostream>

/**
  * class GPS
  * 
  */

class GPS
{
public:

  // Constructors/Destructors
  //  
	GPS (double lat, double lon);


  /**
  ** Empty Constructor
  */
	GPS()
	{
		latitude = 0;
		longitude = 0;
	}

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
  double latitude;
  // Longitude coordinates in decimal degrees format
  double longitude;
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
  void setLatitude (double new_var)   {
      latitude = new_var;
  }

  /**
   * Get the value of latitude
   * Latitude coordinates in decimal degrees format
   * @return the value of latitude
   */
  double getLatitude () const   {
    return latitude;
  }

  /**
   * Set the value of longitude
   * Longitude coordinates in decimal degrees format
   * @param new_var the new value of longitude
   */
  void setLongitude (double new_var)   {
      longitude = new_var;
  }

  /**
   * Get the value of longitude
   * Longitude coordinates in decimal degrees format
   * @return the value of longitude
   */
  double getLongitude ()  const  {
    return longitude;
  }
private:


  void initAttributes () ;

public:




};

bool operator== (const GPS & c1, const GPS & c2);
bool operator!= (const GPS & c1, const GPS & c2);
std::ostream& operator<< (std::ostream& o, const GPS& c);


/**
 * Calculates the distance between 2 GPS positions
 * Coordinates in decimal degrees format
 * @param gps1 Point 1
 * @param gps2 Point 2
 * @return the value of longitude
 */
double calculateDistanceBetween2GPS(const GPS gps1, const GPS gps2);


/**
 * Auxiliary function, to calculate Haversine
 * @param theta Angle theta, in radians
 * @return the value of haversine, for theta
 */


/**
 * Auxiliary function, to convert decimal degrees to radians
 * @param degree Decimal degree
 * @return equivalent in radians
 */
double auxDegreesToRadians(const double degree);

class GPSInvalidLat {
private:
	double latitude;

public:
	GPSInvalidLat(double lat) { this->latitude = lat; }
};

class GPSInvalidLon {
private:
	double longitude;

public:
	GPSInvalidLon(double lon) { this->longitude = lon; }
};



#endif // GPS_H
