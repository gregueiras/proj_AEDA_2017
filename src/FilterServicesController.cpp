/*
 * FilterServicesController.cpp
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#include "FilterServicesController.h"

FilterServicesController::FilterServicesController(Client *user,
		Company *company) {
	this->theView = new FilterServicesView;
	this->company = company;
	v = new Validation();
	u = new Utilities();
	dateInferiorBound = new Date(0, 0, 0);
	dateSuperiorBound = new Date(0, 0, 0);
	this->user = user;
	idInferiorBound = 0;
	idSuperiorBound = 0;
	dayInferiorBound = 0;
	daySuperiorBound = 0;
	monthInferiorBound = 0;
	monthSuperiorBound = 0;
	yearInferiorBound = 0;
	yearSuperiorBound = 0;
	distanceInferiorBound = 0;
	distanceSuperiorBound = 0;
	priceInferiorBound = 0;
	priceSuperiorBound = 0;
	volumeInferiorBound = 0;
	volumeSuperiorBound = 0;
	string city = "";
}
FilterServicesController::~FilterServicesController() {
	// TODO Auto-generated destructor stub
}

void FilterServicesController::menu() {
	filterServicesHandler();
	newListServicesMenu();
}

void FilterServicesController::filterServicesHandler() {
	int option;
	theView->printFilterMenu();
	do {
		theView->printEnterOption();
		option = getMenuOption(0, 8);
		switch (option) {
		case 0:
			theView->printShutdown();
			endProgram();
			break;
		case 1:
			getIDInterval();
			break;
		case 2:
			getTimeInterval();
			break;
		case 3:
			getVolumeInterval();
			break;
		case 4:
			getDistanceInterval();
			break;
		case 5:
			getPriceInterval();
			break;
		case 6:
			getCity();
			break;
		case 7:
			narrowServices();
			break;
		case 8:
			newListServicesMenu();
			break;
		}
	} while (option == -1);
}

int FilterServicesController::getMenuOption(const int lowerBound,
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

void FilterServicesController::getTimeInterval() {
	theView->printEnterDateInferiorBound();
	getDateInfo(dayInferiorBound, monthInferiorBound, yearInferiorBound);
	theView->printEnterDateSuperiorBound();
	getDateInfo(daySuperiorBound, monthSuperiorBound, yearSuperiorBound);
	dateInferiorBound->setDay(dayInferiorBound);
	dateInferiorBound->setMonth(monthInferiorBound);
	dateInferiorBound->setYear(yearInferiorBound);
	dateInferiorBound->setDay(daySuperiorBound);
	dateInferiorBound->setMonth(monthSuperiorBound);
	dateInferiorBound->setYear(yearSuperiorBound);
}

void FilterServicesController::getDateInfo(unsigned int& day,
		unsigned int& month, unsigned int& year) {
	theView->getInfo(day);
	theView->getInfo(month);
	theView->getInfo(year);
}

void FilterServicesController::getIDInterval() {
	theView->printEnterIdInterval();
	theView->getInfo(idInferiorBound);
	theView->getInfo(idSuperiorBound);
}
void FilterServicesController::getVolumeInterval() {
	theView->printEnterVolumeInterval();
	theView->getInfo(volumeInferiorBound);
	theView->getInfo(volumeSuperiorBound);
}

void FilterServicesController::getPriceInterval() {
	theView->printEnterPriceInterval();
	theView->getInfo(priceInferiorBound);
	theView->getInfo(priceSuperiorBound);
}

void FilterServicesController::getDistanceInterval() {
	theView->printEnterDistanceInterval();
	theView->getInfo(distanceInferiorBound);
	theView->getInfo(distanceSuperiorBound);
}

void FilterServicesController::getCity() {
	theView->printEnterCity();
	theView->getInfo(city);
}

void FilterServicesController::narrowServices() {
	for (size_t i = 0; i < user->getServices().size(); i++) {
		Services *service = user->getServices().at(i);
		//service.setVisibility(true);
		narrowServicesByID(service);
	}
}

void FilterServicesController::narrowServicesByID(Services *service) {
	if (idInferiorBound == 0 && idSuperiorBound == 0) {
		narrowServicesByDateInterval(*service, true);
	} else {
		if (service->getId() >= idInferiorBound
				&& service->getId() <= idSuperiorBound) {
			narrowServicesByDateInterval(*service, true);
		} else {
			narrowServicesByDateInterval(*service, false);
		}
	}
}

void FilterServicesController::narrowServicesByDateInterval(Services &service,
		bool distinctFill) {
	if (dateInferiorBound->getYear() == 0
			&& dateSuperiorBound->getYear() == 0) {
		narrowServicesByVolumeInterval(service, distinctFill);
	} else {
		if (service.isBetweenDates(*dateInferiorBound, *dateSuperiorBound)) {
			narrowServicesByVolumeInterval(service, true);
		} else {
			narrowServicesByVolumeInterval(service, false);
		}
	}
}

void FilterServicesController::narrowServicesByVolumeInterval(Services &service,
		bool distinctFill) {
	if (volumeInferiorBound == 0 && volumeSuperiorBound == 0) {
		narrowServicesByDistanceInterval(service, distinctFill);
	} else {
		if (service.isBetweenVolume(volumeInferiorBound, volumeSuperiorBound)) {
			narrowServicesByDistanceInterval(service, true);
		} else {
			narrowServicesByDistanceInterval(service, false);
		}
	}
}

void FilterServicesController::narrowServicesByDistanceInterval(
		Services &service, bool distinctFill) {
	if (distanceInferiorBound == 0 && distanceSuperiorBound == 0) {
		narrowServicesByPriceInterval(service, distinctFill);
	} else {
		if (service.isBetweenDistance(distanceInferiorBound,
				distanceSuperiorBound)) {
			narrowServicesByPriceInterval(service, true);
		} else {
			narrowServicesByPriceInterval(service, false);
		}
	}
}

void FilterServicesController::narrowServicesByPriceInterval(Services &service,
		bool distinctFill) {
	if (priceInferiorBound == 0 && priceSuperiorBound == 0) {
		narrowServicesByCity(service, distinctFill);
	} else {
		if (service.isBetweenPrice(priceInferiorBound, priceSuperiorBound)) {
			narrowServicesByCity(service, true);
		} else {
			narrowServicesByCity(service, false);
		}
	}
}
void FilterServicesController::narrowServicesByCity(Services &service,
		bool distinctFill) {
	if (city == "") {
		setVisibility(service, distinctFill);
	} else {
		if (service.getOrigin_address().getCity() == city
				|| service.getDestination_address().getCity() == city) {
			setVisibility(service, true);
		} else {
			setVisibility(service, false);
		}
	}
}
void FilterServicesController::setVisibility(Services &service,
		bool distinctFill) {
	if (distinctFill) {
		service.setVisibility(true);
	} else {
		service.setVisibility(false);
	}
}

void FilterServicesController::endProgram() {
}

void FilterServicesController::newListServicesMenu() {
	ListServicesController *listServicesController = new ListServicesController(
			user, company);
	listServicesController->menu();
}

