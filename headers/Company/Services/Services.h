
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

using namespace std;
static double cost_km_m = 0.5;
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
  /**
   * Empty Destructor
   */
  virtual ~Services ();

private:

  // Static Private attributes
  //  

  // Private attributes
  //  

  // ID of the service
    int service_id;
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
   */
  double calcPrice ();

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

public:





};

ostream& operator<< (ostream& o, const Services& c);




#endif // SERVICES_H
