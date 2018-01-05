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
	int option;
	do {
		theView->printRemoveVehicleMenu();
		theView->printEnterOption();
		option = getMenuOption(0, 2);
		switch (option) {
		case 0:
			endProgram();
			break;
		case 1:
			removeVehicle();
			newVehicleMenuController();
			break;
		case 2:
			newVehicleMenuController();
			break;
		}
	} while (option != 0);
}

int RemoveVehicleController::getMenuOption(const int lowerBound,
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
void RemoveVehicleController::removeVehicle() {
	theView->printEnterConfirmation();
	int option;
	bool flag = theView->getInfo(option);
	if (flag == true && option == 1) {
		company->removeVehicle(vehiclePlate);
	}
}

void RemoveVehicleController::newVehicleMenuController() {
	theView->printEnd();
	VehicleMenuController *vehicleMenuController = new VehicleMenuController(
			company);
	vehicleMenuController->menu();
}

void RemoveVehicleController::endProgram() {
	theView->printEnd();
	theView->printShutdown();
	company->writeCompanyToFile();
	company->writeClientsToFile();
	company->writeVehiclesToFile();
	exit(0);
}
