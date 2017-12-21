/*
 * PayServiceController.cpp
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#include "PayServiceController.h"

PayServiceController::PayServiceController(Client *user, unsigned int serviceID,
		Company *company) {
	this->theView = new PayServiceView;
	v = new Validation();
	u = new Utilities();
	this->user = user;
	this->serviceID = serviceID;
	this->company = company;

	
	amountToPay = user->getServiceById(serviceID).getPrice();
	creditCardNumber = 0;
}

PayServiceController::~PayServiceController() {
	// TODO Auto-generated destructor stub
}

void PayServiceController::menu() {
	if (dynamic_cast<Business*>(user)) {
		if (serviceID == -1) {
			theView->printPayEOM();
			payEOM();
			newListServicesMenu();
		} else {
			theView->printPayMenuBusiness();
			payMenuBusiness();
			newServiceMenu();
		}
	} else {
		theView->printPayMenuNormal();
		payMenu();
		if (dynamic_cast<Personal*>(user)) {
			newServiceMenu();
		} else {
			newEnterController();
		}
	}
}

void PayServiceController::payEOM() {
	getAmountToPay();
	if (amountToPay == 0) {
		theView->printNoEOMLeftToPay();
	} else {
		company->payAllDues(user);
		theView->printPayMenuBusiness();
		payMenuBusiness();
	}
}

void PayServiceController::payMenu() {
	theView->printEnterOption();
	int option = getMenuOption(1, 2);
	switch (option) {
	case 1:
		payBankTransfer();
		break;
	case 2:
		payMoneyTransfer();
		break;
	default:
		payMenu();
		break;
	}
}

void PayServiceController::payMenuBusiness() {
	theView->printEnterOption();
	int option = getMenuOption(1, 3);
	switch (option) {
	case 1:
		payBankTransfer();
		break;
	case 2:
		payMoneyTransfer();
		break;
	case 3:
		payCreditCard();
		break;
	default:
		payMenu();
		break;
	}
}

void PayServiceController::payBankTransfer() {
	theView->printEntity(company->getEntity());
	theView->printReference(company->getReference());
	theView->printAmountToPay(amountToPay);
	

}

void PayServiceController::payMoneyTransfer() {
	theView->printNIB(company->getNib());
	theView->printAmountToPay(amountToPay);
}

void PayServiceController::payCreditCard() {
	theView->printAmountToPay(amountToPay);
	creditCardNumber = getCreditCardNumber();
}

unsigned long PayServiceController::getCreditCardNumber() {
	unsigned int creditCardNumber;
	theView->printEnterCreditCardNumber();
	theView->getInfo(creditCardNumber);
	return creditCardNumber;
}

double PayServiceController::getAmountToPay() {
	return amountToPay;
	
}

int PayServiceController::getMenuOption(const int lowerBound,
		const int upperBound) {
	unsigned int option;
	bool flag = false;
	while (!flag) {
		theView->getInfo(option);
		if (!(flag = v->validateBound(option, lowerBound, upperBound))) {
			theView->printWrongOption();
		}
	}
	return option;
}

void PayServiceController::newListServicesMenu() {
	ListServicesController *listServicesController = new ListServicesController(
			user, company);
	listServicesController->menu();
}

void PayServiceController::newEnterController() {
	EnterController *enterController = new EnterController(company);
	enterController->menu();
}

void PayServiceController::newServiceMenu() {
	ServiceMenuController *serviceMenuController = new ServiceMenuController(
			user, company);
	serviceMenuController->menu();
}
