/*
 * RemoveServiceController.h
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#ifndef SRC_CONTROLLER_HEADERS_REMOVESERVICECONTROLLER_H_
#define SRC_CONTROLLER_HEADERS_REMOVESERVICECONTROLLER_H_

#include <iostream>
#include "RemoveServiceView.h"
#include "ListServicesController.h"

using namespace std;

class RemoveServiceController {
private:
	RemoveServiceView *theView;
	Validation *v;
	Utilities *u;
	unsigned int serviceID;
	Company *company;
	Client *user;

	/**
	 * opens new list services menu
	 */
	void newListServicesMenu();

public:
	/**
	 * Contructor that initalizes all variables
	 * @param client log in user
	 * @param serviceID chosen service id
	 * @param company pointer to the company object
	 */
	RemoveServiceController(Client *client, unsigned int serviceID,
			Company *company);
	/**
	 * destructor
	 */
	virtual ~RemoveServiceController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};

#endif /* SRC_CONTROLLER_HEADERS_REMOVESERVICECONTROLLER_H_ */
