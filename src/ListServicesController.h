/*
 * ListServicesController.h
 *
 *  Created on: 13/11/2017
 *      Author: jotaa
 */

#ifndef SRC_CONTROLLER_HEADERS_LISTSERVICESCONTROLLER_H_
#define SRC_CONTROLLER_HEADERS_LISTSERVICESCONTROLLER_H_

#include  "ListServicesView.h"

#include "ServiceMenuController.h"

//#include "SeeServiceController.h"
#include "SortServicesController.h"
#include "FilterServicesController.h"
#include "ChangeServiceController.h"
#include "RemoveServiceController.h"
#include "PayServiceController.h"

class ListServicesController {
private:
	ListServicesView *theView;
	Validation *v;
	Utilities *u;
	Client *user;
	Company *company;
	unsigned int serviceID;

	void listServices();
	int getServiceID();
	void listServicesHandler(int serviceID);
	int getMenuOption(const int lowerBound, const int upperBound);

	template<typename T> void getInfo(T &info);

	void endProgram();

	void newSeeService();
	void newChangeServiceMenu();
	void newRemoveServiceMenu();
	void newFilterServicesMenu();
	void newSortServicesMenu();
	void newPayServiceMenu();
	void newServiceMenu();

public:
	ListServicesController(Client *client, Company *company);
	virtual ~ListServicesController();
	void menu();
};

template<typename T>
void ListServicesController::getInfo(T& info) {
	if (!theView->getInfo(info)) { //ctrlz, fim do ficheiro
		theView->printEnd();
		newServiceMenu();
	}
}

#endif /* SRC_CONTROLLER_HEADERS_LISTSERVICESCONTROLLER_H_ */
