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
	listServices();
	serviceMenuHandler();
}

void ServiceMenuController::listServices() {
	vector<Services *> services = user->getServices();
	theView->printServicesListing();
	if (services.size() == 0) {
		theView->printNoServicesRegistered();
	} else {
		for (size_t i = 0; i < services.size(); i++) {
			if (services.at(i)->isVisibility()) {
				theView->printServiceInfo(services.at(i)->getId(),
						services.at(i)->toStrShort());
			}
		}
	}
}

void ServiceMenuController::printListServicesByUserType() {
	if (dynamic_cast<Business*>(user)) {
		theView->printServiceMenuForBusinnessClients();
	} else {
		theView->printServiceMenu();
	}
}

void ServiceMenuController::serviceMenuHandler() {
	int option;
	do {
		printListServicesByUserType();
		theView->printEnterOption();
		option = getMenuOption(0, 6);
		switch (option) {
		case 0:
			endProgram();
			break;
		case 1:
			newRequisitService();
			break;
		case 2:
			newSeeService();
			break;
		case 3:
			newSortServicesMenu();
			break;
		case 4:
			newFilterServicesMenu();
			break;
		case 5:
			if (dynamic_cast<Business*>(user)) {
				newPayServiceMenu();
			} else {
				newClientMenu();
			}
			break;
		case 6:
			if (dynamic_cast<Business*>(user)) {
				newClientMenu();
			}
			break;
		}
	} while (option != 0);
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

int ServiceMenuController::getServiceID() {
	int id;
	theView->printEnterServiceID();
	bool flag1 = theView->getInfo(id);
	if (flag1 == false || id < 1) {
		return -1;
	}
	return id;
}

void ServiceMenuController::newRequisitService() {
	theView->printEnd();
	RequisitServiceController *requisitServiceController =
			new RequisitServiceController(user, company);
	requisitServiceController->menu();
}

void ServiceMenuController::newSeeService() {
	serviceID = getServiceID();
	if (serviceID != 0) {
		Services s = user->getServiceById(serviceID);
		if (s.getVolume() != 0) {
			theView->printEnd();
			SeeServiceController *seeServiceController =
					new SeeServiceController(&s, user, company);
			seeServiceController->menu();
		} else {
			theView->printServiceIDNotFound();
		}
	}
}

void ServiceMenuController::newSortServicesMenu() {
	theView->printEnd();
	SortServicesController *sortServicesController = new SortServicesController(
			user, company);
	sortServicesController->menu();
}

void ServiceMenuController::newFilterServicesMenu() {
	theView->printEnd();
	FilterServicesController *filterServicesController =
			new FilterServicesController(user, company);
	filterServicesController->menu();
}

void ServiceMenuController::newPayServiceMenu() {
	theView->printEnd();
	PayServiceController *payServiceController = new PayServiceController(user,
			-1, company);
	payServiceController->menu();
}

void ServiceMenuController::newClientMenu() {
	theView->printEnd();
	ClientMenuController *clientMenuController = new ClientMenuController(user,
			company);
	clientMenuController->menu();
}

void ServiceMenuController::endProgram() {
	theView->printEnd();
	theView->printShutdown();
	company->writeCompanyToFile();
	company->writeClientsToFile();
	company->writeVehiclesToFile();
	exit(0);
}

