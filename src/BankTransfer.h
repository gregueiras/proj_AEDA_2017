
#ifndef BANKTRANSFER_H
#define BANKTRANSFER_H
#include "Payment.h"

#include <string>

using namespace std;

/**
  * class BankTransfer
  * 
  */

class BankTransfer : public Payment
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
   //ONLY FOR BST FIND PURPOSES
	BankTransfer(unsigned int id);

	BankTransfer (double value, string name);

	BankTransfer(double value, string name, bool due, Date due_date, Hour due_hour);

  /**
   * Empty Destructor
   */
  virtual ~BankTransfer ();

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

#endif // BANKTRANSFER_H
