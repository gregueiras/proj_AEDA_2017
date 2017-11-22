/*
 * RemoveMenuController.cpp
 *
 *  Created on: 08/11/2017
 *      Author: jotaa
 */

#include "RemoveUserMenuController.h"

RemoveUserMenuController::RemoveUserMenuController(Client *client,
		Company *company) {
	this->theView = new RemoveMenuView;
	u = new Utilities();
	v = new Validation();
	user = client;
	this->company = company;
}

RemoveUserMenuController::~RemoveUserMenuController() {
	// TODO Auto-generated destructor stub
}

void RemoveUserMenuController::menu() {
	theView->printInitialMessage();
	theView->printRemoveUser();
	removeUserHandler();
}

void RemoveUserMenuController::removeUserHandler() {
	theView->printEnterOption();
	int option = getMenuOption(0, 2);
	switch (option) {
	case 0:
		theView->printEnd();
		endProgram();
		break;
	case 1:
		removeUser();
		break;
	case 2:
		newUserMenuController();
		break;
	default:
		newUserMenuController();
		break;
	}
}

int RemoveUserMenuController::getMenuOption(const int lowerBound,
		const int upperBound) {
	int option;
	bool flag = false;
	while (!flag) {
		getInfo(option);
		if (!(flag = v->validateBound(option, lowerBound, upperBound))) {
			theView->printWrongOption();
		}
	}
	return option;
}

bool RemoveUserMenuController::getConfirmation() {
	int confirmation;
	theView->printEnterConfirmation();
	bool flag = false;
	while (!flag) {
		getInfo(confirmation);
		if (!(flag = v->validateBound(confirmation, 0, 2))) {
			theView->printWrongOption();
		}
	}
	return confirmation == 1;
}
void RemoveUserMenuController::endProgram() {
	exit(0);
}

void RemoveUserMenuController::removeUser() {
	user->setVisibility(false);
	newEnterMenuController();
}

void RemoveUserMenuController::newEnterMenuController() {
	EnterController *enterController = new EnterController(company);
	enterController->menu();
}

void RemoveUserMenuController::newUserMenuController() {
	UserMenuController *userMenuController = new UserMenuController(user,
			company);
	userMenuController->menu();
}
