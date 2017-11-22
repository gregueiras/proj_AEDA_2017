/*
 * PayServiceController.h
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#ifndef SRC_CONTROLLER_HEADERS_PAYSERVICECONTROLLER_H_
#define SRC_CONTROLLER_HEADERS_PAYSERVICECONTROLLER_H_

#include <iostream>
#include "PayServiceView.h"
#include "ListServicesController.h"

using namespace std;

class PayServiceController {
private:
	PayServiceView *theView;
	Validation *v;
	Utilities *u;
	Client *user;
	Company *company;
	unsigned int serviceID;
	void newListServicesMenu();

	template<typename T> void getInfo(T &info);

public:
	PayServiceController(Client *user, unsigned int serviceID, Company *company);
	virtual ~PayServiceController();
	void menu();
};

template<typename T>
void PayServiceController::getInfo(T &info) {
	if (!theView->getInfo(info)) { //ctrlz, fim do ficheiro
		theView->printEnd();
		newListServicesMenu();
	}
}

#endif /* SRC_CONTROLLER_HEADERS_PAYSERVICECONTROLLER_H_ */
