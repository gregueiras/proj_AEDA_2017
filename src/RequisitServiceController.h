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
#include "Unregistered.h"

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

	/**
	 * user interface method to read service information
	 */
	void getServiceInformation();

	/**
	 * user interface method that get the param respective informations
	 * @param street string with street info
	 * @param country string with country info
	 * @param city string with city info
	 * @param county string with county info
	 * @param doorNumber string with doorNumber info
	 * @param latitude string with latitude info
	 * @param longitude string with longitude info
	 */
	void getAddressInformation(string &street, string &country, string &city,
			string &county, unsigned int &doorNumber, double &latitude,
			double &longitude);

	/**
	 * user interaction method to read packaging initial date infomation
	 */
	void getPackagingInitialDate();

	/**
	 * user interaction method to read packaging initial hour information
	 */
	void getPackagingInitialHour();

	/**
	 * method to create instance of a new service
	 */
	void createService();

	/**
	 * user interaction method to pay the newly created service
	 */
	void payService();

	/**
	 * user interaction method to read street infomation
	 */
	string getStreet();

	/**
	 * user interaction method to read country infomation
	 */
	string getCountry();

	/**
	 * user interaction method to read city infomation
	 */
	string getCity();

	/**
	 * user interaction method to read county infomation
	 */
	string getCounty();

	/**
	 * user interaction method to read doorNumber infomation
	 */
	unsigned int getDoorNumber();

	/**
	 * user interaction method to read latitude infomation
	 */
	double getLatitude();

	/**
	 * user interaction method to read longitude infomation
	 */
	double getLongitude();

	/**
	 * user interaction method to read volume infomation
	 */
	long getVolume();

	/**
	 * user interaction method to read storage days infomation
	 */
	unsigned int getStorageDays();

	/**
	 * user interaction method to decide whether or not to pay at end of the month
	 */
	void payAtEOMHandler();

	/**
	 * read the menu option from the keyboard the value of arrival_date
	 * Date of arrival
	 * @param lowerBound lower bound of the menu option
	 * @param upperBound upper bound of the menu option
	 */
	int getMenuOption(const int lowerBound, const int upperBound);

	/**
	 * Adds service to user
	 */
	void addService();

	/**
	 * Signs the service as an End of the Month to pay service
	 */
	void addToEOM();

	/**
	 * ends the program
	 */
	void endProgram();

	/**
	 * opens new enter menu
	 */
	void newEnterController();

	/**
	 * opens new service menu
	 */
	void newServiceMenu();

	/**
	 * opens new pay service menu
	 */
	void newPayServiceMenu();

public:
	/**
	 * Contructor that initalizes all variables
	 * @param client log in user
	 * @param company pointer to the company object
	 */
	RequisitServiceController(Client *client, Company *company);

	/**
	 * destructor
	 */
	virtual ~RequisitServiceController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};

#endif /* SRC_CONTROLLER_SRC_REQUISITSERVICECONTROLLER_H_ */
