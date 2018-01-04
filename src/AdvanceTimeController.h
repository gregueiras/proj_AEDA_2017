/*
 * AdvanceTimeController.h
 *
 *  Created on: 4 Jan 2018
 *      Author: jotaa
 */

#ifndef SRC_ADVANCETIMECONTROLLER_H_
#define SRC_ADVANCETIMECONTROLLER_H_

#include "AdministratorMenuController.h"
#include "AdvanceTimeView.h"
class AdvanceTimeController {
private:
	AdvanceTimeView *theView;
	Validation *v;
	Utilities *u;
	Company *company;

	int getMenuOption(const int lowerBound, const int upperBound);

	void endProgram();
	void changeCompanyDate();
	Date * getNewCurrentDate();
	void changeCompanyHour();
	Hour* getNewCurrentTime();

	void newAdministratorMenu();

public:
	AdvanceTimeController(Company *company);
	virtual ~AdvanceTimeController();

	void menu();
};

#endif /* SRC_ADVANCETIMECONTROLLER_H_ */
