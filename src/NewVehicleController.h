/*
 * NewVehicleController.h
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#ifndef SRC_NEWVEHICLECONTROLLER_H_
#define SRC_NEWVEHICLECONTROLLER_H_

#include "Company.h"
#include "NewVehicleView.h"
#include "VehicleMenuController.h"

class NewVehicleController {
private:
	NewVehicleView *theView;
	Company *company;
	Validation *v;
	string plate, brand, model;
	Date birthday, maintenance;
	Hour expectable_time;
	unsigned int birthdayDay, birthdayMonth, birthdayYear, expectableHour,
			expectableMinute, maintenanceDay, maintenanceMonth, maintenanceYear;

	void getVehicleInformation();
	void getPlate();
	void getBrand();
	void getModel();
	void getBirthdayDate();
	void getMaintenanceDate();
	void getExpectableTime();

	void createVehicle();

	void newVehicleMenuController();

public:
	NewVehicleController(Company *company);
	virtual ~NewVehicleController();

	void menu();
};

#endif /* SRC_NEWVEHICLECONTROLLER_H_ */
