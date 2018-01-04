/*
 * NewVehicleView.cpp
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#include "NewVehicleView.h"

NewVehicleView::NewVehicleView() {
	u = new Utilities();
}

NewVehicleView::~NewVehicleView() {
	// TODO Auto-generated destructor stub
}

void NewVehicleView::printMessage(const string& message) {
	cout << message << endl;
}

void NewVehicleView::printInitialMessage() {
	printMessage(initialMessage);
}

void NewVehicleView::printEnterPlate() {
	printMessage(enterPlate);
}

void NewVehicleView::printEnterBrand() {
	printMessage(enterBrand);
}

void NewVehicleView::printEnterModel() {
	printMessage(enterModel);
}

void NewVehicleView::printEnterBirthdayDate() {
	printMessage(enterBirthdayDate);
}

void NewVehicleView::printEnterExpectableTime() {
	printMessage(enterExpectableTime);
}

void NewVehicleView::printEnterMaintenanceDate() {
	printMessage(enterMaintenanceDate);
}
//------------
void NewVehicleView::printEnterBirthdayDay() {
	printMessage(enterBirthdayDay);
}

void NewVehicleView::printEnterBirthdayMonth() {
	printMessage(enterBirthdayMonth);
}

void NewVehicleView::printEnterBirthdayYear() {
	printMessage(enterBirthdayYear);
}

void NewVehicleView::printEnterExpectableHour() {
	printMessage(enterExpectableHour);
}

void NewVehicleView::printEnterExpectableMinute() {
	printMessage(enterExpectableMinute);
}

void NewVehicleView::printEnterMaintenanceDay() {
	printMessage(enterMaintenanceDay);
}

void NewVehicleView::printEnterMaintenanceMonth() {
	printMessage(enterMaintenanceMonth);
}

void NewVehicleView::printEnterMaintenanceYear() {
	printMessage(enterMaintenanceYear);
}

void NewVehicleView::printRepeatedVehicle() {
	printMessage(repeatedVehicle);
}

void NewVehicleView::printEnd() {
	printMessage(end);
}
