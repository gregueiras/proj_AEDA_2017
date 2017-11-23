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
}

NewUserController::~NewUserController() {
}

void NewUserController::menu() {
	double latitude, longitude;
	unsigned int userType, nif, doorNumber;
	string name, street, country, city, county;
	string password; 

	theView->printNewUserMenu(); 
	getUserInformation(userType, name, nif, street, country, city, county,
			doorNumber, latitude, longitude, password);
	createUser(userType, name, nif, street, country, city, county, doorNumber,
			latitude, longitude, password);

}

void NewUserController::getUserInformation(unsigned int &userType, string &name,
		unsigned int &nif, string &street, string &country, string &city,
		string &county, unsigned int &doorNumber, double &latitude,
		double &longitude, string &password) {
	userType = getUserType();
	name = getName();
	nif = getNIF();
	street = getStreet();
	country = getCountry();
	city = getCity();
	county = getCounty();
	doorNumber = getDoorNumber();
	latitude = getLatitude();
	longitude = getLongitude();
	password = getPassword(); 
}

unsigned int NewUserController::getUserType() {
	unsigned int userType;
	theView->printEnterUserType();
	bool flag = false;
	while (!flag) {
		getInfo(userType);
		if (!(flag = v->validateBound(userType, client_type_personal,
				client_type_business))) {
			theView->printWrongUserType();
		}
	}
	return userType;
}

string NewUserController::getName() {
	string name;
	theView->printEnterName();
	getInfo(name);
	return name; 
}
unsigned int NewUserController::getNIF() {
	unsigned int nif;
	theView->printEnterNIF();
	bool flag = false;
	while (!flag) {
		getInfo(nif);
		if (!(flag = v->validateNIFFormat(std::to_string(nif)))) {
			theView->printWrongNIF();
		}
	}
	return nif;

}
string NewUserController::getStreet() {
	string street;
	theView->printEnterStreet();
	getInfo(street);
	return street;
}
string NewUserController::getCountry() {
	string country;
	theView->printEnterCountry();
	getInfo(country);
	return country;
}
string NewUserController::getCity() {
	string city;
	theView->printEnterCity();
	getInfo(city);
	return city;
}
string NewUserController::getCounty() {
	string county;
	theView->printEnterCounty();
	getInfo(county);
	return county;
}
unsigned int NewUserController::getDoorNumber() {
	unsigned int doorNumber;
	theView->printEnterDoorNumber();
	getInfo(doorNumber);
	return doorNumber;
}
double NewUserController::getLatitude() {
	double latitude;
	theView->printEnterLatitude();
	bool flag = false;
	while (!flag) {
		getInfo(latitude);
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
		getInfo(longitude);
		if (!(flag = v->validateLongitudeFormat(std::to_string(longitude)))) {
			theView->printWrongLongitude();
		}
	}
	return longitude;
}

string NewUserController::getPassword() {
	string password;
	theView->printEnterPassword();
	getInfo(password);
	return password;
}

void NewUserController::createUser(unsigned int &userType, string &name,
		unsigned int &nif, string &street, string &country, string &city,
		string &county, unsigned int &doorNumber, double &latitude,
		double &longitude, string &password) {
	Client *client;
	Address address(street, country, city, county, doorNumber,
			latitude, longitude);
	if (userType == client_type_personal) {
		client = new Personal(name, address, nif, password);
	} else if (userType == client_type_business) {
		client = new Business(name, address, nif, password);
	}

cout<<client->getId()<<endl;
	company->addClient(client);
	vector<Client*>vec = company->getClients();

	newEnterController();
}

void NewUserController::newEnterController() {
	EnterController *enterController = new EnterController(company); 
	enterController->menu();
}

void NewUserController::endProgram() {
	exit(0);
}

