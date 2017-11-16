
#ifndef SERVICES_H
#define SERVICES_H

#include <string>
#include <vector>
#include <iostream>
#include "GPS.h"
#include "Address.h"
#include "Delivery.h"
#include "Packaging.h"
#include "Shipping.h"
#include <sstream>
//#include "Payment.h"

using namespace std;

/**
 * Cost, in Euros, to move 1m^3 for 1 Km
 */
static double cost_km_m = 0.5;

/**
 * Cost, in Euros, to store package in storage, per day
 */
static double cost_day_in_storage = 2;


/**
  * class Services
  * 
  */
class Services
{
public:

  // Constructors/Destructors
  //  
	Services(Address origin_address, double volume, Address destination_address);
	Services(Address origin_address, double volume, Address destination_address, Packaging packaging, Shipping shipping, Delivery delivery);
	Services(Address origin_address, double volume, Address destination_address, Hour initial_hour, Date initial_date, unsigned int days_in_storage = 0);
  /**
   * Empty Destructor
   */
  virtual ~Services ();

private:

  // Static Private attributes
  //  

  // Private attributes
  //  

  //
//  Payment* pay;
  // ID of the service
  unsigned int service_id;
  // Origin of service
  Address origin_address;
  // Volume shipped
  double volume;
  // Distance between origin and destination of service
  double distance;
  // Price of service
  double price;
  // GPS Coordinates of the destination of service
  Address destination_address;
  //
  Shipping shipping;
  //
  Packaging packaging;
  //
  Delivery delivery;


public:


  // Private attribute accessor methods
  //  

  /**
   * Set the value of origin_address
   * Address of the origin of service
   * @param new_var the new value of origin_address
   */
  void setOrigin_address (Address new_var)   {
      origin_address = new_var;
  }

  /**
   * Get the value of origin_address
   * Address of the origin of service
   * @return the value of origin_address
   */
  Address getOrigin_address () const  {
    return origin_address;
  }

  /**
   * Set the value of volume
   * Volume shipped
   * @param new_var the new value of volume
   */
  void setVolume (double new_var)   {
      volume = new_var;
  }

  /**
   * Get the value of volume
   * Volume shipped
   * @return the value of volume
   */
  double getVolume ()  const {
    return volume;
  }

  /**
   * Calculate the value of distance
   * Distance between origin and destination of service
   */
  double calcDistance ();

  /**
   * Get the value of distance
   * Distance between origin and destination of service
   * @return the value of distance
   */
  double getDistance ()  const {
    return distance;
  }

  /**
   * Calculate the value of price
   * Price of service
   * @param days_in_storage Days the package spends in the storage
   * @return the value of price
   */
  double calcPrice (unsigned int days_in_storage = 0);

  /**
   * Get the value of price
   * Price of service
   * @return the value of price
   */
  double getPrice () const  {
    return price;
  }

  /**
   * Set the value of destination_Address
   * Address of the destination of service
   * @param new_var the new value of destination_Address
   */
  void setDestination_Address (Address new_var)   {
      destination_address = new_var;
  }

  /**
   * Get the value of destination_Address
   * Address of the destination of service
   * @return the value of destination_Address
   */
  Address getDestination_address ()  const {
    return destination_address;
  }

  /**
   * Get the value of Shipping
   * Service of Shipping
   * @return the value of shipping
   */
  Shipping getShipping() const  {
    return shipping;
  }

  /**
   * Get the value of Packaging
   * Service of Packaging
   * @return the value of packaging
   */
  Packaging getPackaging()  const {
    return packaging;
  }
  /**
   * Get the value of Delivery
   * Service of Delivery
   * @return the value of delivery
   */
  Delivery getDelivery()  const {
    return delivery;
  }

  /**
   * Get the value of service_id
   * Id of service
   * @return the value of service_id
   */
  unsigned int getId()  const {
    return service_id;
  }

//  /**
//   * Get the value of Payment
//   * @return the payment of service
//   */
//  unsigned int getPayment()  const {
//    return pay;
//  }

public:


/**
 * Calculates how much time it takes to pack the package
 * @return Time to pack
 */
Hour auxCalcTimePackaging();


/**
 * Calculates how much time it takes to ship the package from origin address to destination address
 * @return Time to ship
 */
Hour auxCalcTimeShipping();


/**
 * Converts the Service to a string with all info
 * @return Service info
 */
string toStrComplete();

/**
 * Converts the Service to a string with just the Origin Address and Destination Address of the Service
 * @return Origin Address and Destination Address of the Service
 */
string toStrShort();


/**
 * Checks if a service is between 2 Dates
 * @param d1 Lower bound of date interval
 * @param d2 Upper bound of date interval
 * @return True if service is between those Dates
 */
bool isBetweenDates(const Date &d1, const Date &d2);

/**
 * Checks if a service volume is between 2 Volumes
 * @param d1 Lower bound of volume interval
 * @param d2 Upper bound of volume interval
 * @return True if service volume is between those volumes
 */
bool isBetweenVolume(const double &d1, const double &d2);


/**
 * Checks if a service distance is between 2 distance
 * @param d1 Lower bound of distance interval
 * @param d2 Upper bound of distance interval
 * @return True if service distance is between those distances
 */
bool isBetweenDistance(const double &d1, const double &d2);


/**
 * Checks if a service price is between 2 prices
 * @param d1 Lower bound of price interval
 * @param d2 Upper bound of price interval
 * @return True if service price is between those prices
 */
bool isBetweenPrice(const double &d1, const double &d2);


};

ostream& operator<< (ostream& o, const Services& c);



#endif // SERVICES_H
