/*
 * EnterController.h
 *
 *  Created on: 04/11/2017
 *      Author: jotaa
 */

#ifndef CONTROLLER_ENTERCONTROLLER_H_
#define CONTROLLER_ENTERCONTROLLER_H_

#include "EnterView.h"
#include "EnterController.h"
#include "LoginController.h"
#include "NewUserController.h"

class EnterController {
private:
	EnterView *theView;
	Validation *v;
	Utilities *u;
	Company *company;

	/**
	 * reads the user option and acts accordingly
	 */
	void enterMenu();

	/**
	 * read the menu option from the keyboard the value of arrival_date
	 * Date of arrival
	 * @param lowerBound lower bound of the menu option
	 * @param upperBound upper bound of the menu option
	 */
	int getMenuOption(const int lowerBound, const int upperBound);

	/**
	 * opens new login menu
	 */
	void newLoginMenu();

	/**
	 * opens new user menu
	 */
	void newUserMenu();

	/**
	 * end program
	 */
	void endProgram();

public:
	/**
	 * Contructor that initalizes all variables
	 * @param company pointer to the company object
	 */
	EnterController(Company *company);

	/**
	 * destructor
	 */
	virtual ~EnterController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};

#endif /* CONTROLLER_ENTERCONTROLLER_H_ */
