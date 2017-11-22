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
#include "ListServicesController.h"
#include "Company.h"
using namespace std;

class SeeServiceController {
private:
	SeeServiceView *theView;
	Services *service;
	Company *company;
	Client *user;

	void endProgram();
	void newListServicesMenu();
public:
	SeeServiceController(Services *service, Client *user, Company *company);
	virtual ~SeeServiceController();
	void menu();

};

#endif /* SRC_CONTROLLER_HEADERS_SEESERVICECONTROLLER_H_ */
