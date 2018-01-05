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
#include "AdvanceTimeController.h"

class AdministratorMenuController {
private:
	AdministratorMenuView *theView;
	Validation *v;
	Utilities *u;
	Company *company;

	/**
	 * read the menu option from the keyboard the value of arrival_date
	 * Date of arrival
	 * @param lowerBound lower bound of the menu option
	 * @param upperBound upper bound of the menu option
	 */
	int getMenuOption(const int lowerBound, const int upperBound);

	/**
	 * opens new user menu
	 */
	void newSeeServices();

	/**
	 * opens new promotional campaign menu
	 */
	void newPromotionalCampaign();

	/**
	 * opens new vehicles menu
	 */
	void newVehiclesMenu();

	/**
	 * opens new advance time menu
	 */
	void newAdvanceTime();

	/**
	 * opens new enter menu
	 */
	void newEnterController();

	/**
	 * end program
	 */
	void endProgram();

public:
	/**
	 * Contructor that initalizes all variables
	 * @param company pointer to the company object
	 */
	AdministratorMenuController(Company *company);

	/**
	 * destructor
	 */
	virtual ~AdministratorMenuController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};

#endif /* SRC_ADMINISTRATORMENUCONTROLLER_H_ */
