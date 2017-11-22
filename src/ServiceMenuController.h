/*
 * ServiceMenuController.h
 *
 *  Created on: 08/11/2017
 *      Author: jotaa
 */

#ifndef SRC_CONTROLLER_HEADERS_SERVICEMENUCONTROLLER_H_
#define SRC_CONTROLLER_HEADERS_SERVICEMENUCONTROLLER_H_

#include "ServiceMenuView.h"
#include  "Validation.h"
#include "Client.h"
#include "RequisitServiceController.h"
#include "ListServicesController.h"
#include "ClientMenuController.h"

class ServiceMenuController {
private:
	ServiceMenuView *theView;
	Validation *v;
	Utilities *u;
	Client *user;
	Company *company;

	void serviceMenuHandler();

	int getMenuOption(const int lowerBound, const int upperBound);
	template<typename T> void getInfo(T &info);

	void newRequisitService();
	void newServiceListMenu();
	void newClientMenu();

	void endProgram();

public:
	ServiceMenuController(Client *client, Company *company);
	virtual ~ServiceMenuController();
	void menu();
};

template<typename T>
void ServiceMenuController::getInfo(T& info) {
	if (!theView->getInfo(info)) { //ctrlz, fim do ficheiro
		theView->printEnd();
		newClientMenu();
	}
}

#endif /* SRC_CONTROLLER_HEADERS_SERVICEMENUCONTROLLER_H_ */
