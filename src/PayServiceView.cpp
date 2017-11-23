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

void PayServiceView::printMenuNormal() {
	printMessage(payMenu);
	printMessage(payMenuNormal);
}

void PayServiceView::printMenuBusiness() {
	printMessage(payMenu);
	printMessage(payMenuBusiness);
}

void PayServiceView::printAmountToPay() {
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

void PayServiceView::printMessage(const string &message) {
	cout << message << endl;
}
