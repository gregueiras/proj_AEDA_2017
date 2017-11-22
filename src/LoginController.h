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
class ClientMenuController; 

class LoginController {
private:
	LoginView *theView;
	Validation *v;
	Utilities *u;
	Client *user;
	Company *company;

	unsigned int id;
	string pass;

	void getUserCredentials();
	unsigned int getID();
	string getPass();

	template<typename T> void getInfo(T &info);
	
	void endProgram();

	void newClientMenu();
	void newEnterController();

public:
	LoginController(Company *company);
	virtual ~LoginController();
	void menu();

	/* namespace std */
};

template<typename T>
void LoginController::getInfo(T &info) {
	if (!theView->getInfo(info)) { //ctrlz, fim do ficheiro
		theView->printEnd();
		newEnterController();
	}
}
#endif /* SRC_CONTROLLER_LOGINCONTROLLER_H_ */
