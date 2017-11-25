/*
 * RemoveMenuView.cpp
 *
 *  Created on: 08/11/2017
 *      Author: jotaa
 */

#include "RemoveUserMenuView.h"

RemoveMenuView::RemoveMenuView() {
	u = new Utilities();
}

RemoveMenuView::~RemoveMenuView() {
	// TODO Auto-generated destructor stub
}

void RemoveMenuView::printMessage(const string &message) {
	cout << message << endl;
}

void RemoveMenuView::printRemoveUser() {
	printMessage(removeUserMenu);
}

void RemoveMenuView::printEnterOption() {
	printMessage(enterOption);
}

void RemoveMenuView::printEnterConfirmation() {
	printMessage(enterConfirmation);
}

void RemoveMenuView::printWrongOption() {
	printMessage(wrongOption);
}

void RemoveMenuView::printEnd() {
	printMessage(end);
}

void RemoveMenuView::printShutdown() {
	printMessage(shutdown);
}
