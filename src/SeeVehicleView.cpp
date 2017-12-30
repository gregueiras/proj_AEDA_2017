/*
 * SeeVehicleView.cpp
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#include "SeeVehicleView.h"

SeeVehicleView::SeeVehicleView() {
	u = new Utilities();
}

SeeVehicleView::~SeeVehicleView() {
	// TODO Auto-generated destructor stub
}

void SeeVehicleView::printMessage(const string& message) {
	cout << message << endl;
}

void SeeVehicleView::printInitialMessage() {
	printMessage(initialMessage);
}

void SeeVehicleView::printInformation(const string& information) {
	printMessage(information);
}

void SeeVehicleView::printEnd() {
	printMessage(end);
}
