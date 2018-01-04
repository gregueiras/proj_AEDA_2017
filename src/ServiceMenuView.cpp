/*
 * ServiceMenuView.cpp
 *
 *  Created on: 08/11/2017
 *      Author: jotaa
 */

#include "ServiceMenuView.h"

ServiceMenuView::ServiceMenuView() {
	this->u = new Utilities();
}

ServiceMenuView::~ServiceMenuView() {
	// TODO Auto-generated destructor stub
}

void ServiceMenuView::printMessage(const string& message) {
	cout << message << endl;

}

void ServiceMenuView::printServiceMenu() {
	printMessage(serviceMenu);
}

void ServiceMenuView::printServicesListing() {
	printMessage(servicesListing);
}

void ServiceMenuView::printServiceMenuForBusinnessClients() {
	printMessage(serviceMenuForBusinnessClients);
}

void ServiceMenuView::printEnterOption() {
	printMessage(enterOption);
}

void ServiceMenuView::printWrongOption() {
	printMessage(wrongOption);
}

void ServiceMenuView::printEnd() {
	printMessage(end);
}

void ServiceMenuView::printNoServicesRegistered() {
	printMessage(noServicesRegistered);
}

void ServiceMenuView::printServiceInfo(unsigned int id, string userInfo) {
	cout << "ID: " << id << " " << userInfo << "\n";
}

void ServiceMenuView::printEnterServiceID() {
	printMessage(enterServiceID);
}

void ServiceMenuView::printServiceIDNotFound() {
	printMessage(serviceIDNotFound);
}

void ServiceMenuView::printServiceTermExpired() {
	printMessage(serviceTermExpired);
}

void ServiceMenuView::printShutdown() {
	printMessage(shutdown);
}
