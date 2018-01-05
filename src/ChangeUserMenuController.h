/*
 * ChangeUserMenuController.h
 *
 *  Created on: 08/11/2017
 *      Author: jotaa
 */

#ifndef SRC_CONTROLLER_HEADERS_CHANGEUSERMENUCONTROLLER_H_
#define SRC_CONTROLLER_HEADERS_CHANGEUSERMENUCONTROLLER_H_

#include "ChangeUserMenuView.h"
#include  "Validation.h"
#include "Client.h"
#include "Company.h"
#include "UserMenuController.h"

class ChangeUserMenuController {
private:
	ChangeUserMenuView *theView;

	Validation *v;
	Utilities *u;
	Client *client;
	Company *company;

	/**
	 * user interaction method to change name
	 */
	void changeName();

	/**
	 * user interaction method to change nif
	 */
	void changeNIF();

	/**
	 * user interaction method to change street
	 */
	void changeStreet();

	/**
	 * user interaction method to change country
	 */
	void changeCountry();

	/**
	 * user interaction method to change city
	 */
	void changeCity();

	/**
	 * user interaction method to change county
	 */
	void changeCounty();

	/**
	 * user interaction method to change door number
	 */
	void changeDoorNumber();

	/**
	 * user interaction method to change latitude
	 */
	void changeLatitude();

	/**
	 * user interaction method to change longitude
	 */
	void changeLongitude();

	/**
	 * user interaction method to change password
	 */
	void changePassword();

	/**
	 * user interaction method to read name information
	 * @return the name
	 */
	string getName();

	/**
	 * user interaction method to read nif information
	 * @return the nif
	 */
	unsigned int getNIF();

	/**
	 * user interaction method to read street information
	 * @return the street
	 */
	string getStreet();

	/**
	 * user interaction method to read country information
	 * @return the country
	 */
	string getCountry();

	/**
	 * user interaction method to read city information
	 * @return the city
	 */
	string getCity();

	/**
	 * user interaction method to read county information
	 * @return the county
	 */
	string getCounty();

	/**
	 * user interaction method to read door number information
	 * @return the door number
	 */
	unsigned int getDoorNumber();

	/**
	 * user interaction method to read latitude information
	 * @return the latitude
	 */
	double getLatitude();

	/**
	 * user interaction method to read longitude information
	 * @return the longitude
	 */
	double getLongitude();

	/**
	 * user interaction method to read password information
	 * @return the password
	 */
	string getPassword();

	/**
	 * method to set new information of user
	 */
	void changeInformation();

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
	 * opens new user menu
	 */
	void newUserMenu();

public:
	/**
	 * Contructor that initalizes all variables
	 * @param client log in user
	 * @param company pointer to the company object
	 */
	ChangeUserMenuController(Client *client, Company *company);

	/**
	 * destructor
	 */
	virtual ~ChangeUserMenuController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
}
;

#endif /* SRC_CONTROLLER_HEADERS_CHANGEUSERMENUCONTROLLER_H_ */
