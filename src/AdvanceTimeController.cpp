/*
 * AdvanceTimeController.cpp
 *
 *  Created on: 4 Jan 2018
 *      Author: jotaa
 */

#include "AdvanceTimeController.h"

AdvanceTimeController::AdvanceTimeController(Company *company) {
	this->company = company;
	this->u = new Utilities();
	this->v = new Validation();
	this->theView = new AdvanceTimeView();
}

AdvanceTimeController::~AdvanceTimeController() {
	// TODO Auto-generated destructor stub
}

void AdvanceTimeController::menu() {
	menuHandler();
	updateCompanyInformation();
}

void AdvanceTimeController::menuHandler() {
	int option;
	do {
		theView->printCurrentDate(company->getCurrentDate().toStr());
		theView->printCurrentTime(company->getCurrentHour().toStr());
		theView->printAdvanceTimeMenu();
		theView->printEnterOption();
		option = getMenuOption(0, 3);
		switch (option) {
		case 0:
			endProgram();
			break;
		case 1:
			changeCompanyDate();
			break;
		case 2:
			changeCompanyHour();
			break;
		case 3:
			newAdministratorMenu();
			break;
		}
	} while (option != 0);
}

void AdvanceTimeController::updateCompanyInformation() {
	company->updateAvailableVehicles();
	company->setInactiveClients();
}

int AdvanceTimeController::getMenuOption(const int lowerBound,
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

void AdvanceTimeController::changeCompanyDate() {
	Date *d = getNewCurrentDate();
	if (!(d->getDay() == 1 && d->getMonth() == 1 && d->getYear() == 1)) {
		company->setCurrentDate(*d);
	}
}

void AdvanceTimeController::changeCompanyHour() {
	company->setCurrentHour(*getNewCurrentTime());
}

Date * AdvanceTimeController::getNewCurrentDate() {
	theView->printEnterNewCurrentDate();
	string date;
	unsigned int currentDay, currentMonth, currentYear;
	bool flag;
	do {
		do {
			theView->printEnterNewCurrentDay();
			flag = theView->getInfo(currentDay);
		} while (flag == false);
		if (flag == true && currentDay == 0) {
			return new Date(1, 1, 1);
		}

		do {
			theView->printEnterNewCurrentMonth();
			flag = theView->getInfo(currentMonth);
		} while (flag == false);
		if (flag == true && currentMonth == 0) {
			return new Date(1, 1, 1);
		}

		do {
			theView->printEnterNewCurrentYear();
			flag = theView->getInfo(currentYear);
		} while (flag == false);
		if (flag == true && currentYear == 0) {
			return new Date(1, 1, 1);
		}

		date = to_string(currentDay) + "/" + to_string(currentMonth) + "/"
				+ to_string(currentYear);
	} while (!v->validateDateFormat(date));

	return new Date(currentDay, currentMonth, currentYear);
}

Hour* AdvanceTimeController::getNewCurrentTime() {
	theView->printEnterNewCurrentTime();
	unsigned int currentHour, currentMinute;
	string time;
	bool flag;
	do {
		do {
			theView->printEnterNewCurrentHour();
			flag = theView->getInfo(currentHour);
		} while (flag == false);

//	if (currentHour == 0) {
//		newVehicleMenuController();
//	}

		do {
			theView->printEnterNewCurrentMinute();
			flag = theView->getInfo(currentMinute);
		} while (flag == false);
//
//	if (currentMinute == 0) {
//		newVehicleMenuController();
//	}
		time = to_string(currentHour) + ":" + to_string(currentMinute);
	} while (!v->validateHourFormat(time));
	return new Hour(currentHour, currentMinute);
}

void AdvanceTimeController::newAdministratorMenu() {
	theView->printEnd();
	AdministratorMenuController *administratorMenu =
			new AdministratorMenuController(company);
	administratorMenu->menu();
}

void AdvanceTimeController::endProgram() {
	theView->printEnd();
	theView->printShutdown();
	company->writeCompanyToFile();
	company->writeClientsToFile();
	company->writeVehiclesToFile();
	exit(0);
}
