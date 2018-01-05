/*
 * VehicleMenuController.h
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#ifndef SRC_VEHICLEMENUCONTROLLER_H_
#define SRC_VEHICLEMENUCONTROLLER_H_

#include "Company.h"
#include "VehicleMenuView.h"
#include "Validation.h"

#include "SeeVehicleController.h"
#include "NewVehicleController.h"
#include "ChangeVehicleController.h"
#include "RemoveVehicleController.h"
#include "AdministratorMenuController.h"

class VehicleMenuController {
private:
	Company *company;
	VehicleMenuView *theView;
	Validation *v;
	string plate;

	/**
	 * list vehicles on the company
	 */
	void listVehicles();

	/**
	 * read the menu option from the keyboard the value of arrival_date
	 * Date of arrival
	 * @param lowerBound lower bound of the menu option
	 * @param upperBound upper bound of the menu option
	 * @return option
	 */
	int getMenuOption(const int lowerBound, const int upperBound);

	/**
	 * list vehicles on the company
	 * @return vehicle_string
	 */
	string getVehiclePlate();

	/**
	 * opens new see vehicle menu
	 */
	void newSeeVehicleMenu();

	/**
	 * opens new add vehicle menu
	 */
	void newAddVehicleMenu();

	/**
	 * opens new change vehicle menu
	 */
	void newChangeVehicleMenu();

	/**
	 * sends vehicle to maintenance
	 */
	void sendVehicleToMaintenance();

	/**
	 * opens new remove vehicle menu
	 */
	void newRemoveVehicleMenu();

	/**
	 * opens new administrator menu
	 */
	void newAdministratorMenu();

	/**
	 * end program
	 */
	void endProgram();
public:
	/**
	 * Contructor that initalizes all variables
	 * @param company pointer to the company object
	 */
	VehicleMenuController(Company *company);

	/**
	 * destructor
	 */
	virtual ~VehicleMenuController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};

#endif /* SRC_VEHICLEMENUCONTROLLER_H_ */
