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

	void clientMenuHandler();
	int getMenuOption(const int lowerBound, const int upperBound);

	template<typename T> void getInfo(T &info);

	void endProgram();

	void newLoginMenu();
	void newUserMenu();
	void newServiceMenu();
public:
	ClientMenuController(Client *user, Company *company);
	virtual ~ClientMenuController();
	void menu();

	/* namespace std */
};

template<typename T>
void ClientMenuController::getInfo(T& info) {
	if (!theView->getInfo(info)) { //ctrlz, fim do ficheiro
		theView->printEnd();
		endProgram();
	}
}
#endif /* SRC_CONTROLLER_HEADERS_CLIENTMENUCONTROLLER_H_ */
