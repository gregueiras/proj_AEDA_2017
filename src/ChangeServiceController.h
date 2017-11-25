/*
 * ChangeServiceController.h
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#ifndef SRC_CONTROLLER_HEADERS_CHANGESERVICECONTROLLER_H_
#define SRC_CONTROLLER_HEADERS_CHANGESERVICECONTROLLER_H_

#include <iostream>
#include "ChangeServiceView.h"
#include "ListServicesController.h"
#include "Company.h"

using namespace std;
class ChangeServiceController {
private:
	ChangeServiceView *theView;
	Validation *v;
	Utilities *u;
	Services *service;
	Client *user;
	Company *company;

	/**
	 * opens new list services menu
	 */
	void newListServicesMenu();

public:
	/**
	 * Contructor that initalizes all variables
	 * @param service chosen service
	 * @param client log in user
	 * @param company pointer to the company object
	 */
	ChangeServiceController(Services *service, Client *client,
			Company *company);

	/**
	 * destructor
	 */
	virtual ~ChangeServiceController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};

#endif /* SRC_CONTROLLER_HEADERS_CHANGESERVICECONTROLLER_H_ */
