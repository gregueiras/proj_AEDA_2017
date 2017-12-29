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

	void newVehicleMenuController();

public:
	SeeVehicleController(Company *company, string plate);
	virtual ~SeeVehicleController();
	void menu();
};

#endif /* SRC_SEEVEHICLECONTROLLER_H_ */
