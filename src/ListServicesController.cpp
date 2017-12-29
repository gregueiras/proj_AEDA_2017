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
	theView->printServicesListing();
	listServices();

	printListServicesByUserType();
	listServicesMenuHandler();
}

void ListServicesController::listServices() {
	vector<Services *> services = user->getServices();
	for (size_t i = 0; i < services.size(); i++) {
		if (services.at(i)->isVisibility()) {
			//		cout << "ID: " << services.at(i)->getId() << " "
			//			<< services.at(i)->toStrShort() << endl;
			theView->printServiceInfo(services.at(i)->getId(),
					services.at(i)->toStrShort());
		}
	}
}

void ListServicesController::printListServicesByUserType() {
	if (dynamic_cast<Business*>(user)) {
		theView->printListServicesMenuForBusinnessClients();
	} else {
		theView->printListServicesMenu();
	}
}

int ListServicesController::getServiceID() {
	int id;
	theView->printEnterServiceID();
	theView->getInfo(id);
	if (id == 10) {
		newServiceMenu();
	}
	return id;
}
void ListServicesController::listServicesMenuHandler() {
	theView->printEnterOption();
	int option = getMenuOption(0, 7);
	switch (option) {
	case 0:
		theView->printEnd();
		endProgram();
		break;
	case 1:
		serviceID = getServiceID();
		newSeeService();
		break;
	case 2:
		newSortServicesMenu();
		break;
	case 3:
		newFilterServicesMenu();
		break;
	case 4:
		serviceID = getServiceID();
		newChangeServiceMenu();
		break;
	case 5:
		newRemoveServiceMenu();
		break;
	case 6:
		if (dynamic_cast<Business*>(user)) {
			newPayServiceMenu();
		} else {
			newServiceMenu();
		}
		break;
	case 7:
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
		theView->getInfo(option);
		if (!(flag = v->validateBound(option, lowerBound, upperBound))) {
			theView->printWrongOption();
		}
	}
	return option;
}

void ListServicesController::endProgram() {

}

void ListServicesController::newSeeService() {

	Services s1 = user->getServiceById(serviceID);
	Services* ss1 = &s1;

	SeeServiceController *seeServiceController = new SeeServiceController(ss1,
			user, company);
	seeServiceController->menu();
}

void ListServicesController::newChangeServiceMenu() {

	Services s1 = user->getServiceById(serviceID);
	ChangeServiceController *changeServiceController =
			new ChangeServiceController(&s1, user, company);

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
			-1, company);
	payServiceController->menu();
}

void ListServicesController::newServiceMenu() {
	ServiceMenuController *serviceMenuController = new ServiceMenuController(
			user, company);
	serviceMenuController->menu();
}
