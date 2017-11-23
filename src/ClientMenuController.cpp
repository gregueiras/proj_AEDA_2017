/*
 * ClientMenuController.cpp
 *
 *  Created on: 06/11/2017
 *      Author: jotaa
 */

#include "ClientMenuController.h"

ClientMenuController::ClientMenuController(Client *client, Company *company) {
	this->theView = new ClientMenuView;
	v = new Validation();
	u = new Utilities();
	user = client;
	this->company = company;
}

ClientMenuController::~ClientMenuController() {

}

void ClientMenuController::menu() {
	theView->printClientMenu();
	clientMenuHandler();
}

void ClientMenuController::clientMenuHandler() {
	theView->printEnterOption();
	int option = getMenuOption(0, 3);
	switch (option) {
	case 0:
		theView->printEnd();
		endProgram();
		break;
	case 1:
		newUserMenu();
		break;
	case 2:
		newServiceMenu();
		break;
	case 3:
		newLoginMenu();
		break;
	default:
		newLoginMenu();
		break;
	}
}
int ClientMenuController::getMenuOption(const int lowerBound,
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

void ClientMenuController::endProgram() {
	exit(0);
}

void ClientMenuController::newLoginMenu() {
	LoginController *loginController = new LoginController(company);
	loginController->menu();
}

void ClientMenuController::newUserMenu() {
	UserMenuController *userControllerMenu = new UserMenuController(user,
			company);
	userControllerMenu->menu();
}

void ClientMenuController::newServiceMenu() {
	ServiceMenuController *serviceMenuController = new ServiceMenuController(
			user, company);
	serviceMenuController->menu();
}
