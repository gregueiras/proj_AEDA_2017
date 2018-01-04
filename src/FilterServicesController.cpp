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
	newServiceMenu();
}

void FilterServicesController::filterServicesHandler() {
	int option;
	do {
		theView->printFilterMenu();
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
			newServiceMenu();
			break;
		}
	} while (option != 0);
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
	theView->printEnterDateInterval();
	theView->printEnterDateInferiorBound();
	theView->printEnterDayInferiorBound();
	dayInferiorBound = getDayInferiorBound();
	if (dayInferiorBound != 0) {
		theView->printEnterMonthInferiorBound();
		monthInferiorBound = getMonthInferiorBound();
		if (monthInferiorBound != 0) {
			theView->printEnterYearInferiorBound();
			yearInferiorBound = getYearInferiorBound();
			if (yearInferiorBound != 0) {
				theView->printEnterDaySuperiorBound();
				daySuperiorBound = getDaySuperiorBound();
				if (daySuperiorBound != 0) {
					theView->printEnterMonthSuperiorBound();
					monthSuperiorBound = getMonthSuperiorBound();
					if (monthSuperiorBound != 0) {
						theView->printEnterYearSuperiorBound();
						yearSuperiorBound = getYearSuperiorBound();
						if (yearSuperiorBound != 0) {
							dateInferiorBound->setDay(dayInferiorBound);
							dateInferiorBound->setMonth(monthInferiorBound);
							dateInferiorBound->setYear(yearInferiorBound);
							dateInferiorBound->setDay(daySuperiorBound);
							dateInferiorBound->setMonth(monthSuperiorBound);
							dateInferiorBound->setYear(yearSuperiorBound);
						}
					}
				}
			}
		}
	}
}

unsigned int FilterServicesController::getDayInferiorBound() {
	unsigned int dayInferiorBound = 0;
	bool flag1;
	do {
		theView->printEnterDayInferiorBound();
		flag1 = theView->getInfo(dayInferiorBound);
		if (flag1 == true && dayInferiorBound == 0) {
			return dayInferiorBound;
		}
	} while (flag1 == false);
	return dayInferiorBound;
}

unsigned int FilterServicesController::getMonthInferiorBound() {
	unsigned int monthInferiorBound = 0;
	bool flag1;
	do {
		theView->printEnterMonthInferiorBound();
		flag1 = theView->getInfo(monthInferiorBound);
		if (flag1 == true && monthInferiorBound == 0) {
			return monthInferiorBound;
		}
	} while (flag1 == false);
	return monthInferiorBound;
}

unsigned int FilterServicesController::getYearInferiorBound() {
	unsigned int yearInferiorBound = 0;
	bool flag1;
	do {
		theView->printEnterYearInferiorBound();
		flag1 = theView->getInfo(yearInferiorBound);
		if (flag1 == true && yearInferiorBound == 0) {
			return yearInferiorBound;
		}
	} while (flag1 == false);
	return yearInferiorBound;
}

unsigned int FilterServicesController::getDaySuperiorBound() {
	unsigned int daySuperiorBound = 0;
	bool flag1;
	do {
		theView->printEnterDaySuperiorBound();
		flag1 = theView->getInfo(daySuperiorBound);
		if (flag1 == true && daySuperiorBound == 0) {
			return daySuperiorBound;
		}
	} while (flag1 == false);
	return daySuperiorBound;
}

unsigned int FilterServicesController::getMonthSuperiorBound() {
	unsigned int monthSuperiorBound = 0;
	bool flag1;
	do {
		theView->printEnterMonthSuperiorBound();
		flag1 = theView->getInfo(monthSuperiorBound);
		if (flag1 == true && monthSuperiorBound == 0) {
			return monthSuperiorBound;
		}
	} while (flag1 == false);
	return monthSuperiorBound;
}

unsigned int FilterServicesController::getYearSuperiorBound() {
	unsigned int yearSuperiorBound = 0;
	bool flag1;
	do {
		theView->printEnterYearSuperiorBound();
		flag1 = theView->getInfo(yearSuperiorBound);
		if (flag1 == true && yearSuperiorBound == 0) {
			return yearSuperiorBound;
		}
	} while (flag1 == false);
	return yearSuperiorBound;
}

void FilterServicesController::getIDInterval() {
	theView->printEnterIDInterval();
	idInferiorBound = getIDInferiorBound();
	if (idInferiorBound != 0) {
		idSuperiorBound = getIDSuperiorBound();
		if (idSuperiorBound == 0) {
			idInferiorBound = 0;
		}
	}
}

