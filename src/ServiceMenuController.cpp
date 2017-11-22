/*
 * ServiceMenuController.cpp
 *
 *  Created on: 08/11/2017
 *      Author: jotaa
 */

#include "ServiceMenuController.h"
ServiceMenuController::ServiceMenuController(Client *client,Company *company) {
	this->theView = new ServiceMenuView;
	this->company = company;
	u = new Utilities();
	v = new Validation();
	user = client;
}
ServiceMenuController::~ServiceMenuController() {
	// TODO Auto-generated destructor stub
}

void ServiceMenuController::menu() {
	theView->printInitialMessage();
	theView->printServiceMenu();
	serviceMenuHandler();
}

void ServiceMenuController::serviceMenuHandler() {
	theView->printEnterOption();
	int option = getMenuOption(0, 9);
	switch (option) {
	case 0:
		theView->printEnd();
		endProgram();
		break;
	case 1:
		newRequisitService();
		break;
	case 2:
		newServiceListMenu();
		break;
	case 3:
		newClientMenu();
		break;
	default:
		newClientMenu();
		break;
	}
}

int ServiceMenuController::getMenuOption(const int lowerBound,
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

void ServiceMenuController::endProgram() {
	exit(0);
}

void ServiceMenuController::newRequisitService() {
	RequisitServiceController *requisitServiceController = new RequisitServiceController(user,company);
	requisitServiceController->menu();
}

void ServiceMenuController::newServiceListMenu() {
	ListServicesController *listServicesController = new ListServicesController(user,company);
	listServicesController->menu();
}

void ServiceMenuController::newClientMenu() {
	ClientMenuController *clientMenuController = new ClientMenuController(user,company);
	clientMenuController->menu();
}

