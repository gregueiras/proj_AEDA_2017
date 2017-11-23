/*
 * NewUserView.cpp
 *
 *  Created on: 04/11/2017
 *      Author: jotaa
 */

#include "NewUserView.h"

NewUserView::NewUserView() {
	u = new Utilities();
}

NewUserView::~NewUserView() {
	// TODO Auto-generated destructor stub
}

void NewUserView::printMessage(const string &message) const {
	cout << message << endl;
}

void NewUserView::printEnd() const {
	printMessage(end);
}

void NewUserView::printEnterUserType() {
	printMessage(enterUserType);
	printMessage(exit);
}

void NewUserView::printEnterName() {
	printMessage(enterName);
	printMessage(exit);
}
void NewUserView::printEnterNIF() {
	printMessage(enterNIF);
	printMessage(exit);
}
void NewUserView::printEnterStreet() {
	printMessage(enterStreet);
}
void NewUserView::printEnterCountry() {
	printMessage(enterCountry);
	printMessage(exit);
}
void NewUserView::printEnterCity() {
	printMessage(enterCity);
	printMessage(exit);
}
void NewUserView::printEnterCounty() {
	printMessage(enterCounty);
	printMessage(exit);
}
void NewUserView::printEnterDoorNumber() {
	printMessage(enterDoorNumber);
	printMessage(exit);
}
void NewUserView::printEnterLatitude() {
	printMessage(enterLatitude);
	printMessage(exit);
}
void NewUserView::printEnterLongitude() {
	printMessage(enterLongitude);
	printMessage(exit);
}

void NewUserView::printWrongNIF() {
	printMessage(wrongNIF);
}
void NewUserView::printWrongLatitude() {
	printMessage(wrongLatitude);
}
void NewUserView::printWrongLongitude() {
	printMessage(wrongLongitude);
}
void NewUserView::printWrongUserType() {
	printMessage(wrongUserType);
}

void NewUserView::printEnterPassword() {
	printMessage(enterPassword);
}

void NewUserView::printNewUserMenu() {
	printMessage(newUserMenu);
}
