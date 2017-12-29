/*
 * RemoveVehicleController.cpp
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#include "RemoveVehicleController.h"

RemoveVehicleController::RemoveVehicleController(Company *company,
		string vehiclePlate) {
	this->theView = new RemoveVehicleView;
	this->company = company;
	this->vehiclePlate = vehiclePlate;
	v = new Validation();

}

RemoveVehicleController::~RemoveVehicleController() {
	// TODO Auto-generated destructor stub
}

void RemoveVehicleController::menu() {
	theView->printRemoveVehicleMenu();
	removeVehicleHandler();
}

void RemoveVehicleController::removeVehicleHandler() {
	theView->printEnterOption();
	int option = getMenuOption(0, 2);
	switch (option) {
	case 0:
		theView->printEnd();
		endProgram();
		break;
	case 1:
		removeVehicle();
		newVehicleMenuController();
		break;
	case 2:
		newVehicleMenuController();
		break;
	default:
		newVehicleMenuController();
		break;
	}
}

int RemoveVehicleController::getMenuOption(const int lowerBound,
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
void RemoveVehicleController::removeVehicle() {
	theView->printEnterConfirmation();
	int option;
	theView->getInfo(option);
	if (option == 1) {
		company->removeVehicle(vehiclePlate);
	}
}

void RemoveVehicleController::newVehicleMenuController() {
	VehicleMenuController *vehicleMenuController = new VehicleMenuController(
			company);
	vehicleMenuController->menu();
}

void RemoveVehicleController::endProgram() {
}
