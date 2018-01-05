/*
 * LoginController.cpp
 *
 *  Created on: 03/11/2017
 *      Author: jotaa
 */

#include "LoginController.h"

LoginController::LoginController(Company *company) {
	client = NULL;
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
		id = getID();
		if (id == 0) {
			break;
		}
		pass = getPass();
		if (pass == "0") {
			break;
		}
		client = company->getClient(id, pass);
		if (client != NULL) {

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
	theView->printEnd();
	theView->printShutdown();
	company->writeCompanyToFile();
	company->writeClientsToFile();
	company->writeVehiclesToFile();
	exit(0);
}

void LoginController::newClientMenu() {
	theView->printEnd();
	ClientMenuController *clientMenuController = new ClientMenuController(client,
			company);
	clientMenuController->menu();
}

void LoginController::newAdministratorController() {
	theView->printEnd();
	AdministratorMenuController *administratorMenuController =
			new AdministratorMenuController(company);
	administratorMenuController->menu();
}
