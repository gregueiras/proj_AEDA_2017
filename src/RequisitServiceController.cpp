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
	user = client;
	u = new Utilities();
	v = new Validation();
	service = NULL;
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
	addService();
	payService();
}

void RequisitServiceController::RequisitServiceController::getServiceInformation() {
	volume = getVolume();
	theView->printOriginAddress();
	getAddressInformation(streetOrigin, countryOrigin, cityOrigin, countyOrigin,
			doorNumberOrigin, latitudeOrigin, longitudeOrigin);

	theView->printDestinationAddress();
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

string RequisitServiceController::getStreet() {
	string street;
	theView->printEnterStreet();
	street = theView->getLine();
	if (street == "0" && !dynamic_cast<Unregistered*>(user)) {
		newServiceMenu();
	}
	return street;
}
string RequisitServiceController::getCountry() {
	string country;
	theView->printEnterCountry();
	country = theView->getLine();
	if (country == "0" && !dynamic_cast<Unregistered*>(user)) {
		newServiceMenu();
	}
	return country;
}
string RequisitServiceController::getCity() {
	string city;
	theView->printEnterCity();
	city = theView->getLine();
	if (city == "0" && !dynamic_cast<Unregistered*>(user)) {
		newServiceMenu();
	}
	return city;
}
string RequisitServiceController::getCounty() {
	string county;
	theView->printEnterCounty();
	county = theView->getLine();
	if (county == "0" && !dynamic_cast<Unregistered*>(user)) {
		newServiceMenu();
	}
	return county;
}

unsigned int RequisitServiceController::getDoorNumber() {
	unsigned int doorNumber;
	theView->printEnterDoorNumber();
	theView->getInfo(doorNumber);
	if (doorNumber == 0 && !dynamic_cast<Unregistered*>(user)) {
		newServiceMenu();
	}
	return doorNumber;
}
double RequisitServiceController::getLatitude() {
	double latitude;
	theView->printEnterLatitude();
	bool flag = false;
	while (!flag) {
		theView->getInfo(latitude);
		if (latitude == 0 && !dynamic_cast<Unregistered*>(user)) {
			newServiceMenu();
		}
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
		theView->getInfo(longitude);
		if (longitude == 0 && !dynamic_cast<Unregistered*>(user)) {
			newServiceMenu();
		}
		if (!(flag = v->validateLongitudeFormat(std::to_string(longitude)))) {
			theView->printWrongLongitude();
		}
	}
	return longitude;
}

void RequisitServiceController::getPackagingInitialDate() {
	theView->printEnterPackagingInitialDate();
	string date;
	do {
		theView->getInfo(packagingInitialDay);
		if (packagingInitialDay == 0 && !dynamic_cast<Unregistered*>(user)) {
			newServiceMenu();
		}
		theView->getInfo(packagingInitialMonth);
		if (packagingInitialMonth == 0 && !dynamic_cast<Unregistered*>(user)) {
			newServiceMenu();
		}
		theView->getInfo(packagingInitialYear);
		if (packagingInitialYear == 0 && !dynamic_cast<Unregistered*>(user)) {
			newServiceMenu();
		}
		date = to_string(packagingInitialDay) + "/"
				+ to_string(packagingInitialDay) + "/"
				+ to_string(packagingInitialDay);
	} while (!v->validateDateFormat(date));
}

void RequisitServiceController::getPackagingInitialHour() {
	theView->printEnterPackagingInitialTime();
	theView->getInfo(packagingInitialHour);
	if (packagingInitialHour == 0 && !dynamic_cast<Unregistered*>(user)) {
		newServiceMenu();
	}
	theView->getInfo(packagingInitialMinute);
	if (packagingInitialMinute == 0 && !dynamic_cast<Unregistered*>(user)) {
		newServiceMenu();
	}
}

unsigned int RequisitServiceController::getStorageDays() {
	unsigned int storageDays;
	theView->printEnterStorageTime();
	theView->getInfo(storageDays);
	if (storageDays == 0 && !dynamic_cast<Unregistered*>(user)) {
		newServiceMenu();
	}
	return storageDays;
}

long RequisitServiceController::getVolume() {
	unsigned long volume;
	theView->printEnterVolume();
	theView->getInfo(volume);
	if (volume == 0 && !dynamic_cast<Unregistered*>(user)) {
		newServiceMenu();
	}
	return volume;
}
void RequisitServiceController::createService() {
	Address adressOrigin(streetOrigin, countryOrigin, cityOrigin, countyOrigin,
			doorNumberOrigin);
	if (latitudeOrigin != 0)
		adressOrigin.setCoordinates(GPS(latitudeOrigin, longitudeOrigin));

	Address addressDestination(streetDestination, countryDestination,
			cityDestination, countyDestination, doorNumberDestination);
	if (latitudeDestination != 0)
		addressDestination.setCoordinates(
				GPS(latitudeDestination, longitudeDestination));

	Date packagingInitialDate(packagingInitialDay, packagingInitialMonth,
			packagingInitialYear);
	Hour packagingInitialTime(packagingInitialHour, packagingInitialMinute);

	service = new Services(adressOrigin, volume, addressDestination,
			packagingInitialTime, packagingInitialDate, storageDays);
}

void RequisitServiceController::payService() {
	if (dynamic_cast<Business*>(user)) {
		theView->printAskAddToEOM();
		payAtEOMHandler();
	}
	newPayServiceMenu();
}

void RequisitServiceController::payAtEOMHandler() {
	theView->printEnterOption();
	int option = getMenuOption(1, 2);
	switch (option) {
	case 1:
		addToEOM();
		newServiceMenu();
		break;
	case 2:
	default:
		break;
	}
}

void RequisitServiceController::addToEOM() {
	Hour *h = new Hour(23, 59);
	EOMPayment *eomPayment = new EOMPayment(service->getPrice(), true,
			u->lastDayofMonth(company->getCurrentDate().getMonth(),
					company->getCurrentDate().getYear()), *h);
	user->addPayment(eomPayment);
}

int RequisitServiceController::getMenuOption(const int lowerBound,
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

void RequisitServiceController::addService() {
	user->addServices(service);
	company->addService(service, user->getId());
}

void RequisitServiceController::newEnterController() {
	EnterController *enterController = new EnterController(company);
	enterController->menu();
}

void RequisitServiceController::newServiceMenu() {
	ServiceMenuController *serviceMenuController = new ServiceMenuController(
			user, company);
	serviceMenuController->menu();
}

void RequisitServiceController::newPayServiceMenu() {
	PayServiceController *payServiceController = new PayServiceController(user,
			service->getId(), company);
	payServiceController->menu();
}

void RequisitServiceController::endProgram() {
	exit(0);
}
