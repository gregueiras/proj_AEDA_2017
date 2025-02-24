/*
 * SeeServiceController.cpp
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#include "SeeServiceController.h"

SeeServiceController::SeeServiceController(Services *service, Client *user,
		Company *company) {
	this->theView = new SeeServiceView;
	this->company = company;
	this->service = service;
	this->user = user;
}

SeeServiceController::~SeeServiceController() {
	// TODO Auto-generated destructor stub
}
void SeeServiceController::menu() {
	if (service->isVisibility()) {
		theView->printInitialMessage();
		theView->printServiceInformation(service->toStrComplete());
	}
	newServiceMenu();
}

void SeeServiceController::newServiceMenu() {
	theView->printEnd();
ServiceMenuController *serviceMenuController = new ServiceMenuController(
			user, company);
	serviceMenuController->menu();
}
