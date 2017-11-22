/*
 * FilterServicesController.h
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#ifndef SRC_CONTROLLER_HEADERS_FILTERSERVICESCONTROLLER_H_
#define SRC_CONTROLLER_HEADERS_FILTERSERVICESCONTROLLER_H_

#include  "Validation.h"
#include "FilterServicesView.h"
#include "ListServicesController.h"
#include "Company.h"

class FilterServicesController {
private:
	FilterServicesView *theView;
	Validation *v;
	Utilities *u;
	Client *user;
	Company *company;

	unsigned int idInferiorBound, idSuperiorBound, dayInferiorBound,
			daySuperiorBound, monthInferiorBound, monthSuperiorBound,
			yearInferiorBound, yearSuperiorBound;
	unsigned long distanceInferiorBound, distanceSuperiorBound,
			priceInferiorBound, priceSuperiorBound, volumeInferiorBound,
			volumeSuperiorBound;
	string city;

	Date *dateInferiorBound, *dateSuperiorBound;

	void filterServices();
	void filterServicesHandler();
	int getMenuOption(const int lowerBound, const int upperBound);

	void getTimeInterval();
	void getDateInfo(unsigned int& day, unsigned int& month,
			unsigned int& year);

	void getIDInterval();
	void getVolumeInterval();
	void getPriceInterval();
	void getDistanceInterval();
	void getCity();

	void narrowServices();
	void narrowServicesByID(Services *service);
	void narrowServicesByDateInterval(Services &service, bool distinctFill);
	void narrowServicesByVolumeInterval(Services &service, bool distinctFill);
	void narrowServicesByDistanceInterval(Services &service, bool distinctFill);
	void narrowServicesByPriceInterval(Services &service, bool distinctFill);
	void narrowServicesByCity(Services &service, bool distinctFill);
	void setVisibility(Services &service, bool distinctFill);

	void endProgram();
	void newListServicesMenu();

	template<typename T> void getInfo(T &info);
	template<typename T> void getInterval(T &inferiorBound, T &superiorBound);

public:
	FilterServicesController(Client *client, Company *company);
	virtual ~FilterServicesController();
	void menu();
};

template<typename T>
void FilterServicesController::getInterval(T &inferiorBound, T &superiorBound) {
	getInfo(inferiorBound);
	getInfo(superiorBound);
}

template<typename T>
void FilterServicesController::getInfo(T& info) {
	if (!theView->getInfo(info)) { //ctrlz, fim do ficheiro
		theView->printEnd();
		newListServicesMenu();
	}
}

#endif /* SRC_CONTROLLER_HEADERS_FILTERSERVICESCONTROLLER_H_ */
