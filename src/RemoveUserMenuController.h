/*
 * RemoveMenuController.h
 *
 *  Created on: 08/11/2017
 *      Author: jotaa
 */

#ifndef SRC_CONTROLLER_HEADERS_REMOVEUSERMENUCONTROLLER_H_
#define SRC_CONTROLLER_HEADERS_REMOVEUSERMENUCONTROLLER_H_

#include "RemoveUserMenuView.h"
#include "Validation.h"
#include "Client.h"
#include "UserMenuController.h"
#include "EnterController.h"
#include "Company.h"
#include "Utilities.h"

class RemoveUserMenuController {
private:
	RemoveMenuView *theView;
	Validation *v;
	Utilities *u;
	Client *user;
	Company *company;

	/**
	 *
	 */
	void removeUserHandler();

	/**
	 *
	 */
	void removeUser();

	/**
	 * read the menu option from the keyboard the value of arrival_date
	 * Date of arrival
	 * @param lowerBound lower bound of the menu option
	 * @param upperBound upper bound of the menu option
	 */
	int getMenuOption(const int lowerBound, const int upperBound);

	/**
	 * ends the program
	 */
	void endProgram();

	/**
	 * opens new enter menu
	 */
	void newEnterMenuController();

	/**
	 * opens new user menu
	 */
	void newUserMenuController();

public:
	/**
	 * Contructor that initalizes all variables
	 * @param client log in user
	 * @param company pointer to the company object
	 */
	RemoveUserMenuController(Client *client, Company *company);

	/**
	 * destructor
	 */
	virtual ~RemoveUserMenuController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};
#endif /* SRC_CONTROLLER_HEADERS_REMOVEUSERMENUCONTROLLER_H_ */
