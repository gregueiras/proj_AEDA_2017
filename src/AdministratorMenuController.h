/*
 * AdministratorMenuController.h
 *
 *  Created on: 25 Dec 2017
 *      Author: jotaa
 */

#ifndef SRC_ADMINISTRATORMENUCONTROLLER_H_
#define SRC_ADMINISTRATORMENUCONTROLLER_H_

#include "LoginController.h"
#include "AdministratorMenuView.h"
#include "PromotionCampaignController.h"
#include "SeeServicesController.h"
#include "VehicleMenuController.h"

class AdministratorMenuController {
private:
	AdministratorMenuView *theView;
	Validation *v;
	Utilities *u;
	Company *company;

	int getMenuOption(const int lowerBound, const int upperBound);

	void newSeeServices();

	void newPromotionalCampaign();

	void newVehiclesMenu();

	void newEnterMenu();

	void endProgram();

public:
	AdministratorMenuController(Company *company);
	virtual ~AdministratorMenuController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};

#endif /* SRC_ADMINISTRATORMENUCONTROLLER_H_ */
