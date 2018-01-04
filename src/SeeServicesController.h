/*
 * SeeServicesController.h
 *
 *  Created on: 25 Dec 2017
 *      Author: jotaa
 */

#ifndef SRC_SEESERVICESCONTROLLER_H_
#define SRC_SEESERVICESCONTROLLER_H_

#include "Company.h"
#include "SeeServicesView.h"
#include "AdministratorMenuController.h"
#include "Client.h"

class SeeServicesController {
	SeeServicesView *theView;
	Company *company;

	void printServicesInvoices();
	void newAdministratorMenu();

public:
	SeeServicesController(Company *company);
	virtual ~SeeServicesController();
	void menu();

};

#endif /* SRC_SEESERVICESCONTROLLER_H_ */
