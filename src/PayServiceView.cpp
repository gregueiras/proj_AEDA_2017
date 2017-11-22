/*
 * PayServiceView.cpp
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#include "PayServiceView.h"

PayServiceView::PayServiceView() {
	u = new Utilities(); 
}

PayServiceView::~PayServiceView() {
	// TODO Auto-generated destructor stub
}

void PayServiceView::printInitialMessage() {
	printMessage(initialMessage);
}

void PayServiceView::printPayMenu() {
	printMessage(payMenu);
}

void  PayServiceView::printGetBackNormal() {
	printMessage(getBackNormal);
}

void  PayServiceView::printBackBusiness() {
	printMessage(getBackBusiness);
}

void  PayServiceView::printAmountToPay() {
	printMessage(amountToPay);
}

void PayServiceView::printEnterOption() {
	printMessage(enterOption);
}

void PayServiceView::printWrongOption() {
	printMessage(wrongOption);
}

void PayServiceView::printEnd() {
	printMessage(end); 
}

void PayServiceView::printMessage(const string &message)  {
	cout << message << endl;
}

