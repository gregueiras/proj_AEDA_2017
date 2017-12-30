/*
 * ServiceMenuController.cpp
 *
 *  Created on: 08/11/2017
 *      Author: jotaa
 */

#include "ServiceMenuController.h"
ServiceMenuController::ServiceMenuController(Client *client, Company *company) {
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
	theView->printServiceMenu();
	serviceMenuHandler();
}

void ServiceMenuController::serviceMenuHandler() {
	int option;
	do {
		theView->printEnterOption();
		option = getMenuOption(0, 3);
		switch (option) {
		case 0:
			theView->printShutdown();
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
		}
	} while (option == -1);
}

int ServiceMenuController::getMenuOption(const int lowerBound,
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

void ServiceMenuController::endProgram() {

}

void ServiceMenuController::newRequisitService() {
	RequisitServiceController *requisitServiceController =
			new RequisitServiceController(user, company);
	requisitServiceController->menu();
}

void ServiceMenuController::newServiceListMenu() {
	user->getId();
	company->getClients();
	ListServicesController *listServicesController = new ListServicesController(
			user, company);
	listServicesController->menu();
}

void ServiceMenuController::newClientMenu() {
	ClientMenuController *clientMenuController = new ClientMenuController(user,
			company);
	clientMenuController->menu();
}

