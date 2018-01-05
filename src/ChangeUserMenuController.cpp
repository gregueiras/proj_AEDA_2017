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
	this->client = client;
}

ChangeUserMenuController::~ChangeUserMenuController() {
}

void ChangeUserMenuController::menu() {
	int option;
	do {
		theView->printUserInfo(client->getInfoDisp());
		theView->printChangeUserMenu();
		theView->printEnterOption();
		option = getMenuOption(0, 11);
		switch (option) {
		case 0:
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
		case 11:
			newUserMenu();
			break;
		}
	} while (option != 0);
}

int ChangeUserMenuController::getMenuOption(const int lowerBound,
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

void ChangeUserMenuController::changeName() {
	string name = getName();
	if (name != "0") {
		client->setName(name);
	}
}

void ChangeUserMenuController::changeNIF() {
	unsigned int nif = getNIF();
	if (nif != 0) {
		client->setNif(nif);
	}
}

void ChangeUserMenuController::changeStreet() {
	string street = getStreet();
	if (street != "0") {
		Address a = client->getAddress();
		a.setStreet(street);
		client->setAddress(a);
	}
}

void ChangeUserMenuController::changeCountry() {
	string country = getCountry();
	if (country != "0") {
		Address a = client->getAddress();
		a.setCountry(country);
		client->setAddress(a);
	}
}

void ChangeUserMenuController::changeCity() {
	string city = getCity();
	if (city != "0") {
		Address a = client->getAddress();
		a.setCity(city);
		client->setAddress(a);
	}
}

void ChangeUserMenuController::changeCounty() {
	string county = getCounty();
	if (county != "0") {
		Address a = client->getAddress();
		a.setCounty(county);
		client->setAddress(a);
	}
}

void ChangeUserMenuController::changeDoorNumber() {
	unsigned int doorNumber = getDoorNumber();
	if (doorNumber != 0) {
		Address a = client->getAddress();
		a.setDoor_number(doorNumber);
		client->setAddress(a);
	}
}

void ChangeUserMenuController::changeLatitude() {
	double latitude = getLatitude();
	if (latitude != 0) {
		Address a = client->getAddress();
		GPS gps = a.getCoordinates();
		gps.setLatitude(latitude);
		client->setAddress(a);
	}
}

void ChangeUserMenuController::changeLongitude() {
	double longitude = getLongitude();
	if (longitude != 0) {
		Address a = client->getAddress();
		GPS gps = a.getCoordinates();
		gps.setLongitude(longitude);
		client->setAddress(a);
	}
}

void ChangeUserMenuController::changePassword() {
	string password = getPassword();
	if (password != "0") {
		client->setPass(password);
	}
}

string ChangeUserMenuController::getName() {
	string name;
	theView->printEnterNewName();
	theView->getInfo(name);
	return name;
}

unsigned int ChangeUserMenuController::getNIF() {
	unsigned int nif;
	bool flag1, flag2;
	do {
		theView->printEnterNewNIF();
		flag1 = theView->getInfo(nif);
		if (flag1 == true && nif == 0) {
			return nif;
		}
		flag2 = v->validateNIFFormat(std::to_string(nif));
		if (flag1 == false || flag2 == false) {
			theView->printWrongNIF();
		}
	} while (flag1 == false || flag2 == false);
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
	unsigned int doorNumber = 0;
	bool flag1;
	do {
		theView->printEnterNewDoorNumber();
		flag1 = theView->getInfo(doorNumber);
		if (flag1 == true && doorNumber == 0) {
			return doorNumber;
		}
	} while (flag1 == false);
	return doorNumber;
}

double ChangeUserMenuController::getLatitude() {
	double latitude;
	bool flag1, flag2;
	do {
		theView->printEnterNewLatitude();
		flag1 = theView->getInfo(latitude);
		if (flag1 == true && latitude == 0) {
			return latitude;
		}
		flag2 = v->validateLatitudeFormat(std::to_string(latitude));
		if (flag1 == false || flag2 == false) {
			theView->printWrongLatitude();
		}
	} while (flag1 == false || flag2 == false);
	return latitude;
}
double ChangeUserMenuController::getLongitude() {
	double longitude;
	bool flag1, flag2;
	do {
		theView->printEnterNewLongitude();
		flag1 = theView->getInfo(longitude);
		if (flag1 == true && longitude == 0) {
			return longitude;
		}
		flag2 = v->validateLongitudeFormat(std::to_string(longitude));
		if (flag1 == false || flag2 == false) {
			theView->printWrongLongitude();
		}
	} while (flag1 == false || flag2 == false);
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
	theView->printEnd();
	theView->printShutdown();
	company->writeCompanyToFile();
	company->writeClientsToFile();
	company->writeVehiclesToFile();
	exit(0);
}

void ChangeUserMenuController::newUserMenu() {
	theView->printEnd();
	UserMenuController *userMenuController = new UserMenuController(client,
			company);
	userMenuController->menu();
}
