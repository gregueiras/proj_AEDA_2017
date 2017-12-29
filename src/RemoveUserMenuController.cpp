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
	theView->printRemoveUserMenu();
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
		newEnterMenuController();
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
		theView->getInfo(option);
		if (!(flag = v->validateBound(option, lowerBound, upperBound))) {
			theView->printWrongOption();
		}
	}
	return option;
}

void RemoveUserMenuController::removeUser() {
	theView->printEnterConfirmation();
	int option;
	theView->getInfo(option);
	if (option == 1) {
		user->setVisibility(false);
	}
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

void RemoveUserMenuController::endProgram() {
}
