/*
 * ListServicesController.h
 *
 *  Created on: 13/11/2017
 *      Author: jotaa
 */

#ifndef SRC_CONTROLLER_HEADERS_LISTSERVICESCONTROLLER_H_
#define SRC_CONTROLLER_HEADERS_LISTSERVICESCONTROLLER_H_

#include  "ListServicesView.h"

#include "ServiceMenuController.h"

//#include "SeeServiceController.h"
#include "SortServicesController.h"
#include "FilterServicesController.h"
#include "ChangeServiceController.h"
#include "RemoveServiceController.h"
#include "PayServiceController.h"

class ListServicesController {
private:
	ListServicesView *theView;
	Validation *v;
	Utilities *u;
	Client *user;
	Company *company;
	unsigned int serviceID;

	/**
	 * call to print menu according to user type
	 */
	void printListServicesByUserType();

	/**
	 * user interaction method to read service id
	 */
	int getServiceID();

	/**
	 * lists user services
	 */
	void listServices();

	/**
	 * reads the user option and acts accordingly
	 */
	void listServicesMenuHandler();

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
	 * opens new see service services menu
	 */
	void newSeeService();

	/**
	 * opens new change service menu
	 */
	void newChangeServiceMenu();

	/**
	 * opens new remove service menu
	 */
	void newRemoveServiceMenu();

	/**
	 * opens new filter services menu
	 */
	void newFilterServicesMenu();

	/**
	 * opens new sort services menu
	 */
	void newSortServicesMenu();

	/**
	 * opens new pay service menu
	 */
	void newPayServiceMenu();

	/**
	 * opens new see service menu
	 */
	void newServiceMenu();

public:
	/**
	 * Contructor that initalizes all variables
	 * @param client log in user
	 * @param company pointer to the company object
	 */
	ListServicesController(Client *client, Company *company);

	/**
	 * destructor
	 */
	virtual ~ListServicesController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};

#endif /* SRC_CONTROLLER_HEADERS_LISTSERVICESCONTROLLER_H_ */
