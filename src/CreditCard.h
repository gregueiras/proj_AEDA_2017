
#ifndef CREDITCARD_H
#define CREDITCARD_H
#include "Payment.h"

#include <string>

using namespace std;

/**
  * class CreditCard
  * 
  */

class CreditCard : public Payment
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
   //ONLY FOR BST FIND PURPOSES
  CreditCard (unsigned int id);

  CreditCard(double value, string name);

  CreditCard (double value, string name, bool due, Date due_date, Hour due_hour);

  /**
   * Empty Destructor
   */
  virtual ~CreditCard ();

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

#endif // CREDITCARD_H
