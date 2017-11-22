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

void ServiceMenuView::printInitialMessage() {
	printMessage(initialMessage);

}

void ServiceMenuView::printServiceMenu() {
	printMessage(serviceMenu);
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
