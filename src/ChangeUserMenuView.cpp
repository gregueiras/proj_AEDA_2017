/*
 * ChangeMenuView.cpp
 *
 *  Created on: 08/11/2017
 *      Author: jotaa
 */

#include "ChangeUserMenuView.h"

ChangeUserMenuView::ChangeUserMenuView() {
	u = new Utilities(); 
}

ChangeUserMenuView::~ChangeUserMenuView() {
	// TODO Auto-generated destructor stub
}

void ChangeUserMenuView::printMessage(const string &message) {
	cout << message << endl;
}

void ChangeUserMenuView::printInitialMessage() {
	printMessage(initialMessage);
}

void ChangeUserMenuView::printChangeUser() {
	printMessage(changeUserMenu);
}

void ChangeUserMenuView::printEnterOption() {
	printMessage(enterOption);

}
void ChangeUserMenuView::printWrongOption() {
	printMessage(wrongOption);
}

void ChangeUserMenuView::printEnd() {
	printMessage(end);
}

void ChangeUserMenuView::printEnterNewName() {
	printMessage(enterName);
}

void ChangeUserMenuView::printEnterNewNIF() {
	printMessage(enterNIF);
}

void ChangeUserMenuView::printEnterNewStreet() {
	printMessage(enterStreet);
}

void ChangeUserMenuView::printEnterNewCounty() {
	printMessage(enterCounty);
}

void ChangeUserMenuView::printEnterNewCity() {
	printMessage(enterCity);
}

void ChangeUserMenuView::printEnterNewCountry() {
	printMessage(enterCountry);
}

void ChangeUserMenuView::printEnterNewDoorNumber() {
	printMessage(enterDoorNumber);
}

void ChangeUserMenuView::printEnterNewLatitude() {
	printMessage(enterLatitude);
}

void ChangeUserMenuView::printEnterNewLongitude() {
	printMessage(enterLongitude);
}

void ChangeUserMenuView::printWrongNIF() {
	printMessage(wrongNIF);
}
void ChangeUserMenuView::printWrongLatitude() {
	printMessage(wrongLatitude);
}
void ChangeUserMenuView::printWrongLongitude() {
	printMessage(wrongLongitude);
}

void ChangeUserMenuView::printEnterContinue() {
	printMessage(keepContinuing);
}

void ChangeUserMenuView::printUserInfo(std::string str) {
	printMessage(str);
}
