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
	this->client = client;
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
	do {
		theView->printClientMenu();
		theView->printEnterOption();
		option = getMenuOption(0, 3);
		switch (option) {
		case 0:
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
	} while (option != 0);
}

void ClientMenuController::notificationHandler() {
	theView->printNotificationsHeader();
	if (client->getVisibility() == false && company->getDiscount() != 0) {
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
	theView->printEnd();
	theView->printShutdown();
	theView->printShutdown();
	company->writeCompanyToFile();
	company->writeClientsToFile();
	company->writeVehiclesToFile();
	exit(0);
}

void ClientMenuController::newEnterMenu() {
	theView->printEnd();
	EnterController *enterController = new EnterController(company);
	enterController->menu();
}

void ClientMenuController::newUserMenu() {
	theView->printEnd();
	UserMenuController *userControllerMenu = new UserMenuController(client,
			company);
	userControllerMenu->menu();
}

void ClientMenuController::newServiceMenu() {
	theView->printEnd();
	ServiceMenuController *serviceMenuController = new ServiceMenuController(
			client, company);
	serviceMenuController->menu();
}
