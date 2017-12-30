/*
 * ChangeVehicleController.cpp
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#include "ChangeVehicleController.h"

ChangeVehicleController::ChangeVehicleController(Company *company,
		string plate) {
	this->company = company;
	this->plate = plate;
	this->theView = new ChangeVehicleView();
	this->v = new Validation();
}

ChangeVehicleController::~ChangeVehicleController() {
	// TODO Auto-generated destructor stub
}

void ChangeVehicleController::menu() {
	menuHandler();
	newVehicleMenuController();
}

void ChangeVehicleController::menuHandler() {
	int option;
	theView->printInformation(company->getVehicleInfoComplete(plate));
	theView->printChangeVehicleMenu();
		do {
		theView->printEnterOption();
		option = getMenuOption(0, 6);
		switch (option) {
		case 0:
			theView->printShutdown();
			endProgram();
			break;
		case 1:
			changePlate();
			break;
		case 2:
			changeBrand();
			break;
		case 3:
			changeModel();
			break;
		case 4:
			changeBirthdayDate();
			break;
		case 5:
			changeExpectableTime();
			break;
		case 6:
			changeMaintenanceDate();
			break;
		}
	} while (option == -1);
	theView->printEnd();
}

int ChangeVehicleController::getMenuOption(const int lowerBound,
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

void ChangeVehicleController::endProgram() {
}

void ChangeVehicleController::changePlate() {
	string newPlate = getPlate();
	company->changeVehiclePlate(plate, newPlate);
	this->plate = newPlate;
}

void ChangeVehicleController::changeBrand() {
	string brand = getBrand();
	company->changeVehicleBrand(plate, brand);
}

void ChangeVehicleController::changeModel() {
	company->changeVehicleModel(plate, getModel());
}

void ChangeVehicleController::changeBirthdayDate() {
	company->changeVehicleBirthday(plate, *getBirthdayDate());
}

void ChangeVehicleController::changeExpectableTime() {
	company->changeVehicleExpectedTime(plate, *getExpectableTime());
}

void ChangeVehicleController::changeMaintenanceDate() {
	company->changeVehicleMaintenance(plate, *getMaintenanceDate());
}

string ChangeVehicleController::getPlate() {
	string plate;
	theView->printEnterNewPlate();
	bool flag = theView->getInfo(plate);
	if (plate == "0") {
		newVehicleMenuController();
	}
	return plate;
}

string ChangeVehicleController::getBrand() {
	string brand;
	theView->printEnterNewBrand();
	bool flag = theView->getInfo(brand);
	if (brand == "0") {
		newVehicleMenuController();
	}
	return brand;
}

string ChangeVehicleController::getModel() {
	string model;
	theView->printEnterNewModel();
	bool flag = theView->getInfo(model);
	if (model == "0") {
		newVehicleMenuController();
	}
	return model;
}

Date * ChangeVehicleController::getBirthdayDate() {
	theView->printEnterNewBirthdayDate();
	string date;
	unsigned int birthdayDay, birthdayMonth, birthdayYear;
	do {
		theView->printEnterNewBirthdayDay();
		theView->getInfo(birthdayDay);
		if (birthdayDay == 0) {
			newVehicleMenuController();
		}

		theView->printEnterNewBirthdayMonth();
		theView->getInfo(birthdayMonth);
		if (birthdayMonth == 0) {
			newVehicleMenuController();
		}

		theView->printEnterNewBirthdayYear();
		theView->getInfo(birthdayYear);
		if (birthdayYear == 0) {
			newVehicleMenuController();
		}
		date = to_string(birthdayDay) + "/" + to_string(birthdayMonth) + "/"
				+ to_string(birthdayYear);
	} while (!v->validateDateFormat(date));
	return new Date(birthdayDay, birthdayMonth, birthdayYear);
}

Hour* ChangeVehicleController::getExpectableTime() {
	theView->printEnterNewExpectableTime();
	unsigned int expectableHour, expectableMinute;
	theView->printEnterNewExpectableHour();
	theView->getInfo(expectableHour);
	if (expectableHour == 0) {
		newVehicleMenuController();
	}
	theView->printEnterNewExpectableMinute();
	theView->getInfo(expectableMinute);
	if (expectableMinute == 0) {
		newVehicleMenuController();
	}
	return new Hour(expectableHour, expectableMinute);
}

Date * ChangeVehicleController::getMaintenanceDate() {
	theView->printEnterNewMaintenanceDate();
	string date;
	unsigned int maintenanceDay, maintenanceMonth, maintenanceYear;
	do {
		theView->printEnterNewMaintenanceDay();
		theView->getInfo(maintenanceDay);
		if (maintenanceDay == 0) {
			newVehicleMenuController();
		}

		theView->printEnterNewMaintenanceMonth();
		theView->getInfo(maintenanceMonth);
		if (maintenanceMonth == 0) {
			newVehicleMenuController();
		}

		theView->printEnterNewMaintenanceYear();
		theView->getInfo(maintenanceYear);
		if (maintenanceYear == 0) {
			newVehicleMenuController();
		}
		date = to_string(maintenanceDay) + "/" + to_string(maintenanceMonth)
				+ "/" + to_string(maintenanceYear);
	} while (!v->validateDateFormat(date));
	return new Date(maintenanceDay, maintenanceMonth, maintenanceYear);
}

void ChangeVehicleController::newVehicleMenuController() {
	VehicleMenuController *vehicleMenuController = new VehicleMenuController(
			company);
	vehicleMenuController->menu();
}
