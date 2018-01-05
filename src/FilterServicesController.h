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
#include "ServiceMenuController.h"
#include "Company.h"

class FilterServicesController {
private:
	FilterServicesView *theView;
	Validation *v;
	Utilities *u;
	Client *client;
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
	 * user interaction method to read day inferior bound information
	 * @return the day inferior bound
	 */
	unsigned int getDayInferiorBound();

	/**
	 * user interaction method to read month inferior bound information
	 * @return the month inferior bound
	 */
	unsigned int getMonthInferiorBound();

	/**
	 * user interaction method to read year inferior bound information
	 * @return the id inferior bound
	 */
	unsigned int getYearInferiorBound();

	/**
	 * user interaction method to read day superior bound information
	 * @return the year superior bound
	 */
	unsigned int getDaySuperiorBound();

	/**
	 * user interaction method to read month superior bound information
	 * @return the month superior bound
	 */
	unsigned int getMonthSuperiorBound();

	/**
	 * user interaction method to read year superior bound information
	 * @return the year superior bound
	 */
	unsigned int getYearSuperiorBound();

	/**
	 * user interaction method to read id interval information
	 */
	void getIDInterval();

	/**
	 * user interaction method to read id inferior bound information
	 * @return the id inferior bound
	 */
	unsigned int getIDInferiorBound();

	/**
	 * user interaction method to read id superior bound information
	 * @return the id superior bound
	 */
	unsigned int getIDSuperiorBound();

	/**
	 * user interaction method to read volume interval information
	 */
	void getVolumeInterval();

	/**
	 * user interaction method to read volume inferior bound information
	 * @return the volume inferior bound
	 */
	unsigned long getVolumeInferiorBound();

	/**
	 * user interaction method to read volume superior bound information
	 * @return the volume superior bound
	 */
	unsigned long getVolumeSuperiorBound();

	/**
	 * user interaction method to read price interval information
	 */
	void getPriceInterval();

	/**
	 * user interaction method to read price inferior bound information
	 * @return the price inferior bound
	 */
	unsigned long getPriceInferiorBound();

	/**
	 * user interaction method to read price superior bound information
	 * @return the price superior bound
	 */
	unsigned long getPriceSuperiorBound();

	/**
	 * user interaction method to read distance interval information
	 */
	void getDistanceInterval();

	/**
	 * user interaction method to read distance inferior bound information
	 * @return the distance inferior bound
	 */
	unsigned long getDistanceInferiorBound();

	/**
	 * user interaction method to read distance superior bound information
	 * @return the distance superior bound
	 */
	unsigned long getDistanceSuperiorBound();

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
	void newServiceMenu();

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
