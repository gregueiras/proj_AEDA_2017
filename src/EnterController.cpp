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

void EnterController::menu() {
	theView->printEnterMenu();
	enterMenu();
}

void EnterController::enterMenu() {
	theView->printEnterOption();
	int option = getMenuOption(0, 2);
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
	default:
		theView->printWrongOption();
		endProgram();
		break;
	}
}

int EnterController::getMenuOption(const int lowerBound, const int upperBound) {
	unsigned int option;
	bool flag = false;
	while (!flag) {
		theView->getInfo(option);
		if (!(flag = v->validateBound(option, lowerBound, upperBound))) {
			theView->printWrongOption();
		}
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
