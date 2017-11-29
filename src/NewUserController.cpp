/*
 * NewUserController.cpp
 *
 *  Created on: 04/11/2017
 *      Author: jotaa
 */

#include "NewUserController.h"

NewUserController::NewUserController(Company *company) {
	this->theView = new NewUserView;
	v = new Validation();
	u = new Utilities();
	this->company = company;
	user = NULL;
	userType = 0, nif = 0, doorNumber = 0;
	latitude = 0, longitude = 0;
	name = "", street = "", country = "", city = "", county = "", password = "";
}

NewUserController::~NewUserController() {
}

void NewUserController::menu() {
	theView->printNewUserMenu();
	getUserInformation();
	createUser();
}

void NewUserController::getUserInformation() {
	userType = getUserType();
	name = getName();
	nif = getNIF();
	street = getStreet();
	country = getCountry();
	city = getCity();
	county = getCounty();
	doorNumber = getDoorNumber();
	if (!u->isCapitalDistrito(city)) {
		latitude = getLatitude();
		longitude = getLongitude();
	}
	if (!(userType == client_type_unregistered)) {
		password = getPassword();
	}
}

unsigned int NewUserController::getUserType() {
	int userType;
	theView->printEnterUserType();
	bool flag = false;
	while (!flag) {
		theView->getInfo(userType);
		if (userType == 0) {
			newEnterController();
		}
		flag = v->validateBound(userType, client_type_personal,
				client_type_unregistered);
		if (!flag) {
			theView->printWrongUserType();
		}
	}
	return userType;
}

string NewUserController::getName() {
	string name;
	theView->printEnterName();
	name = theView->readLine();
	if (name == "0") {
		newEnterController();
	}
	return name;
}
unsigned int NewUserController::getNIF() {
	unsigned int nif;
	theView->printEnterNIF();
	bool flag = false;
	while (!flag) {
		theView->getInfo(nif);
		if (nif == 0) {
			newEnterController();
		}
		if (!(flag = v->validateNIFFormat(std::to_string(nif)))) {
			theView->printWrongNIF();
		}
	}
	return nif;

}
string NewUserController::getStreet() {
	string street;
	theView->printEnterStreet();
	street = theView->readLine();
	if (street == "0") {
		newEnterController();
	}

	return street;
}
string NewUserController::getCountry() {
	string country;
	theView->printEnterCountry();
	country = theView->readLine();
	if (country == "0") {
		newEnterController();
	}

	return country;
}
string NewUserController::getCity() {
	string city;
	theView->printEnterCity();
	city = theView->readLine();
	if (city == "0") {
		newEnterController();
	}

	return city;
}
string NewUserController::getCounty() {
	string county;
	theView->printEnterCounty();
	county = theView->readLine();
	if (county == "0") {
		newEnterController();
	}

	return county;
}
unsigned int NewUserController::getDoorNumber() {
	unsigned int doorNumber;
	theView->printEnterDoorNumber();
	theView->getInfo(doorNumber);
	if (doorNumber == 0) {
		newEnterController();
	}

	return doorNumber;
}
double NewUserController::getLatitude() {
	double latitude;
	theView->printEnterLatitude();
	bool flag = false;
	while (!flag) {
		theView->getInfo(latitude);
		if (latitude == 0) {
			newEnterController();
		}
		if (!(flag = v->validateLatitudeFormat(std::to_string(latitude)))) {
			theView->printWrongLatitude();
		}
	}
	return latitude;

}
double NewUserController::getLongitude() {
	double longitude;
	theView->printEnterLongitude();
	bool flag = false;
	while (!flag) {
		theView->getInfo(longitude);
		if (longitude == 0) {
			newEnterController();
		}
		if (!(flag = v->validateLongitudeFormat(std::to_string(longitude)))) {
			theView->printWrongLongitude();
		}
	}
	return longitude;
}

string NewUserController::getPassword() {
	string password;
	theView->printEnterPassword();
	password = theView->readLine();
	if (password == "0") {
		newEnterController();
	}
	return password;
}

void NewUserController::createUser() {
	Address address;
	if (latitude != 0)
		address = Address(street, country, city, county, doorNumber, latitude,
			longitude);
	else
		address = Address(street, country, city, county, doorNumber);

	if (userType == client_type_personal) {
		user = new Personal(name, address, nif, password);
	} else if (userType == client_type_business) {
		user = new Business(name, address, nif, password);
	} else {
		user = new Unregistered(name, address, nif);
	}

	company->addClient(user);
	if (userType == client_type_unregistered) {
		newRequisitServiceController();
	} else {
		theView->printUserID(user->getId());
		newEnterController();
	}
}

void NewUserController::newEnterController() {
	EnterController *enterController = new EnterController(company);
	enterController->menu();
}

void NewUserController::newRequisitServiceController() {
	RequisitServiceController *enterController = new RequisitServiceController(
			user, company);
	enterController->menu();
}

void NewUserController::endProgram() {
}

