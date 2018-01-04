/*
 * RemoveController.cpp
 *
 *  Created on: 08/11/2017
 *      Author: jotaa
 */

#include "UserMenuController.h"

UserMenuController::UserMenuController(Client *client, Company *company) {
	this->theView = new UserMenuView;
	u = new Utilities();
	v = new Validation();
	user = client;
	this->company = company;
}

UserMenuController::~UserMenuController() {
	// TODO Auto-generated destructor stub
}

void UserMenuController::menu() {
	menuHandler();
}

void UserMenuController::menuHandler() {
	int option;
	do {
		theView->printUserMenu();
		theView->printEnterOption();
		option = getMenuOption(0, 3);
		switch (option) {
		case 0:
			theView->printShutdown();
			endProgram();
			break;
		case 1:
			newChangeUserMenu();
			break;
		case 2:
			newRemoveUserMenu();
			break;
		case 3:
			newClientMenu();
			break;
		}
	} while (option != 0);
}

int UserMenuController::getMenuOption(const int lowerBound,
		const int upperBound) {
	int option;
	bool flag1 = theView->getInfo(option);
	bool flag2 = v->validateBound(option, lowerBound, upperBound);
	if (flag1 == false || flag2 == false) {
		theView->printWrongOption();
		return -1;
	}
	return option;
}

void UserMenuController::endProgram() {
}


void UserMenuController::newChangeUserMenu() {
	ChangeUserMenuController *changeUserMenuController =
			new ChangeUserMenuController(user, company);
	changeUserMenuController->menu();
}

void UserMenuController::newRemoveUserMenu() {
	RemoveUserMenuController *removeUserMenuController =
			new RemoveUserMenuController(user, company);
	removeUserMenuController->menu();
}
void UserMenuController::newClientMenu() {
	ClientMenuController *clientMenuController = new ClientMenuController(user,
			company);
	clientMenuController->menu();
}

