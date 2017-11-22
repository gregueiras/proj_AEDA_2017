/*
 * UserMenuView.cpp
 *
 *  Created on: 08/11/2017
 *      Author: jotaa
 */

#include "UserMenuView.h"

UserMenuView::UserMenuView() {
	u = new Utilities();
}

UserMenuView::~UserMenuView() {
}

void UserMenuView::printMessage(const string &message) {
	cout << message << endl;
}

void UserMenuView::printInitialMessage() {
	printMessage(initialMessage);
}

void UserMenuView::printUserMenu() {
	printMessage(userMenu);
}

void UserMenuView::printEnterOption() {
	printMessage(enterOption);

}
void UserMenuView::printWrongOption() {
	printMessage(wrongOption);
}

void UserMenuView::printEnd() {
	printMessage(end);
}