unsigned int FilterServicesController::getIDInferiorBound() {
	unsigned int idInferiorBound = 0;
	bool flag1;
	do {
		theView->printEnterIDInferiorBound();
		flag1 = theView->getInfo(idInferiorBound);
		if (flag1 == true && idInferiorBound == 0) {
			return idInferiorBound;
		}
	} while (flag1 == false);
	return idInferiorBound;
}

unsigned int FilterServicesController::getIDSuperiorBound() {
	unsigned int idSuperiorBound = 0;
	bool flag1;
	do {
		theView->printEnterIDSuperiorBound();
		flag1 = theView->getInfo(idSuperiorBound);
		if (flag1 == true && idSuperiorBound == 0) {
			return idSuperiorBound;
		}
	} while (flag1 == false);
	return idSuperiorBound;
}

void FilterServicesController::getVolumeInterval() {
	theView->printEnterVolumeInterval();
	volumeInferiorBound = getVolumeInferiorBound();
	if (volumeInferiorBound != 0) {
		volumeSuperiorBound = getVolumeSuperiorBound();
		if (volumeSuperiorBound == 0) {
			volumeInferiorBound = 0;
		}
	}
}

unsigned long FilterServicesController::getVolumeInferiorBound() {
	unsigned long volumeInferiorBound = 0;
	bool flag1;
	do {
		theView->printEnterVolumeInferiorBound();
		flag1 = theView->getInfo(volumeInferiorBound);
		if (flag1 == true && volumeInferiorBound == 0) {
			return volumeInferiorBound;
		}
	} while (flag1 == false);
	return volumeInferiorBound;
}

unsigned long FilterServicesController::getVolumeSuperiorBound() {
	unsigned long idSuperiorBound = 0;
	bool flag1;
	do {
		theView->printEnterVolumeSuperiorBound();
		flag1 = theView->getInfo(idSuperiorBound);
		if (flag1 == true && idSuperiorBound == 0) {
			return idSuperiorBound;
		}
	} while (flag1 == false);
	return idSuperiorBound;
}

void FilterServicesController::getPriceInterval() {
	theView->printEnterPriceInterval();
	priceInferiorBound = getPriceInferiorBound();
	if (priceInferiorBound != 0) {
		priceSuperiorBound = getPriceSuperiorBound();
		if (priceSuperiorBound == 0) {
			priceInferiorBound = 0;
		}
	}
}

unsigned long FilterServicesController::getPriceInferiorBound() {
	unsigned long priceInferiorBound = 0;
	bool flag1;
	do {
		theView->printEnterPriceInferiorBound();
		flag1 = theView->getInfo(priceInferiorBound);
		if (flag1 == true && priceInferiorBound == 0) {
			return priceInferiorBound;
		}
	} while (flag1 == false);
	return priceInferiorBound;
}

unsigned long FilterServicesController::getPriceSuperiorBound() {
	unsigned long priceSuperiorBound = 0;
	bool flag1;
	do {
		theView->printEnterPriceSuperiorBound();
		flag1 = theView->getInfo(priceSuperiorBound);
		if (flag1 == true && priceSuperiorBound == 0) {
			return priceSuperiorBound;
		}
	} while (flag1 == false);
	return priceSuperiorBound;
}

void FilterServicesController::getDistanceInterval() {
	theView->printEnterDistanceInterval();
	distanceInferiorBound = getDistanceInferiorBound();
	if (distanceInferiorBound != 0) {
		distanceSuperiorBound = getDistanceSuperiorBound();
		if (distanceSuperiorBound == 0) {
			distanceInferiorBound = 0;
		}
	}
}

unsigned long FilterServicesController::getDistanceInferiorBound() {
	unsigned long distanceInferiorBound = 0;
	bool flag1;
	do {
		theView->printEnterDistanceInferiorBound();
		flag1 = theView->getInfo(distanceInferiorBound);
		if (flag1 == true && distanceInferiorBound == 0) {
			return distanceInferiorBound;
		}
	} while (flag1 == false);
	return distanceInferiorBound;
}

unsigned long FilterServicesController::getDistanceSuperiorBound() {
	unsigned int distanceSuperiorBound = 0;
	bool flag1;
	do {
		theView->printEnterDistanceSuperiorBound();
		flag1 = theView->getInfo(distanceSuperiorBound);
		if (flag1 == true && distanceSuperiorBound == 0) {
			return distanceSuperiorBound;
		}
	} while (flag1 == false);
	return distanceSuperiorBound;
}

void FilterServicesController::getCity() {
	theView->printEnterCity();
	theView->getInfo(city);
	if (city == "0") {
		city = "";
	}
}

/**
 *
 *
 *
 */
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

void FilterServicesController::newServiceMenu() {
	ServiceMenuController *serviceMenuController = new ServiceMenuController(
			user, company);
	serviceMenuController->menu();
}

