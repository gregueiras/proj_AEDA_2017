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

void ChangeUserMenuView::printChangeUserMenu() {
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
	printMessage(enterNewName);
}

void ChangeUserMenuView::printEnterNewNIF() {
	printMessage(enterNewNIF);
}

void ChangeUserMenuView::printEnterNewStreet() {
	printMessage(enterNewStreet);
}

void ChangeUserMenuView::printEnterNewCounty() {
	printMessage(enterNewCounty);
}

void ChangeUserMenuView::printEnterNewCity() {
	printMessage(enterNewCity);
}

void ChangeUserMenuView::printEnterNewCountry() {
	printMessage(enterNewCountry);
}

void ChangeUserMenuView::printEnterNewDoorNumber() {
	printMessage(enterNewDoorNumber);
}

void ChangeUserMenuView::printEnterNewLatitude() {
	printMessage(enterNewLatitude);
}

void ChangeUserMenuView::printEnterNewLongitude() {
	printMessage(enterNewLongitude);
}

void ChangeUserMenuView::printEnterNewPassword() {
	printMessage(enterNewPassword);
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

void ChangeUserMenuView::printUserInfo(string str) {
	printMessage("\n" + str);
}

void ChangeUserMenuView::printShutdown() {
	printMessage(shutdown);
}
