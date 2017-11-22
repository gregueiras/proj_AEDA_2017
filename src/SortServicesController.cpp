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
}

SortServicesController::~SortServicesController() {
	// TODO Auto-generated destructor stub
}

void SortServicesController::menu() {
	theView->printInitialMessage();
	sortServicesHandler();
	newListServicesMenu();
}

void SortServicesController::sortServicesHandler() {
	theView->printEnterOption();
	int option = getMenuOption(0, 7);
	switch (option) {
	case 0:
		theView->printEnd();
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
	default:
		newListServicesMenu();
		break;
	}
}

int SortServicesController::getMenuOption(const int lowerBound,
		const int upperBound) {
	int option;
	bool flag = false;
	while (!flag) {
		getInfo(option);
		if (!(flag = v->validateBound(option, lowerBound, upperBound))) {
			theView->printWrongOption();
		}
	}
	return option;
}
void SortServicesController::endProgram() {
	exit(0);
}

void SortServicesController::newListServicesMenu() {
	ListServicesController *listServicesController = new ListServicesController(
			user, company);
	listServicesController->menu();
}

void SortServicesController::sortByID() {
	sort(vectorToBeSorted.begin(), vectorToBeSorted.end(), Sort::auxSortbyID);
	user->setServices(vectorToBeSorted);
}

void SortServicesController::sortByDate() {

	sort(vectorToBeSorted.begin(), vectorToBeSorted.end(), Sort::auxSortbyDate);
	user->setServices(vectorToBeSorted);
}


void SortServicesController::sortbyVolume() {
	sort(vectorToBeSorted.begin(), vectorToBeSorted.end(), Sort::auxSortbyVolume);
	user->setServices(vectorToBeSorted);
}

void SortServicesController::sortByDistance() {
	sort(vectorToBeSorted.begin(), vectorToBeSorted.end(), Sort::auxSortbyDistance);
	user->setServices(vectorToBeSorted);
}

void SortServicesController::sortByPrice() {
	sort(vectorToBeSorted.begin(), vectorToBeSorted.end(), Sort::auxSortbyPrice);
	user->setServices(vectorToBeSorted);
}

