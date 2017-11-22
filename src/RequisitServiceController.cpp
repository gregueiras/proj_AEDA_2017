/*
 * RequisitServiceController.cpp
 *
 *  Created on: 13/11/2017
 *      Author: jotaa
 */

#include "RequisitServiceController.h"

RequisitServiceController::RequisitServiceController(Client *client,
		Company *company) {
	this->company = company;
	this->theView = new RequisitServiceView;
	u = new Utilities();
	v = new Validation();
	service = NULL;
	user = client;
	volume = 0;
	storageDays = 0;
	latitudeOrigin = 0;
	longitudeOrigin = 0;
	latitudeDestination = 0;
	longitudeDestination = 0;
	doorNumberOrigin = 0;
	doorNumberDestination = 0;
	packagingInitialDay = 0;
	packagingInitialMonth = 0;
	packagingInitialYear = 0;
	packagingInitialHour = 0;
	packagingInitialMinute = 0;
	streetOrigin = "";
	countryOrigin = "";
	cityOrigin = "";
	countyOrigin = "";
	streetDestination = "";
	countryDestination = "";
	cityDestination = "";
	countyDestination = "";
}

RequisitServiceController::~RequisitServiceController() {
	// TODO Auto-generated destructor stub
}

void RequisitServiceController::menu() {
	theView->printInitialMessage();
	getServiceInformation();
	createService();
	payServiceEOM();
	addService();
}

void RequisitServiceController::RequisitServiceController::getServiceInformation() {

	volume = getVolume();
	getAddressInformation(streetOrigin, countryOrigin, cityOrigin, countyOrigin,
			doorNumberOrigin, latitudeOrigin, longitudeOrigin);

	getAddressInformation(streetDestination, countryDestination,
			cityDestination, countyDestination, doorNumberDestination,
			latitudeDestination, longitudeDestination);

	if (dynamic_cast<Business*>(user)) {
		storageDays = getStorageDays();
	}
	getPackagingInitialDate();
	getPackagingInitialHour();
}

void RequisitServiceController::getAddressInformation(string &street,
		string &country, string &city, string &county, unsigned int &doorNumber,
		double &latitude, double &longitude) {
	street = getStreet();
	country = getCountry();
	city = getCity();
	county = getCounty();
	doorNumber = getDoorNumber();
	if (!u->isCapitalDistrito(city)) {
		latitude = getLatitude();
		longitude = getLongitude();
	}
}

void RequisitServiceController::createService() {

		Address adressOrigin(streetOrigin, countryOrigin, cityOrigin, countyOrigin, doorNumberOrigin);
		if (latitudeOrigin != 0)
			adressOrigin.setCoordinates(GPS(latitudeOrigin, longitudeOrigin));


		Address addressDestination(streetDestination, countryDestination, cityDestination, countyDestination, doorNumberDestination);
		if (latitudeDestination != 0)
			addressDestination.setCoordinates(GPS(latitudeDestination, longitudeDestination));

	Date packagingInitialDate(packagingInitialDay, packagingInitialMonth, packagingInitialYear);
	Hour packagingInitialTime(packagingInitialHour, packagingInitialMinute);

	cout << "A1: " << adressOrigin << endl;
	cout << "A2: " << addressDestination << endl;


	service = new Services(adressOrigin, volume, addressDestination,
			packagingInitialTime, packagingInitialDate, storageDays);

	cout << "A3" << endl;
}

string RequisitServiceController::getStreet() {
	string street;
	theView->printEnterStreet();
	getInfo(street);
	cout << street << endl;

	return street;
}
string RequisitServiceController::getCountry() {
	string country;
	theView->printEnterCountry();
	getInfo(country);
	return country;
}
string RequisitServiceController::getCity() {
	string city;
	theView->printEnterCity();
	getInfo(city);
	return city;
}
string RequisitServiceController::getCounty() {
	string county;
	theView->printEnterCounty();
	getInfo(county);
	return county;
}

unsigned int RequisitServiceController::getDoorNumber() {
	unsigned int doorNumber;
	theView->printEnterDoorNumber();
	getInfo(doorNumber);
	return doorNumber;
}
double RequisitServiceController::getLatitude() {
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
double RequisitServiceController::getLongitude() {
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

void RequisitServiceController::getPackagingInitialDate() {
	theView->printEnterPackagingInitialDate();

	getInfo(packagingInitialDay);
	getInfo(packagingInitialMonth);
	getInfo(packagingInitialYear);
	cout << packagingInitialDay << endl; 
	cout << packagingInitialMonth << endl;
	cout << packagingInitialYear << endl;

}

void RequisitServiceController::getPackagingInitialHour() {
	theView->printEnterPackagingInitialTime();
	getInfo(packagingInitialHour);
	getInfo(packagingInitialMinute);
	cout << packagingInitialHour << endl;
	cout << packagingInitialMinute << endl;
}

unsigned int RequisitServiceController::getStorageDays() {
	unsigned int storageDays;
	theView->printEnterStorageTime();
	getInfo(storageDays);
	return storageDays;
}

long RequisitServiceController::getVolume() {
	unsigned int volume;
	theView->printEnterVolume();
	getInfo(volume);
	return volume;
}

void RequisitServiceController::payServiceEOM() {
	cout << "B1" << endl;
	
	if (dynamic_cast<Business*>(user)) {
		theView->printAddToEOM();
		payAtEOMHandler();
	}

	cout << "B2" << endl;
}

void RequisitServiceController::payAtEOMHandler() {
	theView->printEnterOption();
	int option = getMenuOption(0, 2);
	switch (option) {
	case 0:
		theView->printEnd();
		endProgram();
		break;
	case 1:
		addToEOM();
		break;
	case 2:
		break;
	default:
		break;
	}
}

int RequisitServiceController::getMenuOption(const int lowerBound,
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

void RequisitServiceController::addService() {
	user->addServices(service);
}

void RequisitServiceController::addToEOM() {
//	service->getPrice().addtoEOM(); TODO
	//como e que se faz para saber se foi adicionado para o fim do mes e nao e para pagar ja
}

void RequisitServiceController::newServiceMenu() {
	ServiceMenuController *serviceMenuController = new ServiceMenuController(
			user, company);
	serviceMenuController->menu();
}

void RequisitServiceController::newPayServiceMenu() {
	PayServiceController *payServiceController = new PayServiceController(user, service->getId(), company);
	payServiceController->menu();
}

void RequisitServiceController::endProgram() {
	exit(0);
}
