/*
 * PayServiceController.cpp
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#include "PayServiceController.h"

PayServiceController::PayServiceController(Client *client, Services *service,
		Company *company) {
	this->theView = new PayServiceView;
	v = new Validation();
	u = new Utilities();
	this->client = client;
	this->service = service;
	this->company = company;
	amountToPay = 0;
	creditCardNumber = 0;
}

PayServiceController::~PayServiceController() {
	// TODO Auto-generated destructor stub
}

void PayServiceController::menu() {
	if (dynamic_cast<Business*>(client)) {
		if (service == NULL) {
			theView->printPayEOM();
			payEOM();
			setUserActive();
			newServiceMenu();
		} else {
			theView->printPayMenuBusiness();
			amountToPay = getAmountToPay();
			payMenuBusiness();
			setServicePaid();
			setUserActive();
			newServiceMenu();
		}
	} else {
		theView->printPayMenu();
		amountToPay = getAmountToPay();
		payMenu();
		setServicePaid();
		if (dynamic_cast<Personal*>(client)) {
			setUserActive();
			newServiceMenu();
		} else {
			newEnterMenu();
		}
	}
}

double PayServiceController::getAmountToPay() {
	return service->getPrice();
}

void PayServiceController::payEOM() {
	if (company->checkAllDues(client, amountToPay) == false) {
		theView->printNoEOMLeftToPay();
	} else {
		theView->printPayMenuBusiness();
		payMenuBusiness();
		company->payAllDues(client);
	}
}

void PayServiceController::payMenuBusiness() {
	int option;
	do {
		theView->printEnterOption();
		option = getMenuOption(1, 3);
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
		}
	} while (option == -1);
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
//-----------------------------
void PayServiceController::setServicePaid() {
	int payment_id = client->getPaymentId(service->getId());
	if (payment_id != 0) {
		company->getPayment(payment_id).setDue(false);
	}
}
//--------------------
unsigned long PayServiceController::getCreditCardNumber() {
	unsigned long creditCardNumber;
	bool flag;
	do {
		theView->printEnterCreditCardNumber();
		flag = theView->getInfo(creditCardNumber);
		if (flag == false) {
			theView->printInvalidCreditCardNumber();
		}
	} while (flag == false);
	return creditCardNumber;
}

void PayServiceController::setUserActive() {
	if (client->getVisibility() == false) {
		company->activateClientRecord(client);
	}
}

int PayServiceController::getMenuOption(const int lowerBound,
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

void PayServiceController::newServiceMenu() {
	theView->printEnd();
	ServiceMenuController *serviceMenuController = new ServiceMenuController(
			client, company);
	serviceMenuController->menu();
}

void PayServiceController::newEnterMenu() {
	theView->printEnd();
	EnterController *enterController = new EnterController(company);
	enterController->menu();
}
