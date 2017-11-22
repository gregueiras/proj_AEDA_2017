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

	void menuHandler();
	int getMenuOption(const int lowerBound, const int upperBound);

	void endProgram();

	void newClientMenu();
	void newChangeUserMenu();
	void newRemoveUserMenu();

	template<typename T> void getInfo(T& info);
public:
	UserMenuController(Client *client, Company *company);
	virtual ~UserMenuController();
	void menu();
	/* namespace std */
};


template<typename T>
void UserMenuController::getInfo(T &info) {
	if (!theView->getInfo(info)) { //ctrlz, fim do ficheiro
		theView->printEnd();
		newClientMenu();
	}
}

#endif /* SRC_CONTROLLER_HEADERS_USERMENUCONTROLLER_H_ */
