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

	void newListServicesMenu();

public:
	ChangeServiceController(Services *service, Client *user, Company *company);
	virtual ~ChangeServiceController();
	void menu();
};

#endif /* SRC_CONTROLLER_HEADERS_CHANGESERVICECONTROLLER_H_ */
