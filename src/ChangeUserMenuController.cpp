/*
 * ChangeMenuController.cpp

 *  Created on: 08/11/2017
 *      Author: jotaa
 */

#include "ChangeUserMenuController.h"

ChangeUserMenuController::ChangeUserMenuController(Client *client, Company *company) {
	this->theView = new ChangeUserMenuView;
	this->company = company;
	u = new Utilities();
	v = new Validation();
	user = client;
}

ChangeUserMenuController::~ChangeUserMenuController() {
}

void ChangeUserMenuController::menu() {
	theView->printUserInfo(user->getInfoDisp());
	theView->printChangeUser();
	menuHandler();
}

void ChangeUserMenuController::menuHandler() {
	theView->printEnterOption();
	int option = getMenuOption(0, 9);
	switch (option) {
	case 0:
		theView->printEnd();
		endProgram();
		break;
	case 1:
		changeName();
		break;
	case 2:
		changeNIF();
		break;
	case 3:
		changeStreet();
		break;
	case 4:
		changeCountry();
		break;
	case 5:
		changeCity();
		break;
	case 6:
		changeCounty();
		break;
	case 7:
		changeDoorNumber();
		break;
	case 8:
		changeLatitude();
		break;
	case 9:
		changeLongitude();
		break;
	case 10:
		newUserMenu();
		break;
	default:
		newUserMenu();
		break;
	}
}

int ChangeUserMenuController::getMenuOption(const int lowerBound,
		const int upperBound) {
	int option;
	bool flag = false;
	while (!flag) {
		getInfo(option);
		if (!(flag = v->validateBound(option, lowerBound, upperBound))) {
			theView->printWrongOption();
		}
	}
	return option;
}

void ChangeUserMenuController::changeName() {
	theView->printEnterNewName();
	string name = getName();
	user->setName(name);

}

void ChangeUserMenuController::changeNIF() {
	theView->printEnterNewNIF();
	unsigned int nif = getNIF();
	user->setNif(nif);

}

void ChangeUserMenuController::changeStreet() {
	theView->printEnterNewStreet();
	string street = getStreet();
	Address a = user->getAddress();
	a.setStreet(street);
	user->setAddress(a);
}

void ChangeUserMenuController::changeCountry() {
	theView->printEnterNewCountry();
	string country = getCountry();
	Address a = user->getAddress();
	a.setCountry(country);
	user->setAddress(a);
}

void ChangeUserMenuController::changeCity() {
	theView->printEnterNewCity();
	string city = getCity();
	Address a = user->getAddress();
	a.setCity(city);
	user->setAddress(a);
}

void ChangeUserMenuController::changeCounty() {
	theView->printEnterNewCounty();
	string county = getCounty();
	Address a = user->getAddress();
	a.setCounty(county);
	user->setAddress(a);
}

void ChangeUserMenuController::changeDoorNumber() {
	theView->printEnterNewDoorNumber();
	unsigned int doorNumber = getDoorNumber();
	Address a = user->getAddress();
	a.setDoor_number(doorNumber);
	user->setAddress(a);
}

void ChangeUserMenuController::changeLatitude() {
	theView->printEnterNewLatitude();
	double latitude = getLatitude();
	Address a = user->getAddress();
	GPS gps = a.getCoordinates();
	gps.setLatitude(latitude);
	user->setAddress(a);
}

void ChangeUserMenuController::changeLongitude() {
	theView->printEnterNewLongitude();
	double longitude = getLongitude();
	Address a = user->getAddress();
	GPS gps = a.getCoordinates();
	gps.setLongitude(longitude);
	user->setAddress(a);
}

string ChangeUserMenuController::getName() {
	string name;
	theView->printEnterNewName();
	getInfo(name);
	return name;
}
unsigned int ChangeUserMenuController::getNIF() {
	unsigned int nif;
	theView->printEnterNewNIF();
	bool flag = false;
	while (!flag) {
		getInfo(nif);
		if (!(flag = v->validateNIFFormat(std::to_string(nif)))) {
			theView->printWrongNIF();
		}
	}
	return nif;
}
string ChangeUserMenuController::getStreet() {
	string street;
	theView->printEnterNewStreet();
	getInfo(street);
	return street;
}
string ChangeUserMenuController::getCountry() {
	string country;
	theView->printEnterNewCountry();
	getInfo(country);
	return country;
}
string ChangeUserMenuController::getCity() {
	string city;
	theView->printEnterNewCity();
	getInfo(city);
	return city;
}
string ChangeUserMenuController::getCounty() {
	string county;
	theView->printEnterNewCounty();
	getInfo(county);
	return county;
}
unsigned int ChangeUserMenuController::getDoorNumber() {
	unsigned int doorNumber;
	theView->printEnterNewDoorNumber();
	getInfo(doorNumber);
	return doorNumber;
}

double ChangeUserMenuController::getLatitude() {
	double latitude;
	theView->printEnterNewLatitude();
	bool flag = false;
	while (!flag) {
		getInfo(latitude);
		if (!(flag = v->validateLatitudeFormat(std::to_string(latitude)))) {
			theView->printWrongLatitude();
		}
	}
	return latitude;

}
double ChangeUserMenuController::getLongitude() {
	double longitude;
	theView->printEnterNewLongitude();
	bool flag = false;
	while (!flag) {
		getInfo(longitude);
		if (!(flag = v->validateLongitudeFormat(std::to_string(longitude)))) {
			theView->printWrongLongitude();
		}
	}
	return longitude;
}

bool ChangeUserMenuController::getKeepContinuing() {
	int keepContinuing;
	theView->printEnterContinue();
	bool flag = false;
	while (!flag) {
		getInfo(keepContinuing);
		if (!(flag = v->validateBound(keepContinuing, 0, 1))) {
			theView->printWrongOption();
		}
	}
	return keepContinuing == 1;
}

void ChangeUserMenuController::endProgram() {
	exit(0);
}

void ChangeUserMenuController::newUserMenu() {
	UserMenuController *userMenuController = new UserMenuController(user,company);
	userMenuController->menu();
}
