/*
 * RemoveController.h
 *
 *  Created on: 08/11/2017
 *      Author: jotaa
 */

#ifndef SRC_CONTROLLER_HEADERS_USERMENUCONTROLLER_H_
#define SRC_CONTROLLER_HEADERS_USERMENUCONTROLLER_H_

#include "ChangeUserMenuController.h"
#include "UserMenuView.h"
#include  "Validation.h"
#include "Client.h"
#include "Company.h"
#include "RemoveUserMenuController.h"
#include "ClientMenuController.h"

class UserMenuController {
private:
	UserMenuView *theView;
	Validation *v;
	Utilities *u;
	Client *user;
	Company *company;

	/**
	 * reads the user option and acts accordingly
	 */
	void menuHandler();

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
	 * opens new client menu
	 */
	void newClientMenu();

	/**
	 * opens new change user menu
	 */
	void newChangeUserMenu();

	/**
	 * opens new remove user menu
	 */
	void newRemoveUserMenu();

public:
	/**
	 * Contructor that initalizes all variables
	 * @param client log in user
	 * @param company pointer to the company object
	 */
	UserMenuController(Client *client, Company *company);

	/**
	 * destructor
	 */
	virtual ~UserMenuController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};

#endif /* SRC_CONTROLLER_HEADERS_USERMENUCONTROLLER_H_ */
