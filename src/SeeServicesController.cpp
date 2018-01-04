/*
 * SeeServicesController.cpp
 *
 *  Created on: 25 Dec 2017
 *      Author: jotaa
 */

#include "SeeServicesController.h"

SeeServicesController::SeeServicesController(Company *company) {
	this->theView = new SeeServicesView;
	this->company = company;
}

SeeServicesController::~SeeServicesController() {
	// TODO Auto-generated destructor stub
}

void SeeServicesController::menu() {
	printServicesInvoices();
	newAdministratorMenu();
}

void SeeServicesController::printServicesInvoices() {
	vector<Client*> clients_temp = company->getClients();
	if (clients_temp.size() == 0) {
		theView->printNoVehiclesRegistered();
	} else {
		theView->printListServices();
		for (size_t i = 0; i < clients_temp.size(); i++) {
			theView->printInformation(clients_temp.at(i)->clientToString(true));
		}
	}

}

void SeeServicesController::newAdministratorMenu() {
	AdministratorMenuController *administratorMenu =
			new AdministratorMenuController(company);
	administratorMenu->menu();
}

void SeeServicesController::endProgram() {
}
