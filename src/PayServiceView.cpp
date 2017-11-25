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

void PayServiceView::printPayMenuNormal() {
	printMessage(payMenuNormal);
}

void PayServiceView::printPayMenuBusiness() {
	printMessage(payMenuBusiness);
}

void PayServiceView::printPayEOM() {
	printMessage(payEOM);
}

void PayServiceView::printAmountToPay(double value) {
//	cout << amountToPay << value << endl;
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

void PayServiceView::printShutdown() {
	printMessage(shutdown);
}

void PayServiceView::printMessage(const string &message) {
	cout << message << endl;
}

void PayServiceView::printNoEOMLeftToPay() {
	printMessage(noEOMLeftToPay);
}

void PayServiceView::printEntity(string entity) {
	cout << this->entity << entity << endl;
}

void PayServiceView::printReference(string reference) {
	cout << this->reference << reference << endl;
}

void PayServiceView::printNIB(string nib) {
	cout << this->nib << nib << endl;
}

void PayServiceView::printEnterCreditCardNumber() {
	printMessage(enterCreditCardNumber);
}
