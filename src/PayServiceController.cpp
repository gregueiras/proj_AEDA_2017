/*
 * PayServiceController.cpp
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#include "PayServiceController.h"

PayServiceController::PayServiceController(Client *user, unsigned int serviceID,
		Company *company) {
	this->theView = new PayServiceView;
	v = new Validation();
	u = new Utilities();
	this->user = user;
	this->serviceID = serviceID;
	this->company = company;
}

PayServiceController::~PayServiceController() {
	// TODO Auto-generated destructor stub
}

void PayServiceController::newListServicesMenu() {
	ListServicesController *listServicesController = new ListServicesController(
			user, company);
	listServicesController->menu();
}

void PayServiceController::menu() {
}
