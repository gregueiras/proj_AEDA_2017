/*
 * AdministratorMenuView.cpp
 *
 *  Created on: 25 Dec 2017
 *      Author: jotaa
 */

#include "AdministratorMenuView.h"

AdministratorMenuView::AdministratorMenuView() {
	u = new Utilities();
}

AdministratorMenuView::~AdministratorMenuView() {
	// TODO Auto-generated destructor stub
}

void AdministratorMenuView::printAdministratorMenu() {
	printMessage(administratorMenu);
}

void AdministratorMenuView::printEnterOption() {
	printMessage(enterOption);
}

void AdministratorMenuView::printShutdown() {
	printMessage(shutdown);
}

void AdministratorMenuView::printWrongOption() {
	printMessage(wrongOption);
}

void AdministratorMenuView::printMessage(const string& message) {
	cout << message << endl;
}

