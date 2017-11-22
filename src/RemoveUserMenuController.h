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

	void removeUserHandler();
	void removeUser();

	int getMenuOption(const int lowerBound, const int upperBound);
	bool getConfirmation();

	template<typename T> void getInfo(T &info);

	void endProgram();
	void newEnterMenuController();
	void newUserMenuController();

public:
	RemoveUserMenuController(Client *client, Company *company);
	virtual ~RemoveUserMenuController();
	void menu();
};

template<typename T>
void RemoveUserMenuController::getInfo(T& info) {
	if (!theView->getInfo(info)) { //ctrlz, fim do ficheiro
		theView->printEnd();
		newUserMenuController();
	}
}
#endif /* SRC_CONTROLLER_HEADERS_REMOVEUSERMENUCONTROLLER_H_ */
