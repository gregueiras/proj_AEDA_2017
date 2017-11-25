/*
 * NewUserController.h
 *
 *  Created on: 04/11/2017
 *      Author: jotaa
 */

#ifndef SRC_CONTROLLER_NEWUSERCONTROLLER_H_
#define SRC_CONTROLLER_NEWUSERCONTROLLER_H_

#include "NewUserView.h"
#include "Validation.h"
#include "Client.h"
#include "Personal.h"
#include "Business.h"
#include "Company.h"
#include "Address.h"
#include "EnterController.h"
#include "Utilities.h"

using namespace std;

class NewUserController {
private:
	NewUserView *theView;
	Validation *v;
	Utilities *u;
	Company *company;
	Client *user;

	const unsigned int client_type_personal = 1;
	const unsigned int client_type_business = 2;
	const unsigned int client_type_unregistered = 3;

	unsigned int userType, nif, doorNumber;
	double latitude, longitude;
	string name, street, country, city, county, password;

	/**
	 * user interaction method to read user information
	 */
	void getUserInformation();

	/**
	 * user interaction method to read user type infomation
	 */
	unsigned int getUserType();

	/**
	 * user interaction method to read name infomation
	 */
	string getName();

	/**
	 * user interaction method to read nif infomation
	 */
	unsigned int getNIF();

	/**
	 * user interaction method to read street infomation
	 */
	string getStreet();

	/**
	 * user interaction method to read country infomation
	 */
	string getCountry();

	/**
	 * user interaction method to read city infomation
	 */
	string getCity();

	/**
	 * user interaction method to read county infomation
	 */
	string getCounty();

	/**
	 * user interaction method to read door number infomation
	 */
	unsigned int getDoorNumber();

	/**
	 * user interaction method to read latitude infomation
	 */
	double getLatitude();

	/**
	 * user interaction method to read longitude infomation
	 */
	double getLongitude();

	/**
	 * user interaction method to read password infomation
	 */
	string getPassword();

	/**
	 * Creates instance of new user
	 */
	void createUser();

	/**
	 * ends the program
	 */
	void endProgram();

	/**
	 * opens new enter menu
	 */
	void newEnterController();

	/**
	 * opens new requisit service menu
	 */
	void newRequisitServiceController();

public:
	/**
	 * Contructor that initalizes all variables
	 * @param company pointer to the company object
	 */
	NewUserController(Company *company);

	/**
	 * destructor
	 */
	virtual ~NewUserController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};

#endif /* SRC_CONTROLLER_NEWUSERCONTROLLER_H_ */
