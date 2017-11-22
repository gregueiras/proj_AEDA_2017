/*
 * EnterController.h
 *
 *  Created on: 04/11/2017
 *      Author: jotaa
 */

#ifndef CONTROLLER_ENTERCONTROLLER_H_
#define CONTROLLER_ENTERCONTROLLER_H_

#include "EnterView.h"
#include "EnterController.h"
#include "LoginController.h"
#include "NewUserController.h"

class EnterController {
private:
	EnterView *theView;
	Validation *v;
	Utilities *u;
	Company *company;

	void enterMenu();
	int getMenuOption(const int lowerBound, const int upperBound);
	void newLoginMenu();
	void newUserMenu();
	void endProgram();

	template<typename T> void getInfo(T& info);
public:
	EnterController(Company *company);
	virtual ~EnterController();
	void menu();

};

template<typename T>
void EnterController::getInfo(T& info) {
	if (!theView->getInfo(info)) { //ctrlz, fim do ficheiro
		theView->printEnd();
		endProgram();
	}
}

#endif /* CONTROLLER_ENTERCONTROLLER_H_ */
