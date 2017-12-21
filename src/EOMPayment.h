
#ifndef EOMPAYMENT_H
#define EOMPAYMENT_H
#include "Payment.h"

#include <string>

using namespace std;

/**
  * class EOMPayment
  * 
  */

class EOMPayment : public Payment
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
   //ONLY FOR BST FIND PURPOSES
  EOMPayment (unsigned int id);

  EOMPayment(double value, string name);

  EOMPayment(double value, string name, bool due, Date due_date, Hour due_hour);

  /**
   * Empty Destructor
   */
  virtual ~EOMPayment ();

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  

private:

public:
	
	string getPayType();

};

#endif // EOMPayment_H
