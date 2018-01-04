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
	menuHandler();
}

void VehicleMenuController::listVehicles() {
	theView->printVehicleList();
	priority_queue<Vehicle> temp = company->getVehicles();
	if (temp.size() == 0) {
		theView->printNoVehicleRegistered();
	} else {
		while (!temp.empty()) {
			Vehicle vehicle = temp.top();
			string info = vehicle.toStrShort();
			theView->printInformation(info);
			temp.pop();
		}
	}
}

void VehicleMenuController::menuHandler() {
	int option;
	do {
		listVehicles();
		theView->printVehicleMenu();
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
	} while (option != 0);
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

string VehicleMenuController::getVehiclePlate() {
	string plate = "0";
	bool flag = false;
	do {
		theView->printEnterPlate();
		flag = theView->getInfo(plate);
	} while (!flag);
	return plate;
}

void VehicleMenuController::newVehicleMenu() {
	NewVehicleController *newVehicleController = new NewVehicleController(
			company);
	newVehicleController->menu();
}

void VehicleMenuController::seeVehicleMenu() {
	plate = getVehiclePlate();
	if (plate != "0") {
		if (company->getVehicle(plate) != NULL) {
			SeeVehicleController *seeVehicleController =
					new SeeVehicleController(company, plate);
			seeVehicleController->menu();
		} else {
			theView->printPlateNotFound();
		}
	}
}

void VehicleMenuController::changeVehicleMenu() {
	plate = getVehiclePlate();
	if (plate != "0") {
		if (company->getVehicle(plate) != NULL) {
			if (company->isVehicleAvailable(plate)) {
				ChangeVehicleController *changeVehicleController =
						new ChangeVehicleController(company, plate);
				changeVehicleController->menu();
			} else {
				theView->printVehicleNotAvailable();
			}
		} else {
			theView->printPlateNotFound();
		}
	}
}

void VehicleMenuController::sendVehicleToMaintenanceMenu() {
	plate = getVehiclePlate();
	if (plate != "0") {
		if (company->getVehicle(plate) != NULL) {
			if (company->isVehicleAvailable(plate)) {
				company->changeVehicleInMaintenance(plate, true);
			} else {
				theView->printVehicleNotAvailable();
			}
		} else {
			theView->printPlateNotFound();
		}
	}
}

void VehicleMenuController::removeVehicleMenu() {
	plate = getVehiclePlate();
	if (plate != "0") {
		if (company->getVehicle(plate) != NULL) {
			if (company->isVehicleAvailable(plate)) {
				RemoveVehicleController *removeVehicleController =
						new RemoveVehicleController(company, plate);
				removeVehicleController->menu();
			} else {
				theView->printVehicleNotAvailable();
			}
		} else {
			theView->printPlateNotFound();
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
