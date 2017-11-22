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

	void newListServicesMenu();
public:
	RemoveServiceController(Client *client, unsigned int serviceID,
			Company *company);
	virtual ~RemoveServiceController();
	void menu();
};

#endif /* SRC_CONTROLLER_HEADERS_REMOVESERVICECONTROLLER_H_ */
