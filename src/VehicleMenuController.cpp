/*
 * VehicleMenuController.cpp
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#include "VehicleMenuController.h"

VehicleMenuController::VehicleMenuController(Company *company) {
	this->company = company;
	this->theView = new VehicleMenuView();
	this->v = new Validation();
	plate = "";
}

VehicleMenuController::~VehicleMenuController() {
	// TODO Auto-generated destructor stub
}

void VehicleMenuController::menu() {
	listVehicles();
	menuHandler();
}

void VehicleMenuController::listVehicles() {
	priority_queue<Vehicle> temp = company->getVehicles();
	while (!temp.empty()) {
		Vehicle vehicle = temp.top();
		string info = vehicle.toStrShort();
		theView->printInformation(info);
		temp.pop();
	}
}
void VehicleMenuController::menuHandler() {
	theView->printVehicleMenu();
	theView->printEnterOption();
	int option = getMenuOption(0, 6);
	switch (option) {
	case 0:
		theView->printShutdown();
		endProgram();
		break;
	case 1:
		seeVehicleMenu(getVehiclePlate());
		break;
	case 2:
		newVehicleMenu();
		break;
	case 3:
		changeVehicleMenu(getVehiclePlate());
		break;
	case 4:
		sendVehicleToMaintenanceMenu();
		break;
	case 5:
		removeVehicleMenu();
		break;
	case 6:
		newAdministratorMenu();
		break;
	default:
		newAdministratorMenu();
		break;
	}
}

int VehicleMenuController::getMenuOption(const int lowerBound,
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

bool VehicleMenuController::getVehicle() {
	plate = getVehiclePlate();
	if (plate == "0") {
		theView->printPlateNotFound();
		return false;
	}
	return company->existVehicle(plate);
}

string VehicleMenuController::getVehiclePlate() {
	string plate;
	theView->printEnterPlate();
	theView->getInfo(plate);
	return plate;
}

void VehicleMenuController::seeVehicleMenu(const string plate) {
	if (getVehicle()) {
		SeeVehicleController *seeVehicleController = new SeeVehicleController(
				company, plate);
		seeVehicleController->menu();
	}
}

void VehicleMenuController::newVehicleMenu() {
	NewVehicleController *newVehicleController = new NewVehicleController(
			company);
	newVehicleController->menu();
}

void VehicleMenuController::changeVehicleMenu(const string plate) {
	if (getVehicle() && company->isVehicleAvailable(plate)) {
		ChangeVehicleController *changeVehicleController =
				new ChangeVehicleController(company, plate);
		changeVehicleController->menu();
	}
}

void VehicleMenuController::sendVehicleToMaintenanceMenu() {
	if (getVehicle() && company->isVehicleAvailable(plate)) {
		company->changeVehicleInMaintenance(plate, true);
	}
}

void VehicleMenuController::removeVehicleMenu() {
	if (getVehicle() && company->isVehicleAvailable(plate)) {
		RemoveVehicleController *removeVehicleController =
				new RemoveVehicleController(company, plate);
		removeVehicleController->menu();
	}
}

void VehicleMenuController::newAdministratorMenu() {
	AdministratorMenuController *administratorMenuController =
			new AdministratorMenuController(company);
	administratorMenuController->menu();
}

void VehicleMenuController::endProgram() {
}
