/*
 * ChangeServiceController.cpp
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#include "ChangeServiceController.h"

ChangeServiceController::ChangeServiceController(Services *service,
		Client *user, Company *company) {
	theView = new ChangeServiceView;
	v = new Validation();
	u = new Utilities();
	this->user = user;
	this->company = company;
	this->service = service;
}

ChangeServiceController::~ChangeServiceController() {
	// TODO Auto-generated destructor stub
}

void ChangeServiceController::menu() {
}

void ChangeServiceController::newListServicesMenu() {
	ListServicesController *listServicesController = new ListServicesController(
			user, company);
	listServicesController->menu();
}
