/*
 * ListServicesController.cpp
 *
 *  Created on: 13/11/2017
 *      Author: jotaa
 */

#include "ListServicesController.h"
#include "SeeServiceController.h"
//#include "Services.h"
ListServicesController::ListServicesController(Client *client,
		Company *company) {
	this->theView = new ListServicesView;
	this->company = company;
	v = new Validation();
	u = new Utilities();
	user = client;
	serviceID = 0;
}

ListServicesController::~ListServicesController() {
}

void ListServicesController::menu() {
	theView->printListServicesMenu();
	listServices();
	serviceID = getServiceID();
	listServicesHandler(serviceID);
}

int ListServicesController::getServiceID() {
	int id;
	theView->printEnterServiceID();
	getInfo(id);
	return id;
}

void ListServicesController::listServices() {
	vector<Services *> services = user->getServices();
	for (size_t i = 0; i < services.size(); i++) {
		if (services.at(i)->isVisibility()) {
			theView->printServiceInfo(services.at(i)->getId(),
					services.at(i)->toStrShort());
		}
	}
}

void ListServicesController::listServicesHandler(int serviceID) {
	theView->printEnterOption();
	int option = getMenuOption(0, 7);
	switch (option) {
	case 0:
		theView->printEnd();
		endProgram();
		break;
	case 1:
		newSeeService();
		break;
	case 2:
		newSortServicesMenu();
		break;
	case 3:
		newFilterServicesMenu();
		break;
	case 4:
		newChangeServiceMenu();
		break;
	case 5:
		newRemoveServiceMenu();
		break;
	case 6:
		newPayServiceMenu();
		break;
	case 7:
		newServiceMenu();
		break;
	default:
		newServiceMenu();
		break;
	}
}

int ListServicesController::getMenuOption(const int lowerBound,
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

void ListServicesController::endProgram() {
	exit(0);
}

void ListServicesController::newSeeService() {

	Services s1 = user->getServiceById(serviceID);
	Services* ss1 = &s1;
	SeeServiceController *seeServiceController = new SeeServiceController(
			ss1, user, company);
	seeServiceController->menu();
}

void ListServicesController::newChangeServiceMenu() {

	Services s1 = user->getServiceById(serviceID);
	Services* ss1 = &s1;

	ChangeServiceController *changeServiceController =
			new ChangeServiceController(ss1, user, company);

	changeServiceController->menu();
}

void ListServicesController::newRemoveServiceMenu() {
	RemoveServiceController *removeServiceController =
			new RemoveServiceController(user, serviceID, company);

	removeServiceController->menu();
}

void ListServicesController::newFilterServicesMenu() {
	FilterServicesController *filterServicesController =
			new FilterServicesController(user, company);

	filterServicesController->menu();
}

void ListServicesController::newSortServicesMenu() {
	SortServicesController *sortServicesController = new SortServicesController(
			user, company);

	sortServicesController->menu();
}

void ListServicesController::newPayServiceMenu() {
	PayServiceController *payServiceController = new PayServiceController(user,
			serviceID, company);
	payServiceController->menu();
}

void ListServicesController::newServiceMenu() {
	ServiceMenuController *serviceMenuController = new ServiceMenuController(
			user, company);
	serviceMenuController->menu();
}
