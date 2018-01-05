/*
 * SeeVehicleController.h
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#ifndef SRC_SEEVEHICLECONTROLLER_H_
#define SRC_SEEVEHICLECONTROLLER_H_

#include "Company.h"
#include "SeeVehicleView.h"
#include "VehicleMenuController.h"

class SeeVehicleController {
private:
	SeeVehicleView *theView;
	Company *company;
	string plate;

	/**
	 * opens new vehicle menu
	 */
	void newVehicleMenuController();

public:
	/**
	 * Contructor that initalizes all variables
	 * @param company pointer to the company object
	 * @param plate vehicle plate
	 */
	SeeVehicleController(Company *company, string plate);

	/**
	 * destructor
	 */
	virtual ~SeeVehicleController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};

#endif /* SRC_SEEVEHICLECONTROLLER_H_ */
