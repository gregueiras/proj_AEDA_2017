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
	notificationHandler();
	clientMenuHandler();
}

void ClientMenuController::clientMenuHandler() {
	int option;
	theView->printClientMenu();
	do {
		theView->printEnterOption();
		option = getMenuOption(0, 3);
		switch (option) {
		case 0:
			theView->printShutdown();
			endProgram();
			break;
		case 1:
			newUserMenu();
			break;
		case 2:
			newServiceMenu();
			break;
		case 3:
			newEnterMenu();
			break;
		}
	} while (option == -1);
}

void ClientMenuController::notificationHandler() {
	theView->printNotificationsHeader();
	if (user->getVisibility() == false && company->getDiscount() != 0) {
		theView->printPendingChangeAdress();
	}
}

int ClientMenuController::getMenuOption(const int lowerBound,
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

void ClientMenuController::endProgram() {
}

void ClientMenuController::newEnterMenu() {
	EnterController *enterController = new EnterController(company);
	enterController->menu();
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
