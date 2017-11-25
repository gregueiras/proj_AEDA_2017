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

	/**
	 * user interaction method to decide which criteria to filter for
	 */
	void filterServicesHandler();

	/**
	 * read the menu option from the keyboard the value of arrival_date
	 * Date of arrival
	 * @param lowerBound lower bound of the menu option
	 * @param upperBound upper bound of the menu option
	 */
	int getMenuOption(const int lowerBound, const int upperBound);

	/**
	 * user interaction method to read time interval information
	 */
	void getTimeInterval();

	/**
	 * user interaction method to read date infomation
	 */
	void getDateInfo(unsigned int& day, unsigned int& month,
			unsigned int& year);

	/**
	 * user interaction method to read id interval information
	 */
	void getIDInterval();

	/**
	 * user interaction method to read volume interval information
	 */
	void getVolumeInterval();

	/**
	 * user interaction method to read price interval information
	 */
	void getPriceInterval();

	/**
	 * user interaction method to read distance interval information
	 */
	void getDistanceInterval();

	/**
	 * user interaction method to read city infomation
	 */
	void getCity();

	/**
	 * narrow services upper method
	 */
	void narrowServices();

	/**
	 * narrow services by id
	 * @param service current service
	 */
	void narrowServicesByID(Services *service);

	/**
	 * narrow services by id
	 * @param service current service
	 * @param distinctFill marks diference if has info according to the criteria or not
	 */
	void narrowServicesByDateInterval(Services &service, bool distinctFill);

	/**
	 * narrow services by id
	 * @param service current service
	 * @param distinctFill marks diference if has info according to the criteria or not
	 */
	void narrowServicesByVolumeInterval(Services &service, bool distinctFill);

	/**
	 * narrow services by id
	 * @param service current service
	 * @param distinctFill marks diference if has info according to the criteria or not
	 */
	void narrowServicesByDistanceInterval(Services &service, bool distinctFill);

	/**
	 * narrow services by id
	 * @param service current service
	 * @param distinctFill marks diference if has info according to the criteria or not
	 */
	void narrowServicesByPriceInterval(Services &service, bool distinctFill);

	/**
	 * narrow services by id
	 * @param service current service
	 * @param distinctFill marks diference if has info according to the criteria or not
	 */
	void narrowServicesByCity(Services &service, bool distinctFill);

	/**
	 * sets visibility of service
	 * @param service current service
	 * @param distinctFill marks diference if has info according to the criteria or not
	 */
	void setVisibility(Services &service, bool distinctFill);

	/**
	 * end program
	 */
	void endProgram();

	/**
	 * opens new list services menu
	 */
	void newListServicesMenu();

public:
	/**
	 * Contructor that initalizes all variables
	 * @param client log in user
	 * @param company pointer to the company object
	 */
	FilterServicesController(Client *client, Company *company);

	/**
	 * destructor
	 */
	virtual ~FilterServicesController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};

#endif /* SRC_CONTROLLER_HEADERS_FILTERSERVICESCONTROLLER_H_ */
