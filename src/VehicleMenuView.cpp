/*
 * VehicleMenuView.cpp
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#include "VehicleMenuView.h"

VehicleMenuView::VehicleMenuView() {
	this->u = new Utilities();
}

VehicleMenuView::~VehicleMenuView() {
	// TODO Auto-generated destructor stub
}

void VehicleMenuView::printMessage(const string& message) {
	cout << message << endl;
}

void VehicleMenuView::printVehicleMenu() {
	printMessage(vehicleMenu);
}

void VehicleMenuView::printEnterOption() {
	printMessage(enterOption);
}

void VehicleMenuView::printWrongOption() {
	printMessage(wrongOption);
}

void VehicleMenuView::printEnd() {
	printMessage(end);
}

void VehicleMenuView::printShutdown() {
	printMessage(shutdown);
}

void VehicleMenuView::printInformation(const string info) {
	printMessage(info);
}

void VehicleMenuView::printPlateNotFound() {
	printMessage(plateNotFound);
}

void VehicleMenuView::printEnterPlate() {
	printMessage(enterPlate);
}
