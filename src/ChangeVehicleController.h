/*
 * ChangeVehicleController.h
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#ifndef SRC_CHANGEVEHICLECONTROLLER_H_
#define SRC_CHANGEVEHICLECONTROLLER_H_

#include "Company.h"
#include "VehicleMenuView.h"
#include "VehicleMenuController.h"
#include "ChangeVehicleView.h"

class ChangeVehicleController {
private:
	ChangeVehicleView *theView;
	Validation *v;
	Company *company;
	string plate;

	/**
	 * read the menu option from the keyboard the value of arrival_date
	 * Date of arrival
	 * @param lowerBound lower bound of the menu option
	 * @param upperBound upper bound of the menu option
	 */
	int getMenuOption(const int lowerBound, const int upperBound);

	/**
	 * user interaction method to read plate information
	 * @return the plate
	 */
	string getPlate();

	/**
	 * user interaction method to read brand information
	 * @return the brand
	 */
	string getBrand();

	/**
	 * user interaction method to read model information
	 * @return the model
	 */
	string getModel();

	/**
	 * user interaction method to read birthday date information
	 * @return the  birthday date
	 */
	Date* getBirthdayDate();

	/**
	 * user interaction method to read expectable time information
	 * @return the expectable time
	 */
	Hour* getExpectableTime();

	/**
	 * user interaction method to read maintenance date information
	 * @return the maintenance date
	 */
	Date* getMaintenanceDate();

	/**
	 * user interaction method to change plate
	 */
	void changePlate();

	/**
	 * user interaction method to change brande
	 */
	void changeBrand();

	/**
	 * user interaction method to change model
	 */
	void changeModel();

	/**
	 * user interaction method to change birthday date
	 */
	void changeBirthdayDate();

	/**
	 * user interaction method to change expectable time
	 */
	void changeExpectableTime();

	/**
	 * user interaction method to change maintenance date
	 */
	void changeMaintenanceDate();

	/**
	 * end program
	 */
	void endProgram();

	/**
	 * opens new vehicle menu
	 */
	void newVehicleMenuController();
public:
	/**
	 * Contructor that initalizes all variables
	 * @param company pointer to the company object
	 * @param plate vehicle plate
	 */
	ChangeVehicleController(Company *company, string plate);

	/**
	 * destructor
	 */
	virtual ~ChangeVehicleController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};

#endif /* SRC_CHANGEVEHICLECONTROLLER_H_ */
