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
	theView->printVehicleList();
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
	int option;
	do {
		theView->printEnterOption();
		option = getMenuOption(0, 6);
		switch (option) {
		case 0:
			theView->printShutdown();
			endProgram();
			break;
		case 1:
			newVehicleMenu();
			break;
		case 2:
			seeVehicleMenu();
			break;
		case 3:
			changeVehicleMenu();
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
		}
	} while (option == -1);
}

int VehicleMenuController::getMenuOption(const int lowerBound,
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

bool VehicleMenuController::askVehiclePlate() {
	theView->printEnterPlate();
	return theView->getInfo(plate);
}

bool VehicleMenuController::getVehiclePlate() {
	if (plate == "0" && askVehiclePlate()) {
		return false;
	}
	bool flag = company->existVehicle(plate);
	if (!flag) {
		theView->printPlateNotFound();
	}
	return flag;
}

void VehicleMenuController::newVehicleMenu() {
	NewVehicleController *newVehicleController = new NewVehicleController(
			company);
	newVehicleController->menu();
}

void VehicleMenuController::seeVehicleMenu() {
	if (getVehiclePlate()) {
		SeeVehicleController *seeVehicleController = new SeeVehicleController(
				company, plate);
		seeVehicleController->menu();
	}
}

void VehicleMenuController::changeVehicleMenu() {
	if (getVehiclePlate()) {
		if (company->isVehicleAvailable(plate)) {
			ChangeVehicleController *changeVehicleController =
					new ChangeVehicleController(company, plate);
			changeVehicleController->menu();
		} else {
			theView->printVehicleNotAvailable();
		}
	}
}

void VehicleMenuController::sendVehicleToMaintenanceMenu() {
	if (getVehiclePlate()) {
		if (company->isVehicleAvailable(plate)) {
			company->changeVehicleInMaintenance(plate, true);
		} else {
			theView->printVehicleNotAvailable();
		}
	}
}

void VehicleMenuController::removeVehicleMenu() {
	if (getVehiclePlate()) {
		if (company->isVehicleAvailable(plate)) {
			RemoveVehicleController *removeVehicleController =
					new RemoveVehicleController(company, plate);
			removeVehicleController->menu();
		} else {
			theView->printVehicleNotAvailable();
		}
	}
}

void VehicleMenuController::newAdministratorMenu() {
	AdministratorMenuController *administratorMenuController =
			new AdministratorMenuController(company);
	administratorMenuController->menu();
}

void VehicleMenuController::endProgram() {
}
