/*
 * ChangeMenuController.cpp

 *  Created on: 08/11/2017
 *      Author: jotaa
 */

#include "ChangeUserMenuController.h"

ChangeUserMenuController::ChangeUserMenuController(Client *client,
		Company *company) {
	this->theView = new ChangeUserMenuView;
	this->company = company;
	u = new Utilities();
	v = new Validation();
	user = client;
}

ChangeUserMenuController::~ChangeUserMenuController() {
}

void ChangeUserMenuController::menu() {
	menuHandler();
	newUserMenu();
}

void ChangeUserMenuController::menuHandler() {
	int option;
	do {
		theView->printUserInfo(user->getInfoDisp());
		theView->printChangeUserMenu();
		theView->printEnterOption();
		option = getMenuOption(0, 11);
		switch (option) {
		case 0:
			theView->printShutdown();
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
			changePassword();
			break;
		default:
			newUserMenu();
			break;
		}
	} while (option != 11);
}

int ChangeUserMenuController::getMenuOption(const int lowerBound,
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

void ChangeUserMenuController::changeName() {
	string name = getName();
	user->setName(name);
}

void ChangeUserMenuController::changeNIF() {
	unsigned int nif = getNIF();
	user->setNif(nif);

}

void ChangeUserMenuController::changeStreet() {
	string street = getStreet();
	Address a = user->getAddress();
	a.setStreet(street);
	user->setAddress(a);
}

void ChangeUserMenuController::changeCountry() {
	string country = getCountry();
	Address a = user->getAddress();
	a.setCountry(country);
	user->setAddress(a);
}

void ChangeUserMenuController::changeCity() {
	string city = getCity();
	Address a = user->getAddress();
	a.setCity(city);
	user->setAddress(a);
}

void ChangeUserMenuController::changeCounty() {
	string county = getCounty();
	Address a = user->getAddress();
	a.setCounty(county);
	user->setAddress(a);
}

void ChangeUserMenuController::changeDoorNumber() {
	unsigned int doorNumber = getDoorNumber();
	Address a = user->getAddress();
	a.setDoor_number(doorNumber);
	user->setAddress(a);
}

void ChangeUserMenuController::changeLatitude() {
	double latitude = getLatitude();
	Address a = user->getAddress();
	GPS gps = a.getCoordinates();
	gps.setLatitude(latitude);
	user->setAddress(a);
}

void ChangeUserMenuController::changeLongitude() {
	double longitude = getLongitude();
	Address a = user->getAddress();
	GPS gps = a.getCoordinates();
	gps.setLongitude(longitude);
	user->setAddress(a);
}

void ChangeUserMenuController::changePassword() {
	string password = getPassword();
	user->setPass(password);
}

string ChangeUserMenuController::getName() {
	string name;
	theView->printEnterNewName();
	theView->getInfo(name);
	return name;
}

unsigned int ChangeUserMenuController::getNIF() {
	unsigned int nif;
	theView->printEnterNewNIF();
	bool flag = false;
	while (!flag) {
		theView->getInfo(nif);
		if (!(flag = v->validateNIFFormat(std::to_string(nif)))) {
			theView->printWrongNIF();
		}
	}
	return nif;
}

string ChangeUserMenuController::getStreet() {
	string street;
	theView->printEnterNewStreet();
	theView->getInfo(street);
	return street;
}

string ChangeUserMenuController::getCountry() {
	string country;
	theView->printEnterNewCountry();
	theView->getInfo(country);
	return country;
}

string ChangeUserMenuController::getCity() {
	string city;
	theView->printEnterNewCity();
	theView->getInfo(city);
	return city;
}

string ChangeUserMenuController::getCounty() {
	string county;
	theView->printEnterNewCounty();
	theView->getInfo(county);
	return county;
}

unsigned int ChangeUserMenuController::getDoorNumber() {
	unsigned int doorNumber;
	theView->printEnterNewDoorNumber();
	theView->getInfo(doorNumber);
	return doorNumber;
}

double ChangeUserMenuController::getLatitude() {
	double latitude;
	theView->printEnterNewLatitude();
	bool flag = false;
	while (!flag) {
		theView->getInfo(latitude);
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
		theView->getInfo(longitude);
		if (!(flag = v->validateLongitudeFormat(std::to_string(longitude)))) {
			theView->printWrongLongitude();
		}
	}
	return longitude;
}

string ChangeUserMenuController::getPassword() {
	string pass;
	theView->printEnterNewPassword();
	theView->getInfo(pass);
	return pass;
}

//void ChangeUserMenuController::changeInformation() {
//	company->setclient(user);
//}

void ChangeUserMenuController::endProgram() {
}

void ChangeUserMenuController::newUserMenu() {
	UserMenuController *userMenuController = new UserMenuController(user,
			company);
	userMenuController->menu();
}
