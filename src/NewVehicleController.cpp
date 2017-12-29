/*
 * NewVehicleController.cpp
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#include "NewVehicleController.h"

NewVehicleController::NewVehicleController(Company *company) {
	this->company = company;
	this->theView = new NewVehicleView();
	this->v = new Validation();
	plate = "0";
	brand = "0";
	model = "0";
	birthdayDay = 0;
	birthdayMonth = 0;
	birthdayYear = 0;
	expectableHour = 0;
	expectableMinute = 0;
	maintenanceDay = 0;
	maintenanceMonth = 0;
	maintenanceYear = 0;

}

NewVehicleController::~NewVehicleController() {
	// TODO Auto-generated destructor stub
}

void NewVehicleController::menu() {
	theView->printInitialMessage();
	getVehicleInformation();
	createVehicle();
}

void NewVehicleController::getVehicleInformation() {
	getPlate();
	getBrand();
	getModel();
	getBirthdayDate();
	getExpectableTime();
	getMaintenanceDate();
}

void NewVehicleController::getPlate() {
	theView->printEnterPlate();
	theView->getInfo(plate);
	if (plate == "0") {
		newVehicleMenuController();
	}
}

void NewVehicleController::getBrand() {
	theView->printEnterBrand();
	theView->getInfo(brand);
	if (brand == "0") {
		newVehicleMenuController();
	}
}

void NewVehicleController::getModel() {
	theView->printEnterModel();
	bool flag = theView->getInfo(model);
	if (model == "0") {
		newVehicleMenuController();
	}
}

void NewVehicleController::getBirthdayDate() {
	theView->printEnterBirthdayDate();
	string date;
	do {
		theView->printEnterBirthdayDay();
		theView->getInfo(birthdayDay);
		if (birthdayDay == 0) {
			newVehicleMenuController();
		}

		theView->printEnterBirthdayMonth();
		theView->getInfo(birthdayMonth);
		if (birthdayMonth == 0) {
			newVehicleMenuController();
		}

		theView->printEnterBirthdayYear();
		theView->getInfo(birthdayYear);
		if (birthdayYear == 0) {
			newVehicleMenuController();
		}
		date = to_string(birthdayDay) + "/" + to_string(birthdayMonth) + "/"
				+ to_string(birthdayYear);
	} while (!v->validateDateFormat(date));
}

void NewVehicleController::getExpectableTime() {
	theView->printEnterExpectableTime();
	theView->printEnterExpectableHour();
	theView->getInfo(expectableHour);
	if (expectableHour == 0) {
		newVehicleMenuController();
	}
	theView->printEnterExpectableMinute();
	theView->getInfo(expectableMinute);
	if (expectableMinute == 0) {
		newVehicleMenuController();
	}
}

void NewVehicleController::getMaintenanceDate() {
	theView->printEnterMaintenanceDate();
	string date;
	do {
		theView->printEnterMaintenanceDay();
		theView->getInfo(maintenanceDay);
		if (maintenanceDay == 0) {
			newVehicleMenuController();
		}

		theView->printEnterMaintenanceMonth();
		theView->getInfo(maintenanceMonth);
		if (maintenanceMonth == 0) {
			newVehicleMenuController();
		}

		theView->printEnterMaintenanceYear();
		theView->getInfo(maintenanceYear);
		if (maintenanceYear == 0) {
			newVehicleMenuController();
		}
		date = to_string(maintenanceDay) + "/" + to_string(maintenanceMonth)
				+ "/" + to_string(maintenanceYear);
	} while (!v->validateDateFormat(date));
}

void NewVehicleController::createVehicle() {
	Date birthday(birthdayDay, birthdayMonth, birthdayYear);
	Hour expectable_time(expectableHour, expectableMinute);
	Date maintenance(maintenanceDay, maintenanceMonth, maintenanceYear);
	Vehicle vehicle(plate, brand, model, birthday, expectable_time, maintenance,
			true, false);
	if (!company->addVehicle(vehicle)) {
		theView->printRepeatedVehicle();
	}
}

void NewVehicleController::newVehicleMenuController() {
	VehicleMenuController *vehicleMenuController = new VehicleMenuController(
			company);
	vehicleMenuController->menu();
}
