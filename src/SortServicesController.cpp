/*
 * SortServicesController.cpp
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#include "SortServicesController.h"

SortServicesController::SortServicesController(Client *client,
		Company *company) {
	theView = new SortServicesView;
	this->company = company;
	v = new Validation();
	u = new Utilities();
	user = client;
	vectorToBeSorted = user->getServices();
	sortedByID = false;
	sortedByDate = false;
	sortedByVolume = false;
	sortedByDistance = false;
	sortedByPrice = false;
}

SortServicesController::~SortServicesController() {
	// TODO Auto-generated destructor stub
}

void SortServicesController::menu() {
	theView->printSortServicesMenu();
	sortServicesHandler();
	newListServicesMenu();
}

void SortServicesController::sortServicesHandler() {
	int option;
	do {
		theView->printEnterOption();
		option = getMenuOption(0, 6);
		switch (option) {
		case 0:
			theView->printShutdown();
			endProgram();
			break;
		case 1:
			sortByID();
			break;
		case 2:
			sortByDate();
			break;
		case 3:
			sortbyVolume();
			break;
		case 4:
			sortByDistance();
			break;
		case 5:
			sortByPrice();
			break;
		case 6:
			newListServicesMenu();
			break;
		}
	} while (option == -1);
}

int SortServicesController::getMenuOption(const int lowerBound,
		const int upperBound) {
	int option;
	bool flag1 = theView->getInfo(option);
	bool flag2 = v->validateBound(option, lowerBound, upperBound);
	if (flag1 == false || flag2 == false) {
		theView->printWrongOption();
		return -1;
	}
	return option;
}

void SortServicesController::sortByID() {
//	sortedByDate = false;
//	sortedByVolume = false;
//	sortedByDistance = false;
//	sortedByPrice = false;
//
//	if (!sortedByID) {
	sortedByID = !sortedByID;
	sort(vectorToBeSorted.begin(), vectorToBeSorted.end(), Sort::auxSortbyID);
	user->setServices(vectorToBeSorted);
//	} else {
//		//printReverse
//	}
}

void SortServicesController::sortByDate() {
//	sortedByID = false;
//	sortedByVolume = false;
//	sortedByDistance = false;
//	sortedByPrice = false;
//	if (!sortedByDate) {
	sortedByDate = !sortedByDate;
	sort(vectorToBeSorted.begin(), vectorToBeSorted.end(), Sort::auxSortbyDate);
	user->setServices(vectorToBeSorted);
//	} else {
//		//printReverse
//	}
}

void SortServicesController::sortbyVolume() {
//	sortedByID = false;
//	sortedByDate = false;
//	sortedByDistance = false;
//	sortedByPrice = false;
//	if (!sortedByVolume) {
	sortedByVolume = !sortedByVolume;
	sort(vectorToBeSorted.begin(), vectorToBeSorted.end(),
			Sort::auxSortbyVolume);
	user->setServices(vectorToBeSorted);
//	} else {
//		//printReverse
//	}
}

void SortServicesController::sortByDistance() {
//	sortedByID = false;
//	sortedByDate = false;
//	sortedByVolume = false;
//	sortedByPrice = false;
//	if (!sortedByDistance) {
	sortedByDistance = !sortedByDistance;
	sort(vectorToBeSorted.begin(), vectorToBeSorted.end(),
			Sort::auxSortbyDistance);
	user->setServices(vectorToBeSorted);
//	} else {
//printReverse
//	}
}

void SortServicesController::sortByPrice() {
//	sortedByID = false;
//	sortedByDate = false;
//	sortedByVolume = false;
//	sortedByDistance = false;
//
//	if (!sortedByPrice) {
	sortedByPrice = !sortedByPrice;
	sort(vectorToBeSorted.begin(), vectorToBeSorted.end(),
			Sort::auxSortbyPrice);
	user->setServices(vectorToBeSorted);
//}
//else {
//	//printReverse
//}
}

void SortServicesController::newListServicesMenu() {

	ListServicesController *listServicesController = new ListServicesController(
			user, company);
	listServicesController->menu();
}

void SortServicesController::endProgram() {

}
