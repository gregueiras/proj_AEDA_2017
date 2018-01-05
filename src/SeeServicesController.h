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

	/**
	 * prints services invoices
	 */
	void printServicesInvoices();

	/**
	 * opens new administrator menu
	 */
	void newAdministratorMenu();

public:
	/**
	 * Contructor that initalizes all variables
	 * @param company pointer to the company object
	 */
	SeeServicesController(Company *company);

	/**
	 * destructor
	 */
	virtual ~SeeServicesController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();

};

#endif /* SRC_SEESERVICESCONTROLLER_H_ */
