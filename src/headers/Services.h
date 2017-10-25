
#ifndef SERVICES_H
#define SERVICES_H

#include <string>
#include vector



/**
  * class Services
  * 
  */

class Services
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Services ();

  /**
   * Empty Destructor
   */
  virtual ~Services ();

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

  // GPS Coordinates of the origin of service
  Address origin_address;
  // Volume shipped
  long volume;
  // Distance between origin and destination of service
  unsigned long distance;
  // Price of service
  unsigned long price;
  // GPS Coordinates of the destination of service
  Address destination_Address;
public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of origin_address
   * GPS Coordinates of the origin of service
   * @param new_var the new value of origin_address
   */
  void setOrigin_address (Address new_var)   {
      origin_address = new_var;
  }

  /**
   * Get the value of origin_address
   * GPS Coordinates of the origin of service
   * @return the value of origin_address
   */
  Address getOrigin_address ()   {
    return origin_address;
  }

  /**
   * Set the value of volume
   * Volume shipped
   * @param new_var the new value of volume
   */
  void setVolume (long new_var)   {
      volume = new_var;
  }

  /**
   * Get the value of volume
   * Volume shipped
   * @return the value of volume
   */
  long getVolume ()   {
    return volume;
  }

  /**
   * Set the value of distance
   * Distance between origin and destination of service
   * @param new_var the new value of distance
   */
  void setDistance (unsigned long new_var)   {
      distance = new_var;
  }

  /**
   * Get the value of distance
   * Distance between origin and destination of service
   * @return the value of distance
   */
  unsigned long getDistance ()   {
    return distance;
  }

  /**
   * Set the value of price
   * Price of service
   * @param new_var the new value of price
   */
  void setPrice (unsigned long new_var)   {
      price = new_var;
  }

  /**
   * Get the value of price
   * Price of service
   * @return the value of price
   */
  unsigned long getPrice ()   {
    return price;
  }

  /**
   * Set the value of destination_Address
   * GPS Coordinates of the destination of service
   * @param new_var the new value of destination_Address
   */
  void setDestination_Address (Address new_var)   {
      destination_Address = new_var;
  }

  /**
   * Get the value of destination_Address
   * GPS Coordinates of the destination of service
   * @return the value of destination_Address
   */
  Address getDestination_Address ()   {
    return destination_Address;
  }
private:


  void initAttributes () ;

};

#endif // SERVICES_H
