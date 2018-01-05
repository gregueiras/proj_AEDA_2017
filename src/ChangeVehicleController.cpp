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
	int option;
	do {
		theView->printInformation(company->getVehicleInfoComplete(plate));
		theView->printChangeVehicleMenu();
		theView->printEnterOption();
		option = getMenuOption(0, 7);
		switch (option) {
		case 0:
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
		case 7:

			newVehicleMenuController();
			break;
		}
	} while (option != 0);
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

void ChangeVehicleController::changePlate() {
	string newPlate = getPlate();
	if (newPlate != "0") {
		company->changeVehiclePlate(plate, newPlate);
		this->plate = newPlate;
	}
}

void ChangeVehicleController::changeBrand() {
	string brand = getBrand();
	if (brand != "0") {
		company->changeVehicleBrand(plate, brand);
	}
}

void ChangeVehicleController::changeModel() {
	string model = getModel();
	if (model != "0") {
		company->changeVehicleModel(plate, model);
	}
}

void ChangeVehicleController::changeBirthdayDate() {
	Date *d = getBirthdayDate();
	if (!(d->getDay() == 1 && d->getMonth() == 1 && d->getYear() == 1)) {
		company->changeVehicleBirthday(plate, *d);
	}
}

void ChangeVehicleController::changeExpectableTime() {
	company->changeVehicleExpectedTime(plate, *getExpectableTime(),
			company->getVehicle(plate)->getExpectableDay());
}

void ChangeVehicleController::changeMaintenanceDate() {
	Date *d = getMaintenanceDate();
	if (!(d->getDay() == 1 && d->getMonth() == 1 && d->getYear() == 1)) {
		company->changeVehicleMaintenance(plate, *d);
	}
}

string ChangeVehicleController::getPlate() {
	string plate;
	do {
		theView->printEnterNewPlate();
		theView->getInfo(plate);
	} while (company->existVehicle(plate) == true);
	return plate;
}

string ChangeVehicleController::getBrand() {
	string brand;
	theView->printEnterNewBrand();
	theView->getInfo(brand);
	return brand;
}

string ChangeVehicleController::getModel() {
	string model;
	theView->printEnterNewModel();
	theView->getInfo(model);
	return model;
}

Date * ChangeVehicleController::getBirthdayDate() {
	theView->printEnterNewBirthdayDate();
	string date;
	unsigned int birthdayDay, birthdayMonth, birthdayYear;
	bool flag;
	do {
		do {
			theView->printEnterNewBirthdayDay();
			flag = theView->getInfo(birthdayDay);
		} while (flag == false);
		if (flag == true && birthdayDay == 0) {
			return new Date(1, 1, 1);
		}

		do {
			theView->printEnterNewBirthdayMonth();
			flag = theView->getInfo(birthdayMonth);
		} while (flag == false);
		if (flag == true && birthdayMonth == 0) {
			return new Date(1, 1, 1);
		}

		do {
			theView->printEnterNewBirthdayYear();
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

Hour* ChangeVehicleController::getExpectableTime() {
	theView->printEnterNewExpectableTime();
	unsigned int expectableHour, expectableMinute;
	string time;
	bool flag;
	do {
		do {
			theView->printEnterNewExpectableHour();
			flag = theView->getInfo(expectableHour);
		} while (flag == false);

//	if (expectableHour == 0) {
//		newVehicleMenuController();
//	}

		do {
			theView->printEnterNewExpectableMinute();
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

Date * ChangeVehicleController::getMaintenanceDate() {
	theView->printEnterNewMaintenanceDate();
	string date;
	unsigned int maintenanceDay, maintenanceMonth, maintenanceYear;
	bool flag;
	do {
		do {
			theView->printEnterNewMaintenanceDay();
			flag = theView->getInfo(maintenanceDay);
		} while (flag == false);
		if (flag == true && maintenanceDay == 0) {
			return new Date(1, 1, 1);
		}

		do {
			theView->printEnterNewMaintenanceMonth();
			flag = theView->getInfo(maintenanceMonth);
		} while (flag == false);

		if (flag == true && maintenanceMonth == 0) {
			return new Date(1, 1, 1);
		}

		do {
			theView->printEnterNewMaintenanceYear();
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

void ChangeVehicleController::endProgram() {
	theView->printEnd();
	theView->printShutdown();
	company->writeCompanyToFile();
	company->writeClientsToFile();
	company->writeVehiclesToFile();
	exit(0);
}

void ChangeVehicleController::newVehicleMenuController() {
	theView->printEnd();
	VehicleMenuController *vehicleMenuController = new VehicleMenuController(
			company);
	vehicleMenuController->menu();
}
