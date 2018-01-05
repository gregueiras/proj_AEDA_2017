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
	this->client = client;
	this->company = company;
}

RemoveUserMenuController::~RemoveUserMenuController() {
	// TODO Auto-generated destructor stub
}

void RemoveUserMenuController::menu() {
	int option;
	do {
		theView->printRemoveUserMenu();
		theView->printEnterOption();
		option = getMenuOption(0, 2);
		switch (option) {
		case 0:
			endProgram();
			break;
		case 1:
			removeUser();
			newEnterMenuController();
			break;
		case 2:
			newUserMenuController();
			break;
		}
	} while (option != 0);
}

int RemoveUserMenuController::getMenuOption(const int lowerBound,
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

void RemoveUserMenuController::removeUser() {
	theView->printEnterConfirmation();
	int option;
	bool flag = theView->getInfo(option);
	if (option == 1 && flag == true) {
		client->setVisibility(false);
	}
}

void RemoveUserMenuController::newEnterMenuController() {
	theView->printEnd();
	EnterController *enterController = new EnterController(company);
	enterController->menu();
}

void RemoveUserMenuController::newUserMenuController() {
	theView->printEnd();
	UserMenuController *userMenuController = new UserMenuController(client,
			company);
	userMenuController->menu();
}

void RemoveUserMenuController::endProgram() {
	theView->printEnd();
	theView->printShutdown();
	company->writeCompanyToFile();
	company->writeClientsToFile();
	company->writeVehiclesToFile();
	exit(0);
}
