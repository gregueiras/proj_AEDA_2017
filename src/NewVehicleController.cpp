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
	newVehicleMenuController();
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
	do {
		theView->printEnterPlate();
		theView->getInfo(plate);
		if (plate == "0") {
			newVehicleMenuController();
		}
	} while (company->existVehicle(plate) == true);
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
	theView->getInfo(model);
	if (model == "0") {
		newVehicleMenuController();
	}
}

void NewVehicleController::getBirthdayDate() {
	theView->printEnterBirthdayDate();
	string date;
	bool flag;
	do {
		do {
			theView->printEnterBirthdayDay();
			flag = theView->getInfo(birthdayDay);
		} while (flag == false);

		if (birthdayDay == 0) {
			newVehicleMenuController();
		}
		do {
			theView->printEnterBirthdayMonth();
			flag = theView->getInfo(birthdayMonth);
		} while (flag == false);

		if (birthdayMonth == 0) {
			newVehicleMenuController();
		}

		do {
			theView->printEnterBirthdayYear();
			flag = theView->getInfo(birthdayYear);
		} while (flag == false);

		if (birthdayYear == 0) {
			newVehicleMenuController();
		}
		date = to_string(birthdayDay) + "/" + to_string(birthdayMonth) + "/"
				+ to_string(birthdayYear);
	} while (!v->validateDateFormat(date));
}

void NewVehicleController::getExpectableTime() {
	theView->printEnterExpectableTime();
	string time;
	bool flag;
	do {
		do {
			theView->printEnterExpectableHour();
			flag = theView->getInfo(expectableHour);
		} while (flag == false);

//	if (expectableHour == 0) {
//		newVehicleMenuController();
//	}

		do {
			theView->printEnterExpectableMinute();
			flag = theView->getInfo(expectableMinute);
		} while (flag == false);
//
//	if (expectableMinute == 0) {
//		newVehicleMenuController();
//	}
		time = to_string(expectableHour) + ":" + to_string(expectableMinute);
	} while (!v->validateHourFormat(time));
}

void NewVehicleController::getMaintenanceDate() {
	theView->printEnterMaintenanceDate();
	string date;
	bool flag;
	do {
		do {
			theView->printEnterMaintenanceDay();
			flag = theView->getInfo(maintenanceDay);
		} while (flag == false);
		if (maintenanceDay == 0) {
			newVehicleMenuController();
		}

		do {
			theView->printEnterMaintenanceMonth();
			flag = theView->getInfo(maintenanceMonth);
		} while (flag == false);
		if (maintenanceMonth == 0) {
			newVehicleMenuController();
		}

		do {
			theView->printEnterMaintenanceYear();
			flag = theView->getInfo(maintenanceYear);
		} while (flag == false);
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
	theView->printEnd();
	VehicleMenuController *vehicleMenuController = new VehicleMenuController(
			company);
	vehicleMenuController->menu();
}
