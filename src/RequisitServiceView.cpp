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

void RequisitServiceView::printDepartureAddress() {
	printMessage(departureAddress);
}

void RequisitServiceView::printArrivalAddress() {
	printMessage(arrivalAddress);
}

void RequisitServiceView::printEnterStreet() {
	printMessage(enterStreet);
}
void RequisitServiceView::printEnterCountry() {
	printMessage(enterCountry);
}
void RequisitServiceView::printEnterCity() {
	printMessage(enterCity);
}
void RequisitServiceView::printEnterCounty() {
	printMessage(enterCounty);
}
void RequisitServiceView::printEnterDoorNumber() {
	printMessage(enterDoorNumber);
}
void RequisitServiceView::printEnterLatitude() {
	printMessage(enterLatitude);
}
void RequisitServiceView::printEnterLongitude() {
	printMessage(enterLongitude);
}

void RequisitServiceView::printEnterPackagingInitialDate() {
	printMessage(enterPackagingInitialDate);
}

void RequisitServiceView::printEnterPackagingInitialTime() {
	printMessage(enterPackagingInitialTime);
}

void RequisitServiceView::printEnterStorageTime() {
	printMessage(enterStorageTime);
}

void RequisitServiceView::printEnterVolume() {
	printMessage(enterVolume);
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

void RequisitServiceView::printAddToEOM() {
	printMessage(addToEOM);
}

void RequisitServiceView::printEnterOption() {
	printMessage(enterOption);
}

void RequisitServiceView::printWrongOption() {
	printMessage(wrongOption);
}
