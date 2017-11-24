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
	
	Client* c1 = company->getClient(id, pass);
	if (c1 != NULL) {
		this->user = c1;
		newClientMenu();
	} else {
		theView->printUserNotFound();
		newEnterController();
	}
}

void LoginController::getUserCredentials() {
	id = getID();
	
	cout << "ID: " << id << endl;
	pass = getPass();


}

unsigned int LoginController::getID() {
	unsigned int id = 0;
	bool flag = false;
	theView->printEnterID();
	while (!flag) {
		getInfo(id);
		if (!(flag = v->validateIDFormat(std::to_string(id)))) {
			theView->printWrongUserID();
			continue;
		}

	}
	return id;
}

string LoginController::getPass() {
	string pass;
//	bool flag = false;
	theView->printEnterPassword();
	getInfo(pass);
	return pass;
}

void LoginController::endProgram() {
	exit(0);
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
