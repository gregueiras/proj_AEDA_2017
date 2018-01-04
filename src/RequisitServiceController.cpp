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
	bool flag1;
	do {
		theView->printEnterDoorNumber();
		flag1 = theView->getInfo(doorNumber);
		if (flag1 == true && doorNumber == 0
				&& !dynamic_cast<Unregistered*>(user)) {
			newServiceMenu();
		}
	} while (flag1 == false);
	return doorNumber;
}

double RequisitServiceController::getLatitude() {
	unsigned int latitude;
	bool flag1, flag2;
	do {
		theView->printEnterLatitude();
		flag1 = theView->getInfo(latitude);
		if (flag1 == true && latitude == 0
				&& !dynamic_cast<Unregistered*>(user)) {
			newServiceMenu();
		}
		flag2 = v->validateLatitudeFormat(std::to_string(latitude));
		if (flag1 == false || flag2 == false) {
			theView->printWrongLatitude();
		}
	} while (flag1 == false || flag2 == false);
	return latitude;

}
double RequisitServiceController::getLongitude() {
	double longitude;
	bool flag1, flag2;
	do {
		theView->printEnterLongitude();
		flag1 = theView->getInfo(longitude);
		if (flag1 == true && longitude == 0
				&& !dynamic_cast<Unregistered*>(user)) {
			newEnterController();
		}
		flag2 = v->validateLongitudeFormat(std::to_string(longitude));
		if (flag1 == false || flag2 == false) {
			theView->printWrongLongitude();
		}
	} while (flag1 == false || flag2 == false);
	return longitude;
}

void RequisitServiceController::getPackagingInitialDate() {
	theView->printEnterPackagingInitialDate();
	string date;
	bool flag;
	do {
		do {
			theView->printEnterPackagingInitialDay();
			flag = theView->getInfo(packagingInitialDay);
		} while (flag == false);
		if (packagingInitialDay == 0 && !dynamic_cast<Unregistered*>(user)) {
			newServiceMenu();
		}

		do {
			theView->printEnterPackagingInitialMonth();
			flag = theView->getInfo(packagingInitialMonth);
		} while (flag == false);
		if (packagingInitialMonth == 0 && !dynamic_cast<Unregistered*>(user)) {
			newServiceMenu();
		}

		do {
			theView->printEnterMaintenanceYear();
			flag = theView->getInfo(packagingInitialYear);
		} while (flag == false);
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
	string time;
	bool flag;
	do {
		do {
			theView->printEnterPackagingInitialHour();
			flag = theView->getInfo(packagingInitialHour);
		} while (flag == false);

		do {
			theView->printEnterPackagingInitialMinute();
			flag = theView->getInfo(packagingInitialMinute);
		} while (flag == false);

		time = to_string(packagingInitialHour) + ":"
				+ to_string(packagingInitialMinute);
	} while (!v->validateHourFormat(time));
}

unsigned int RequisitServiceController::getStorageDays() {
	unsigned int storageDays;
	bool flag1;
	do {
		theView->printEnterStorageTime();
		flag1 = theView->getInfo(storageDays);
		if (flag1 == true && storageDays == 0
				&& !dynamic_cast<Unregistered*>(user)) {
			newServiceMenu();
		}
	} while (flag1 == false);
	return storageDays;
}

long RequisitServiceController::getVolume() {
	unsigned long volume;
	bool flag1;
	do {
		theView->printEnterVolume();
		flag1 = theView->getInfo(volume);
		if (flag1 == true && volume == 0
				&& !dynamic_cast<Unregistered*>(user)) {
			newServiceMenu();
		}
	} while (flag1 == false);
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
	Hour vehicleExpectedTime(vehicleExpectedHour, vehicleExpectedMinute);
	service = new Services(adressOrigin, volume, addressDestination,
			packagingInitialTime, packagingInitialDate, vehicleExpectedTime,
			storageDays);
	service->applyDiscount(company->getDiscount());

}

void RequisitServiceController::payService() {
	if (dynamic_cast<Business*>(user)) {
		theView->printAskAddToEOM();
		payAtEOMHandler();
	}
	newPayServiceMenu();
}

void RequisitServiceController::payAtEOMHandler() {
	int option;
	do {
		theView->printEnterOption();
		option = getMenuOption(1, 2);
		switch (option) {
		case 1:
			addToEOM();
			newServiceMenu();
			break;
		}
	} while (option == -1);
}

int RequisitServiceController::getMenuOption(const int lowerBound,
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
void RequisitServiceController::addToEOM() {
	Hour *h = new Hour(23, 59);
	EOMPayment *eomPayment = new EOMPayment(service->getPrice(),
			service->getId(), true,
			u->lastDayofMonth(company->getCurrentDate().getMonth(),
					company->getCurrentDate().getYear()), *h);
	user->addPayment(eomPayment);
}

void RequisitServiceController::addService() {
	if (company->isAnyVehicleAvailable()) {
		company->addService(service, user->getId());
		company->assignVehicle(service);
	} else {
		company->addServiceToNext_Services(service);
	}
	user->addServices(service);
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

}
