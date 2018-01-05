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
}

NewVehicleController::~NewVehicleController() {
	// TODO Auto-generated destructor stub
}

void NewVehicleController::menu() {
	theView->printInitialMessage();
	getNewVehicleInformation();
	createVehicle();
	newVehicleMenuController();
}

void NewVehicleController::getNewVehicleInformation() {
	plate = getPlate();
	if (plate == "0") {
		newVehicleMenuController();
	}

	brand = getBrand();
	if (brand == "0") {
		newVehicleMenuController();
	}

	model = getModel();
	if (model == "0") {
		newVehicleMenuController();
	}

	birthday = getBirthdayDate();
	if (birthday->getDay() == 1 && birthday->getMonth() == 1
			&& birthday->getYear() == 1) {
		cout << "10" << endl;
		newVehicleMenuController();
	}
	//expectable_time = getExpectableTime();

	maintenance = getMaintenanceDate();
	if (maintenance->getDay() == 1 && maintenance->getMonth() == 1
			&& maintenance->getYear() == 1) {
		newVehicleMenuController();
	}
}

string NewVehicleController::getPlate() {
	string plate;
	do {
		theView->printEnterPlate();
		theView->getInfo(plate);
	} while (company->existVehicle(plate) == true);
	return plate;
}

string NewVehicleController::getBrand() {
	string brand;
	theView->printEnterBrand();
	theView->getInfo(brand);
	return brand;
}

string NewVehicleController::getModel() {
	string model;
	theView->printEnterModel();
	theView->getInfo(model);
	return model;
}

Date * NewVehicleController::getBirthdayDate() {
	theView->printEnterBirthdayDate();
	string date;
	unsigned int birthdayDay, birthdayMonth, birthdayYear;
	bool flag;
	do {
		do {
			theView->printEnterBirthdayDay();
			flag = theView->getInfo(birthdayDay);
		} while (flag == false);
		if (flag == true && birthdayDay == 0) {
			return new Date(1, 1, 1);
		}

		do {
			theView->printEnterBirthdayMonth();
			flag = theView->getInfo(birthdayMonth);
		} while (flag == false);
		if (flag == true && birthdayMonth == 0) {
			return new Date(1, 1, 1);
		}

		do {
			theView->printEnterBirthdayYear();
			flag = theView->getInfo(birthdayYear);
		} while (flag == false);
		if (flag == true && birthdayYear == 0) {
			return new Date(1, 1, 1);
		}

		date = to_string(birthdayDay) + "/" + to_string(birthdayMonth) + "/"
				+ to_string(birthdayYear);
	} while (!v->validateDateFormat(date));
	return new Date(birthdayDay, birthdayMonth, birthdayYear);
}

Hour * NewVehicleController::getExpectableTime() {
	theView->printEnterExpectableTime();
	unsigned int expectableHour, expectableMinute;
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
	return new Hour(expectableHour, expectableMinute);
}

Date * NewVehicleController::getMaintenanceDate() {
	theView->printEnterMaintenanceDate();
	string date;
	unsigned int maintenanceDay, maintenanceMonth, maintenanceYear;
	bool flag;
	do {
		do {
			theView->printEnterMaintenanceDay();
			flag = theView->getInfo(maintenanceDay);
		} while (flag == false);
		if (flag == true && maintenanceDay == 0) {
			return new Date(1, 1, 1);
		}

		do {
			theView->printEnterMaintenanceMonth();
			flag = theView->getInfo(maintenanceMonth);
		} while (flag == false);

		if (flag == true && maintenanceMonth == 0) {
			return new Date(1, 1, 1);
		}

		do {
			theView->printEnterMaintenanceYear();
			flag = theView->getInfo(maintenanceYear);
		} while (flag == false);
		if (flag == true && maintenanceYear == 0) {
			return new Date(1, 1, 1);
		}
		date = to_string(maintenanceDay) + "/" + to_string(maintenanceMonth)
				+ "/" + to_string(maintenanceYear);
	} while (!v->validateDateFormat(date));
	return new Date(maintenanceDay, maintenanceMonth, maintenanceYear);
}

void NewVehicleController::createVehicle() {
	Vehicle vehicle(plate, brand, model, *birthday, Hour(0, 0), *maintenance,
			true, false);
	if (!company->addVehicle(vehicle)) {
		theView->printRepeatedVehicle();
	}
	company->updateAvailableVehicles();
}

void NewVehicleController::newVehicleMenuController() {
	theView->printEnd();
	VehicleMenuController *vehicleMenuController = new VehicleMenuController(
			company);
	vehicleMenuController->menu();
}
