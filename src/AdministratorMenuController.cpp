/*
 * AdministratorMenuController.cpp
 *
 *  Created on: 25 Dec 2017
 *      Author: jotaa
 */

#include "AdministratorMenuController.h"

AdministratorMenuController::AdministratorMenuController(Company *company) {
	this->company = company;
	this->u = new Utilities();
	this->v = new Validation();
	this->theView = new AdministratorMenuView();
}

AdministratorMenuController::~AdministratorMenuController() {
	// TODO Auto-generated destructor stub
}

void AdministratorMenuController::menu() {
	int option;
	do {
		theView->printAdministratorMenu();
		theView->printEnterOption();
		option = getMenuOption(0, 4);
		switch (option) {
		case 0:
			theView->printShutdown();
			endProgram();
			break;
		case 1:
			newSeeServices();
			break;
		case 2:
			newPromotionalCampaign();
			break;
		case 3:
			newVehiclesMenu();
			break;
		case 4:
			newEnterController();
			break;
		}
	} while (option != 0);
}

int AdministratorMenuController::getMenuOption(const int lowerBound,
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

void AdministratorMenuController::newSeeServices() {
	SeeServicesController *seeServiceController = new SeeServicesController(
			company);
	seeServiceController->menu();
}

void AdministratorMenuController::newPromotionalCampaign() {
	PromotionCampaignController *promotionCampaignController =
			new PromotionCampaignController(company);
	promotionCampaignController->menu();
}

void AdministratorMenuController::newVehiclesMenu() {
	VehicleMenuController *vehicleMenuController = new VehicleMenuController(
			company);
	vehicleMenuController->menu();
}

void AdministratorMenuController::newEnterController() {
	EnterController *enterController = new EnterController(company);
	enterController->menu();
}

void AdministratorMenuController::endProgram() {
}
