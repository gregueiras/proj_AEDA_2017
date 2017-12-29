/*
 * RemoveVehicleView.cpp
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#include "RemoveVehicleView.h"

RemoveVehicleView::RemoveVehicleView() {
	u = new Utilities();

}

RemoveVehicleView::~RemoveVehicleView() {
	// TODO Auto-generated destructor stub
}

void RemoveVehicleView::printMessage(const string &message) {
	cout << message << endl;
}

void RemoveVehicleView::printRemoveVehicleMenu() {
	printMessage(removeVehicleMenu);
}

void RemoveVehicleView::printEnterOption() {
	printMessage(enterOption);
}

void RemoveVehicleView::printEnterConfirmation() {
	printMessage(enterConfirmation);
}

void RemoveVehicleView::printWrongOption() {
	printMessage(wrongOption);
}

void RemoveVehicleView::printEnd() {
	printMessage(end);
}

void RemoveVehicleView::printShutdown() {
	printMessage(shutdown);
}
