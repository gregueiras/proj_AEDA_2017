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
		option = getMenuOption(0, 11);
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
			newEnterMenu();
			break;
		default:
			newEnterMenu();
			break;
		}
	} while (option != 11);
}

int AdministratorMenuController::getMenuOption(const int lowerBound,
		const int upperBound) {
	int option;
	bool flag = false;
	while (!flag) {
		theView->getInfo(option);
		if (!(flag = v->validateBound(option, lowerBound, upperBound))) {
			theView->printWrongOption();
		}
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

void AdministratorMenuController::newEnterMenu() {
	EnterController *enterController = new EnterController(company);
	enterController->menu();
}

void AdministratorMenuController::endProgram() {
}
