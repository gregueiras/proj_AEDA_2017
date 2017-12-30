/*
 * EnterController.cpp
 *
 *  Created on: 04/11/2017
 *      Author: jotaa
 */

#include "EnterController.h"

EnterController::EnterController(Company *company) {
	this->theView = new EnterView;
	v = new Validation();
	u = new Utilities();
	this->company = company;
}

EnterController::~EnterController() {
}

void EnterController::setInactiveUsers() {
	company->setInactiveClients();
}

void EnterController::menu() {
	setInactiveUsers();
	enterMenu();
}

void EnterController::enterMenu() {
	int option;
	theView->printEnterMenu();
	do {
		theView->printEnterOption();
		option = getMenuOption(0, 2);
		switch (option) {
		case 0:
			theView->printShutdown();
			endProgram();
			break;
		case 1:
			newLoginMenu();
			break;
		case 2:
			newUserMenu();
			break;
		}
	} while (option == -1);
}

int EnterController::getMenuOption(const int lowerBound, const int upperBound) {
	int option;
	bool flag1 = theView->getInfo(option);
	bool flag2 = v->validateBound(option, lowerBound, upperBound);
	if (flag1 == false || flag2 == false) {
		theView->printWrongOption();
		return -1;
	}
	return option;
}

void EnterController::newLoginMenu() {
	LoginController *loginController = new LoginController(company);
	loginController->menu();
}

void EnterController::newUserMenu() {
	NewUserController *newUserController = new NewUserController(company);
	newUserController->menu();
}

void EnterController::endProgram() {

	//company->writeCompanyToFile();
	//company->writeClientsToFile();
	//exit(0);
}
