/*
 * SeeServicesView.cpp
 *
 *  Created on: 25 Dec 2017
 *      Author: jotaa
 */

#include "SeeServicesView.h"

SeeServicesView::SeeServicesView() {
	// TODO Auto-generated constructor stub

}

SeeServicesView::~SeeServicesView() {
	// TODO Auto-generated destructor stub
}

void SeeServicesView::printMessage(const string& message) {
	cout << message << endl;
}

void SeeServicesView::printInitialMessage() {
	printMessage(initialMessage);
}

void SeeServicesView::printInformation(const string& information) {
	printMessage(information);
}

void SeeServicesView::printEnd() {
	printMessage(end);
}

void SeeServicesView::printShutdown() const {
}

void SeeServicesView::printListServices() {
	printMessage(listServices);
}

void SeeServicesView::printNoVehiclesRegistered() {
	printMessage(noVehiclesRegistered);
}
