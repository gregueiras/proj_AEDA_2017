/*
 * LoginController.cpp
 *
 *  Created on: 03/11/2017
 *      Author: jotaa
 */

#include "LoginController.h"

LoginController::LoginController(Company *company) {
	user = NULL;
	this->theView = new LoginView;
	v = new Validation();
	u = new Utilities();
	this->company = company;
}

LoginController::~LoginController() {
}

void LoginController::menu() {
	unsigned int id;
	string pass;
	do {
		theView->printInitialMessage();
		if ((id = getID()) == 0) {
			break;
		}
		if ((pass = getPass()) == "0") {
			break;
		}
		user = company->getClient(id, pass);
		if (user != NULL) {
			newClientMenu();
		} else if (company->checkAdminCredentials(id, pass)) {
			newAdministratorController();
		} else {
			theView->printUserNotFound();
		}
	} while (id != 0 || pass != "0");
}

unsigned int LoginController::getID() {
	unsigned int id = 0;
	bool flag = false;
	do {
		theView->printEnterID();
		flag = theView->getInfo(id);
		if (flag == false) {
			theView->printWrongUserID();
		}
	} while (!flag);
	return id;
}

string LoginController::getPass() {
	theView->printEnterPassword();
	return theView->readLine();
}

void LoginController::endProgram() {
}

void LoginController::newClientMenu() {
	ClientMenuController *clientMenuController = new ClientMenuController(user,
			company);
	clientMenuController->menu();
}

void LoginController::newAdministratorController() {
	AdministratorMenuController *administratorMenuController =
			new AdministratorMenuController(company);
	administratorMenuController->menu();
}
