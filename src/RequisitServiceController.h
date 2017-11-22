/*
 * RequisitServiceController.h
 *
 *  Created on: 13/11/2017
 *      Author: jotaa
 */

#ifndef SRC_CONTROLLER_SRC_REQUISITSERVICECONTROLLER_H_
#define SRC_CONTROLLER_SRC_REQUISITSERVICECONTROLLER_H_

#include "RequisitServiceView.h"
#include "ListServicesController.h"
#include "Company.h"
#include "ServiceMenuController.h"

class RequisitServiceController {
private:
	RequisitServiceView *theView;
	Validation *v;
	Utilities *u;
	Client *user;
	Services *service;
	Company *company;

	long volume;
	unsigned int storageDays;
	double latitudeOrigin, longitudeOrigin, latitudeDestination,
			longitudeDestination;
	unsigned int doorNumberOrigin, doorNumberDestination;
	string streetOrigin, countryOrigin, cityOrigin, countyOrigin,
			streetDestination, countryDestination, cityDestination,
			countyDestination;
	unsigned int packagingInitialDay, packagingInitialMonth,
			packagingInitialYear, packagingInitialHour, packagingInitialMinute;

	void getServiceInformation();
	void getAddressInformation(string &street, string &country, string &city,
			string &county, unsigned int &doorNumber, double &latitude,
			double &longitude);

	void getPackagingInitialDate();
	void getPackagingInitialHour();
	void createService();
	void payServiceEOM();

	string getStreet();
	string getCountry();
	string getCity();
	string getCounty();
	unsigned int getDoorNumber();
	double getLatitude();
	double getLongitude();

	long getVolume();
	unsigned int getStorageDays();

	void payAtEOMHandler();
	int getMenuOption(const int lowerBound, const int upperBound);
	void addService();
	void addToEOM();

	void endProgram();

	void newServiceMenu();
	void newPayServiceMenu();

	template<typename T> void getInfo(T &info);

public:
	RequisitServiceController(Client *client, Company *company);
	virtual ~RequisitServiceController();
	void menu();
};

template<typename T>
void RequisitServiceController::getInfo(T &info) {
	if (!theView->getInfo(info)) { //ctrlz, fim do ficheiro
		theView->printEnd();
		newServiceMenu();
	}
}

#endif /* SRC_CONTROLLER_SRC_REQUISITSERVICECONTROLLER_H_ */
