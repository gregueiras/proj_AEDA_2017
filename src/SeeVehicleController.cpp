/*
 * SeeVehicleController.cpp
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#include "SeeVehicleController.h"

SeeVehicleController::SeeVehicleController(Company *company, string plate) {
	this->theView = new SeeVehicleView();
	this->plate = plate;
	this->company = company;
}

SeeVehicleController::~SeeVehicleController() {
	// TODO Auto-generated destructor stub
}

void SeeVehicleController::menu() {
	theView->printInitialMessage();
	theView->printInformation(company->getVehicleInfoComplete(plate));
	newVehicleMenuController();
}

void SeeVehicleController::newVehicleMenuController() {
	VehicleMenuController *vehicleMenuController = new VehicleMenuController(
			company);
	vehicleMenuController->menu();
}
