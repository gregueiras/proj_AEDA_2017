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
}

void NewUserView::printEnterName() {
	printMessage(enterName);
}
void NewUserView::printEnterNIF() {
	printMessage(enterNIF);
}
void NewUserView::printEnterStreet() {
	printMessage(enterStreet);
}
void NewUserView::printEnterCountry() {
	printMessage(enterCountry);
}
void NewUserView::printEnterCity() {
	printMessage(enterCity);
}
void NewUserView::printEnterCounty() {
	printMessage(enterCounty);
}
void NewUserView::printEnterDoorNumber() {
	printMessage(enterDoorNumber);
}
void NewUserView::printEnterLatitude() {
	printMessage(enterLatitude);
}
void NewUserView::printEnterLongitude() {
	printMessage(enterLongitude);
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

void NewUserView::printUserID(const unsigned int userID) {
	printMessage("ID-> " + to_string(userID));
}

void NewUserView::printShutdown() {
	printMessage(shutdown);
}

string NewUserView::readLine() {
	return u->readLine();
}
