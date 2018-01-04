/*
 * SeeServiceController.h
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#ifndef SRC_CONTROLLER_HEADERS_SEESERVICECONTROLLER_H_
#define SRC_CONTROLLER_HEADERS_SEESERVICECONTROLLER_H_

#include <iostream>
#include "SeeServiceView.h"
#include "ServiceMenuController.h"
#include "Company.h"

using namespace std;

class SeeServiceController {
private:
	SeeServiceView *theView;
	Services *service;
	Company *company;
	Client *user;

	/**
	 * opens new list services menu
	 */
	void newServiceMenu();
public:
	/**
	 * Contructor that initalizes all variables
	 * @param service chosen service
	 * @param client log in user
	 * @param company pointer to the company object
	 */
	SeeServiceController(Services *service, Client *client, Company *company);

	/**
	 * destructor
	 */
	virtual ~SeeServiceController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};

#endif /* SRC_CONTROLLER_HEADERS_SEESERVICECONTROLLER_H_ */
