/*
 * ChangeVehicleController.h
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#ifndef SRC_CHANGEVEHICLECONTROLLER_H_
#define SRC_CHANGEVEHICLECONTROLLER_H_

#include "Company.h"
#include "VehicleMenuView.h"
#include "VehicleMenuController.h"
#include "ChangeVehicleView.h"

class ChangeVehicleController {
private:
	Company *company;
	string plate;
	ChangeVehicleView *theView;
	Validation *v;

	void menuHandler();

	int getMenuOption(const int lowerBound, const int upperBound);
	string getPlate();
	string getBrand();
	string getModel();
	Date* getBirthdayDate();
	Hour* getExpectableTime();
	Date* getMaintenanceDate();

	void changePlate();
	void changeBrand();
	void changeModel();
	void changeBirthdayDate();
	void changeExpectableTime();
	void changeMaintenanceDate();

	void endProgram();
	void newVehicleMenuController();
public:
	ChangeVehicleController(Company *company, string plate);
	virtual ~ChangeVehicleController();
	void menu();
};

#endif /* SRC_CHANGEVEHICLECONTROLLER_H_ */
