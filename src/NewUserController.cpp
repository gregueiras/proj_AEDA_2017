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
	userType = 0;
	nif = 0;
	doorNumber = 0;
	latitude = 0;
	longitude = 0;
	name = "";
	street = "";
	country = "";
	city = "";
	county = "";
	password = "";
}

NewUserController::~NewUserController() {
}

void NewUserController::menu() {
	getUserInformation();
	createUser();
}

void NewUserController::getUserInformation() {
	theView->printNewUserMenu();
	getUserType();
	getName();
	getNIF();
	getStreet();
	getCountry();
	getCity();
	getCounty();
	getDoorNumber();
	if (!u->isCapitalDistrito(city)) {
		getLatitude();
		getLongitude();
	}
	if (!(userType == client_type_unregistered)) {
		password = getPassword();
	}
}

void NewUserController::getUserType() {
	bool flag1, flag2;
	do {
		theView->printEnterUserType();
		flag1 = theView->getInfo(userType);
		if (flag1 == true && userType == 0) {
			newEnterController();
		}
		flag2 = v->validateBound(userType, client_type_personal,
				client_type_unregistered);
		if (flag1 == false || flag2 == false) {
			theView->printWrongUserType();
		}
	} while (flag1 == false || flag2 == false);
}

void NewUserController::getName() {
	theView->printEnterName();
	name = theView->readLine();
	if (name == "0") {
		newEnterController();
	}
}

void NewUserController::getNIF() {
	bool flag1, flag2;
	do {
		theView->printEnterNIF();
		flag1 = theView->getInfo(nif);
		if (flag1 == true && nif == 0) {
			newEnterController();
		}
		flag2 = v->validateNIFFormat(std::to_string(nif));
		if (flag1 == false || flag2 == false) {
			theView->printWrongNIF();
		}
	} while (flag1 == false || flag2 == false);
}

void NewUserController::getStreet() {
	theView->printEnterStreet();
	street = theView->readLine();
	if (street == "0") {
		newEnterController();
	}
}
void NewUserController::getCountry() {
	theView->printEnterCountry();
	country = theView->readLine();
	if (country == "0") {
		newEnterController();
	}
}
void NewUserController::getCity() {
	theView->printEnterCity();
	city = theView->readLine();
	if (city == "0") {
		newEnterController();
	}
}
void NewUserController::getCounty() {
	theView->printEnterCounty();
	county = theView->readLine();
	if (county == "0") {
		newEnterController();
	}
}
void NewUserController::getDoorNumber() {
	bool flag1;
	do {
		theView->printEnterDoorNumber();
		flag1 = theView->getInfo(doorNumber);
		if (flag1 == true && doorNumber == 0) {
			newEnterController();
		}
	} while (flag1 == false);
}

void NewUserController::getLatitude() {
	bool flag1, flag2;
	do {
		theView->printEnterLatitude();
		flag1 = theView->getInfo(latitude);
		if (flag1 == true && latitude == 0) {
			newEnterController();
		}
		flag2 = v->validateLatitudeFormat(std::to_string(latitude));
		if (flag1 == false || flag2 == false) {
			theView->printWrongLatitude();
		}
	} while (flag1 == false || flag2 == false);
}

void NewUserController::getLongitude() {
	bool flag1, flag2;
	do {
		theView->printEnterLongitude();
		flag1 = theView->getInfo(longitude);
		if (flag1 == true && longitude == 0) {
			newEnterController();
		}
		flag2 = v->validateLongitudeFormat(std::to_string(longitude));
		if (flag1 == false || flag2 == false) {
			theView->printWrongLongitude();
		}
	} while (flag1 == false || flag2 == false);
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

