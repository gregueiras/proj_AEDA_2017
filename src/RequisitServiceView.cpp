/*
 * RequisitServiceView.cpp
 *
 *  Created on: 13/11/2017
 *      Author: jotaa
 */

#include "RequisitServiceView.h"

RequisitServiceView::RequisitServiceView() {
	// TODO Auto-generated constructor stub
}

void RequisitServiceView::printMessage(const string& message) {
	cout << message << endl;
}

RequisitServiceView::~RequisitServiceView() {
	// TODO Auto-generated destructor stub
}

void RequisitServiceView::printInitialMessage() {
	printMessage(initialMessage);
}

void RequisitServiceView::printOriginAddress() {
	printMessage(originAddress);
}

void RequisitServiceView::printDestinationAddress() {
	printMessage(destinationAddress);
}

void RequisitServiceView::printEnterStreet() {
	printMessage(enterStreet + exit);
}
void RequisitServiceView::printEnterCountry() {
	printMessage(enterCountry + exit);
}
void RequisitServiceView::printEnterCity() {
	printMessage(enterCity + exit);
}
void RequisitServiceView::printEnterCounty() {
	printMessage(enterCounty + exit);
}
void RequisitServiceView::printEnterDoorNumber() {
	printMessage(enterDoorNumber + exit);
}
void RequisitServiceView::printEnterLatitude() {
	printMessage(enterLatitude + exit);
}
void RequisitServiceView::printEnterLongitude() {
	printMessage(enterLongitude + exit);
}

void RequisitServiceView::printEnterPackagingInitialDate() {
	printMessage(enterPackagingInitialDate + exit);
}

void RequisitServiceView::printEnterPackagingInitialTime() {
	printMessage(enterPackagingInitialTime + exit);
}

void RequisitServiceView::printEnterStorageTime() {
	printMessage(enterStorageTime + exit);
}

void RequisitServiceView::printEnterVolume() {
	printMessage(enterVolume + exit);
}

void RequisitServiceView::printWrongPackagingInitialDay() {
	printMessage(wrongPackagingInitialDay);
}

void RequisitServiceView::printWrongPackagingInitialMonth() {
	printMessage(wrongPackagingInitialMonth);
}

void RequisitServiceView::printWrongPackagingInitialYear() {
	printMessage(wrongPackagingInitialYear);
}

void RequisitServiceView::printWrongPackagingInitialMinute() {
	printMessage(wrongPackagingInitialMinute);
}

void RequisitServiceView::printWrongPackagingInitialHour() {
	printMessage(wrongPackagingInitialHour);
}

void RequisitServiceView::printWrongStorageTime() {
	printMessage(wrongStorageTime);
}

void RequisitServiceView::printWrongNIF() {
	printMessage(wrongNIF);
}
void RequisitServiceView::printWrongLatitude() {
	printMessage(wrongLatitude);
}
void RequisitServiceView::printWrongLongitude() {
	printMessage(wrongLongitude);
}

void RequisitServiceView::printEnd() {
	printMessage(end);
}

void RequisitServiceView::printAskAddToEOM() {
	printMessage(addToEOM);
}

void RequisitServiceView::printEnterOption() {
	printMessage(enterOption);
}

void RequisitServiceView::printWrongOption() {
	printMessage(wrongOption);
}

void RequisitServiceView::printShutdown() {
	printMessage(shutdown);
}

/**
 * reads string from keyboard
 */
string RequisitServiceView::getLine() {
	string line;
	getline(cin, line);
	return line;
}

void RequisitServiceView::printEnterVehicleExpectedTime() {
	printMessage(enterVehicleExpectedTime);
}

void RequisitServiceView::printEnterPackagingInitialDay() {
	printMessage(enterPackagingInitialDay);
}

void RequisitServiceView::printEnterPackagingInitialMonth() {
	printMessage(enterPackagingInitialMonth);
}

void RequisitServiceView::printEnterMaintenanceYear() {
	printMessage(enterPackagingInitialYear);
}

void RequisitServiceView::printEnterPackagingInitialHour() {
	printMessage(enterPackagingInitialHour);
}

void RequisitServiceView::printEnterPackagingInitialMinute() {
	printMessage(enterPackagingInitialMinute);
}
