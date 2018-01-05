/*
 * LoginController.h
 *
 *  Created on: 03/11/2017
 *      Author: jotaa
 */

#ifndef SRC_CONTROLLER_LOGINCONTROLLER_H_
#define SRC_CONTROLLER_LOGINCONTROLLER_H_

#include "LoginView.h"
#include "Validation.h"
#include "ClientMenuController.h"
#include "EnterController.h"
#include "Client.h"
#include "AdministratorMenuController.h"

class LoginController {
private:
	LoginView *theView;
	Validation *v;
	Utilities *u;
	Client *client;
	Company *company;

	/**
	 * user interaction method to read user credentials
	 */
	void getUserCredentials();

	/**
	 * user interaction method to read user ID
	 */
	unsigned int getID();

	/**
	 * user interaction method to read user password
	 */
	string getPass();

	/**
	 * ends the program
	 */
	void endProgram();

	/**
	 * opens new client menu
	 */
	void newClientMenu();


	/**
	 * opens new company administrator menu
	 */
	void newAdministratorController();

public:
	/**
	 * Contructor that initalizes all variables
	 * @param company pointer to the company object
	 */
	LoginController(Company *company);

	/**
	 * destructor
	 */
	virtual ~LoginController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};

#endif /* SRC_CONTROLLER_LOGINCONTROLLER_H_ */
