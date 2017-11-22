/*
 * RemoveServiceController.cpp
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#include "RemoveServiceController.h"

RemoveServiceController::~RemoveServiceController() {
	// TODO Auto-generated destructor stub
}
RemoveServiceController::RemoveServiceController(Client *user,
		unsigned int serviceID, Company *company) {
	theView = new RemoveServiceView;
	v = new Validation();
	u = new Utilities();
	this->serviceID = serviceID;
	this->company = company;
	this->user = user;
}

void RemoveServiceController::menu() {
}

void RemoveServiceController::newListServicesMenu() {
	ListServicesController *listServicesController = new ListServicesController(
			user, company);
	listServicesController->menu();
}
