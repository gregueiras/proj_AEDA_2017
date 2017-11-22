/*
 * SortServicesController.h
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#ifndef SRC_CONTROLLER_HEADERS_SORTSERVICESCONTROLLER_H_
#define SRC_CONTROLLER_HEADERS_SORTSERVICESCONTROLLER_H_

#include "SortServicesView.h"
#include "ListServicesController.h"
#include "Company.h"

class SortServicesController {
private:
	SortServicesView *theView;
	Validation *v;
	Utilities *u;
	Client *user;
	vector<Services *> vectorToBeSorted;
	Company *company;

	void sortServicesHandler();
	void sortByID();
	void sortByDate();
	void sortbyVolume();
	void sortByDistance();
	void sortByPrice();

	int getMenuOption(const int lowerBound, const int upperBound);

	template<typename T> void getInfo(T &info);

	void endProgram();
	void newListServicesMenu();
public:
	SortServicesController(Client *client, Company *company);
	virtual ~SortServicesController();
	void menu();
};

template<typename T>
void SortServicesController::getInfo(T& info) {
	if (!theView->getInfo(info)) { //ctrlz, fim do ficheiro
		theView->printEnd();
		newListServicesMenu();
	}
}

#endif /* SRC_CONTROLLER_HEADERS_SORTSERVICESCONTROLLER_H_ */
