/*
 * EnterView.cpp
 *
 *  Created on: 04/11/2017
 *      Author: jotaa
 */

#include "EnterView.h"

EnterView::EnterView() {
	u = new Utilities();
}

EnterView::~EnterView() {
	// TODO Auto-generated destructor stub
}

void EnterView::printMessage(const string message) const {
	cout << message << endl;
}

void EnterView::printEnterMenu() const {
	printMessage(title);
	printMessage(options);
	printEnterOption();
}

void EnterView::printWrongOption() const {
	printMessage(wrongOption);
}
void EnterView::printEnterOption() const {
	printMessage(enterOption);
}
void EnterView::printEnd() const {
	printMessage(end);
}