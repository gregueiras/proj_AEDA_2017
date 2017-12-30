/*
 * ChangeVehicleView.cpp
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#include "ChangeVehicleView.h"

ChangeVehicleView::ChangeVehicleView() {
	u = new Utilities();
}

ChangeVehicleView::~ChangeVehicleView() {
	// TODO Auto-generated destructor stub
}

void ChangeVehicleView::printMessage(const string& message) {
	cout << message << endl;
}

void ChangeVehicleView::printInitialMessage() {
	printMessage(initialMessage);
}

void ChangeVehicleView::printChangeVehicleMenu() {
	printMessage(changeVehicleMenu);
}

void ChangeVehicleView::printEnterOption() {
	printMessage(enterOption);
}

void ChangeVehicleView::printWrongOption() {
	printMessage(wrongOption);
}

void ChangeVehicleView::printEnd() {
	printMessage(end);
}

void ChangeVehicleView::printShutdown() {
	printMessage(shutdown);
}

void ChangeVehicleView::printEnterNewPlate() {
	printMessage(enterNewPlate);
}

void ChangeVehicleView::printEnterNewBrand() {
	printMessage(enterNewBrand);
}

void ChangeVehicleView::printEnterNewModel() {
	printMessage(enterNewModel);
}

void ChangeVehicleView::printEnterNewBirthdayDate() {
	printMessage(enterNewBirthdayDate);
}

void ChangeVehicleView::printEnterNewExpectableTime() {
	printMessage(enterNewExpectableTime);
}

void ChangeVehicleView::printEnterNewMaintenanceDate() {
	printMessage(enterNewMaintenanceDate);
}
//------------
void ChangeVehicleView::printEnterNewBirthdayDay() {
	printMessage(enterNewBirthdayDay);
}

void ChangeVehicleView::printEnterNewBirthdayMonth() {
	printMessage(enterNewBirthdayMonth);
}

void ChangeVehicleView::printEnterNewBirthdayYear() {
	printMessage(enterNewBirthdayYear);
}

void ChangeVehicleView::printEnterNewExpectableHour() {
	printMessage(enterNewExpectableHour);
}

void ChangeVehicleView::printEnterNewExpectableMinute() {
	printMessage(enterNewExpectableMinute);
}

void ChangeVehicleView::printEnterNewMaintenanceDay() {
	printMessage(enterNewMaintenanceDay);
}

void ChangeVehicleView::printEnterNewMaintenanceMonth() {
	printMessage(enterNewMaintenanceMonth);
}

void ChangeVehicleView::printEnterNewMaintenanceYear() {
	printMessage(enterNewMaintenanceYear);
}

void ChangeVehicleView::printInformation(const string information) {
	printMessage(information);
}
