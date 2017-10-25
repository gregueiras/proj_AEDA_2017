
#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include vector



/**
  * class Company
  * 
  */

class Company
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Company ();

  /**
   * Empty Destructor
   */
  virtual ~Company ();

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

  // Cost of shipping 1 cubic metre of material for 1km.
  // Basis for calculating prices.
  static unsigned long cost_km_m;
  // Price of storing goods in the storage.
  // Service only available for registered clients.
  // Basis for calculating prices
  static unsigned long cost_day_in_storage;
  // Private attributes
  //  

  // Vector of clients of the company
  vector<Client*> clients;
public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of cost_km_m
   * Cost of shipping 1 cubic metre of material for 1km.
   * Basis for calculating prices.
   * @param new_var the new value of cost_km_m
   */
  void setCost_km_m (unsigned long new_var)   {
      Company::cost_km_m = new_var;
  }

  /**
   * Get the value of cost_km_m
   * Cost of shipping 1 cubic metre of material for 1km.
   * Basis for calculating prices.
   * @return the value of cost_km_m
   */
  unsigned long getCost_km_m ()   {
    return Company::cost_km_m;
  }

  /**
   * Set the value of cost_day_in_storage
   * Price of storing goods in the storage.
   * Service only available for registered clients.
   * Basis for calculating prices
   * @param new_var the new value of cost_day_in_storage
   */
  void setCost_day_in_storage (unsigned long new_var)   {
      Company::cost_day_in_storage = new_var;
  }

  /**
   * Get the value of cost_day_in_storage
   * Price of storing goods in the storage.
   * Service only available for registered clients.
   * Basis for calculating prices
   * @return the value of cost_day_in_storage
   */
  unsigned long getCost_day_in_storage ()   {
    return Company::cost_day_in_storage;
  }
private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of clients
   * Vector of clients of the company
   * @param new_var the new value of clients
   */
  void setClients (vector<Client*> new_var)   {
      clients = new_var;
  }

  /**
   * Get the value of clients
   * Vector of clients of the company
   * @return the value of clients
   */
  vector<Client*> getClients ()   {
    return clients;
  }
private:


  void initAttributes () ;

};

#endif // COMPANY_H
