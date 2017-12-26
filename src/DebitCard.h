
#ifndef DEBITCARD_H
#define DEBITCARD_H
#include "Payment.h"

#include <string>

using namespace std;

/**
  * class DebitCard
  * 
  */

class DebitCard : public Payment
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */

  DebitCard(double value, unsigned int s_id);

  DebitCard (double value, unsigned int s_id, bool due, Date due_date, Hour due_hour);

  /**
   * Empty Destructor
   */
  virtual ~DebitCard ();

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

#endif // DEBITCARD_H
