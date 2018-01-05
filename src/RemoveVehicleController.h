/*
 * RemoveVehicleController.h
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#ifndef SRC_REMOVEVEHICLECONTROLLER_H_
#define SRC_REMOVEVEHICLECONTROLLER_H_

#include "Company.h"
#include "RemoveVehicleView.h"
#include "Validation.h"
#include "VehicleMenuController.h"

class RemoveVehicleController {
private:
	RemoveVehicleView *theView;
	Validation *v;
	Company *company;
	string vehiclePlate;

	/**
	 * read the menu option from the keyboard the value of arrival_date
	 * Date of arrival
	 * @param lowerBound lower bound of the menu option
	 * @param upperBound upper bound of the menu option
	 */
	int getMenuOption(const int lowerBound, const int upperBound);

	/**
	 * method to remove vehicle
	 */
	void removeVehicle();

	/**
	 * opens new vehicle menu
	 */
	void newVehicleMenuController();

	/**
	 * end program
	 */
	void endProgram();
public:
	/**
	 * Contructor that initalizes all variables
	 * @param company pointer to the company object
	 * @param vehiclePlate vehicle plate
	 */
	RemoveVehicleController(Company *company, string vehiclePlate);

	/**
	 * destructor
	 */
	virtual ~RemoveVehicleController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();

};

#endif /* SRC_REMOVEVEHICLECONTROLLER_H_ */
