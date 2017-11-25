/*
 * ServiceMenuController.h
 *
 *  Created on: 08/11/2017
 *      Author: jotaa
 */

#ifndef SRC_CONTROLLER_HEADERS_SERVICEMENUCONTROLLER_H_
#define SRC_CONTROLLER_HEADERS_SERVICEMENUCONTROLLER_H_

#include "ServiceMenuView.h"
#include  "Validation.h"
#include "Client.h"
#include "RequisitServiceController.h"
#include "ListServicesController.h"
#include "ClientMenuController.h"

class ServiceMenuController {
private:
	ServiceMenuView *theView;
	Validation *v;
	Utilities *u;
	Client *user;
	Company *company;

	void serviceMenuHandler();

	/**
	 * read the menu option from the keyboard the value of arrival_date
	 * Date of arrival
	 * @param lowerBound lower bound of the menu option
	 * @param upperBound upper bound of the menu option
	 */
	int getMenuOption(const int lowerBound, const int upperBound);

	/**
	 * opens new requisit service menu
	 */
	void newRequisitService();

	/**
	 * opens new list services menu
	 */
	void newServiceListMenu();

	/**
	 * opens new client menu
	 */
	void newClientMenu();

	/**
	 * ends the program
	 */
	void endProgram();

public:
	/**
	 * Contructor that initalizes all variables
	 * @param client log in user
	 * @param company pointer to the company object
	 */
	ServiceMenuController(Client *client, Company *company);

	/**
	 * destructor
	 */
	virtual ~ServiceMenuController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};

#endif /* SRC_CONTROLLER_HEADERS_SERVICEMENUCONTROLLER_H_ */
