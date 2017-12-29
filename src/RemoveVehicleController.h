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
	Company *company;
	string vehiclePlate;
	Validation *v;

	void removeVehicleHandler();
	int getMenuOption(const int lowerBound, const int upperBound);
	void removeVehicle();
	void newVehicleMenuController();
	void endProgram();
public:
	RemoveVehicleController(Company *company, string vehiclePlate);
	virtual ~RemoveVehicleController();
	void menu();

};

#endif /* SRC_REMOVEVEHICLECONTROLLER_H_ */
