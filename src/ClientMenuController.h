/*
 * ClientMenuController.h
 *
 *  Created on: 06/11/2017
 *      Author: jotaa
 */

#ifndef SRC_CONTROLLER_HEADERS_CLIENTMENUCONTROLLER_H_
#define SRC_CONTROLLER_HEADERS_CLIENTMENUCONTROLLER_H_

#include "ClientMenuView.h"
#include  "Validation.h"
#include "LoginController.h"
#include "UserMenuController.h"
#include "Client.h"
#include "ServiceMenuController.h"

class ClientMenuController {
private:
	ClientMenuView *theView;
	Validation *v;
	Utilities *u;
	Client *user;
	Company *company;

	/**
	 * reads the user option and acts accordingly
	 */
	void clientMenuHandler();

	/**
	 * read the menu option from the keyboard the value of arrival_date
	 * Date of arrival
	 * @param lowerBound lower bound of the menu option
	 * @param upperBound upper bound of the menu option
	 */
	int getMenuOption(const int lowerBound, const int upperBound);

	/**
	 * end program
	 */
	void endProgram();

	/**
	 * opens new enter menu
	 */
	void newEnterMenu();

	/**
	 * opens new user menu
	 */
	void newUserMenu();

	/**
	 * opens new service menu
	 */
	void newServiceMenu();
public:
	/**
	 * Contructor that initalizes all variables
	 * @param client log in user
	 * @param company pointer to the company object
	 */
	ClientMenuController(Client *user, Company *company);

	/**
	 * destructor
	 */
	virtual ~ClientMenuController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};
#endif /* SRC_CONTROLLER_HEADERS_CLIENTMENUCONTROLLER_H_ */
