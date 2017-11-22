/*
 * SeeServiceView.cpp
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#include "SeeServiceView.h"

SeeServiceView::SeeServiceView() {
	// TODO Auto-generated constructor stub

}

SeeServiceView::~SeeServiceView() {
	// TODO Auto-generated destructor stub
}

void SeeServiceView::printMessage(const string& message) {
	cout << message << endl;
}

void SeeServiceView::printInitialMessage() {
	printMessage(initialMessage);

}

void SeeServiceView::printServiceInformation(const string& information) {
	printMessage(information);
}

void SeeServiceView::printEnd() {
	printMessage(end);
}
