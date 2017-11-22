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
	Client *user;
	Company *company;

	void menuHandler();

	void changeName();
	void changeNIF();
	void changeStreet();
	void changeCountry();
	void changeCity();
	void changeCounty();
	void changeDoorNumber();
	void changeLatitude();
	void changeLongitude();

	string getName();
	unsigned int getNIF();
	string getStreet();
	string getCountry();
	string getCity();
	string getCounty();
	unsigned int getDoorNumber();
	double getLatitude();
	double getLongitude();
	bool getKeepContinuing();

	int getMenuOption(const int lowerBound, const int upperBound);
	template<typename T> void getInfo(T &info);
	void endProgram();
	void newUserMenu();

public:
	ChangeUserMenuController(Client *client, Company *company);
	virtual ~ChangeUserMenuController();
	void menu();
};

template<typename T>
void ChangeUserMenuController::getInfo(T &info) {
	if (!theView->getInfo(info)) { //ctrlz, fim do ficheiro
		theView->printEnd();
		newUserMenu();
	}
}
#endif /* SRC_CONTROLLER_HEADERS_CHANGEUSERMENUCONTROLLER_H_ */
