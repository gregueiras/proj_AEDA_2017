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
	id = 0;
	pass = "";
}

LoginController::~LoginController() {
}

void LoginController::menu() {
	theView->printInitialMessage();
	getUserCredentials();
	user = company->getClient(id, pass);

	if (user != NULL) {
		newClientMenu();
	} else {
		theView->printUserNotFound();
		menu();
	}
}

void LoginController::getUserCredentials() {
	id = getID();
	pass = getPass();
}

unsigned int LoginController::getID() {
	unsigned int id = 0;
	bool flag = false;
	theView->printEnterID();
	while (!flag) {
		theView->getInfo(id);
		if (id == 0) {
			newEnterController();
		}
		if (!(flag = v->validateIDFormat(std::to_string(id)))) {
			theView->printWrongUserID();
			continue;
		}

	}
	return id;
}

string LoginController::getPass() {
	string pass;
	theView->printEnterPassword();
	pass = theView->readLine();
	if (pass == "0") {
		newEnterController();
	}
	return pass;
}

void LoginController::endProgram() {
}

void LoginController::newClientMenu() {
	ClientMenuController *clientMenuController = new ClientMenuController(user,
			company);
	clientMenuController->menu();
}

void LoginController::newEnterController() {
	EnterController *enterController = new EnterController(company);
	enterController->menu();
}
/* namespace std */
