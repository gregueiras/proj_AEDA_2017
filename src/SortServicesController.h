/*
 * SortServicesController.h
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#ifndef SRC_CONTROLLER_HEADERS_SORTSERVICESCONTROLLER_H_
#define SRC_CONTROLLER_HEADERS_SORTSERVICESCONTROLLER_H_

#include "SortServicesView.h"
#include "ServiceMenuController.h"
#include "Company.h"

class SortServicesController {
private:
	SortServicesView *theView;
	Validation *v;
	Utilities *u;
	Client *user;
	vector<Services *> vectorToBeSorted;
	Company *company;

	bool sortedByID;
	bool sortedByDate;
	bool sortedByVolume;
	bool sortedByDistance;
	bool sortedByPrice;

	/**
	 * user interface method that reads sort option and acts accordingly
	 */
	void sortServicesHandler();

	/**
	 * sorts services by ID
	 */
	void sortByID();

	/**
	 * sorts services by date
	 */
	void sortByDate();

	/**
	 * sorts services by volume
	 */
	void sortbyVolume();

	/**
	 * sorts services by distance
	 */
	void sortByDistance();

	/**
	 * sorts services by price
	 */
	void sortByPrice();

	/**
	 * read the menu option from the keyboard the value of arrival_date
	 * Date of arrival
	 * @param lowerBound lower bound of the menu option
	 * @param upperBound upper bound of the menu option
	 */
	int getMenuOption(const int lowerBound, const int upperBound);

	/**
	 * ends the program
	 */
	void endProgram();

	/**
	 * opens new list services menu
	 */
	void newServiceMenu();
public:
	/**
	 * Contructor that initalizes all variables
	 * @param client log in user
	 * @param company pointer to the company object
	 */
	SortServicesController(Client *client, Company *company);

	/**
	 * destructor
	 */
	virtual ~SortServicesController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};

#endif /* SRC_CONTROLLER_HEADERS_SORTSERVICESCONTROLLER_H_ */
