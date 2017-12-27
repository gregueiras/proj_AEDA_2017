/*
 * PayServiceController.h
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#ifndef SRC_CONTROLLER_HEADERS_PAYSERVICECONTROLLER_H_
#define SRC_CONTROLLER_HEADERS_PAYSERVICECONTROLLER_H_

#include <iostream>
#include "PayServiceView.h"
#include "ListServicesController.h"

using namespace std;

class PayServiceController {
private:
	PayServiceView *theView;
	Validation *v;
	Utilities *u;
	Client *user;
	Company *company;
	int serviceID;
	double amountToPay;
	unsigned long creditCardNumber;

	/**
	 * user interaction method to pay by end of the month
	 */
	void payEOM();

	/**
	 * user interaction method to read normal user option
	 */
	void payMenu();

	/**
	 * user interaction method to read business user option
	 */
	void payMenuBusiness();

	/**
	 * user interaction method to pay by bank trasfer
	 */
	void payBankTransfer();

	/**
	 * user interaction method to pay by money transfer
	 */
	void payMoneyTransfer();

	/**
	 * user interaction method to pay by credit car
	 */
	void payCreditCard();

	/**
	 * sets service as paid
	 */
	void setServicePaid();

	/**
	 * method that calculates the amount to pay
	 */
	double getAmountToPay();

	/**
	 * user interaction method to read volume infomation
	 */
	unsigned long getCreditCardNumber();

	void setUserActive();

	/**
	 * read the menu option from the keyboard the value of arrival_date
	 * Date of arrival
	 * @param lowerBound lower bound of the menu option
	 * @param upperBound upper bound of the menu option
	 */
	int getMenuOption(const int lowerBound, const int upperBound);

	/**
	 * opens new service menu
	 */
	void newServiceMenu();

	/**
	 * opens new list services menu
	 */
	void newListServicesMenu();

	/**
	 * opens new enter menu
	 */
	void newEnterMenu();

public:
	/**
	 * Contructor that initalizes all variables
	 * @param client log in user
	 * @param serviceID chosen service id
	 * @param company pointer to the company object
	 */
	PayServiceController(Client *client, unsigned int serviceID,
			Company *company);

	/**
	 * destructor
	 */
	virtual ~PayServiceController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};

#endif /* SRC_CONTROLLER_HEADERS_PAYSERVICECONTROLLER_H_ */
