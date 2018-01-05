/*
 * AdvanceTimeController.h
 *
 *  Created on: 4 Jan 2018
 *      Author: jotaa
 */

#ifndef SRC_ADVANCETIMECONTROLLER_H_
#define SRC_ADVANCETIMECONTROLLER_H_

#include "AdministratorMenuController.h"
#include "AdvanceTimeView.h"
class AdvanceTimeController {
private:
	AdvanceTimeView *theView;
	Validation *v;
	Utilities *u;
	Company *company;

	/**
	 * user interaction method to change company date
	 */
	void menuHandler();

	void updateCompanyInformation();

	/**
	 * read the menu option from the keyboard the value of arrival_date
	 * Date of arrival
	 * @param lowerBound lower bound of the menu option
	 * @param upperBound upper bound of the menu option
	 */
	int getMenuOption(const int lowerBound, const int upperBound);

	/**
	 * user interaction method to change company date
	 */
	void changeCompanyDate();

	/**
	 * user interaction method to read new current date
	 * @return the new date
	 */
	Date * getNewCurrentDate();

	/**
	 * user interaction method to change company hour
	 */
	void changeCompanyHour();

	/**
	 * user interaction method to read new current hour
	 * @return the new hour
	 */
	Hour* getNewCurrentTime();

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
	AdvanceTimeController(Company *company);

	/**
	 * destructor
	 */
	virtual ~AdvanceTimeController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};

#endif /* SRC_ADVANCETIMECONTROLLER_H_ */
