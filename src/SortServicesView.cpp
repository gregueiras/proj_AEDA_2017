/*
 * SortServicesView.cpp
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#include "SortServicesView.h"

SortServicesView::SortServicesView() {
	u = new Utilities();
}

void SortServicesView::printMessage(const string& message) {
	cout << message << endl;
}

SortServicesView::~SortServicesView() {
	// TODO Auto-generated destructor stub
}

void SortServicesView::printSortServicesMenu() {
	printMessage(sortServicesMenu);
}

void SortServicesView::printEnterOption() {
	printMessage(enterOption);
}

void SortServicesView::printWrongOption() {
	printMessage(wrongOption);
}

void SortServicesView::printEnd() {
	printMessage(end);
}

void SortServicesView::printShutdown()  {
	printMessage(shutdown);
}
