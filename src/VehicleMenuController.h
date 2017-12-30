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

	void menuHandler();
	void listVehicles();
	int getMenuOption(const int lowerBound, const int upperBound);
	bool getVehiclePlate();
	bool askVehiclePlate();

	void seeVehicleMenu();
	void newVehicleMenu();
	void changeVehicleMenu();
	void sendVehicleToMaintenanceMenu();
	void removeVehicleMenu();
	void newAdministratorMenu();
	void endProgram();
public:
	VehicleMenuController(Company *company);
	virtual ~VehicleMenuController();
	void menu();
};

#endif /* SRC_VEHICLEMENUCONTROLLER_H_ */
