/*
 * ListServicesView.cpp
 *
 *  Created on: 13/11/2017
 *      Author: jotaa
 */

#include "ListServicesView.h"

ListServicesView::ListServicesView() {
	u = new Utilities();
}

ListServicesView::~ListServicesView() {
	// TODO Auto-generated destructor stub
}

void ListServicesView::printMessage(const string &message) {
	cout << message << endl;
}

void ListServicesView::printInitialMessage() {
	printMessage(initialMessage);
}
void ListServicesView::printEnterOption() {
	printMessage(enterOption);
}

void ListServicesView::printWrongOption() {
	printMessage(wrongOption);
}

void ListServicesView::printEnd() {
	printMessage(end);
}

void ListServicesView::printListServicesMenu() {
	printMessage(listServicesMenu);
}

void ListServicesView::printServiceInfo(unsigned int i, string userInfo) {
	cout << i << userInfo;
}

void ListServicesView::printEnterServiceID() {
	printMessage(enterServiceID);
}

void ListServicesView::printListServicesMenuForBusinnessClients() {
	printMessage(listServicesMenuForBusinnessClients);
}
