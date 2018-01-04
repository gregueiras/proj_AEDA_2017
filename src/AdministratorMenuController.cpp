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
		option = getMenuOption(0, 5);
		switch (option) {
		case 0:
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
			newAdvanceTime();
			break;
		case 5:

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
	theView->printEnd();
	SeeServicesController *seeServiceController = new SeeServicesController(
			company);
	seeServiceController->menu();
}

void AdministratorMenuController::newPromotionalCampaign() {
	theView->printEnd();
	PromotionCampaignController *promotionCampaignController =
			new PromotionCampaignController(company);
	promotionCampaignController->menu();
}

void AdministratorMenuController::newVehiclesMenu() {
	theView->printEnd();
	VehicleMenuController *vehicleMenuController = new VehicleMenuController(
			company);
	vehicleMenuController->menu();
}

void AdministratorMenuController::newAdvanceTime() {
	theView->printEnd();
	AdvanceTimeController *advanceTimeController = new AdvanceTimeController(
			company);
	advanceTimeController->menu();
}

void AdministratorMenuController::newEnterController() {
	theView->printEnd();
	EnterController *enterController = new EnterController(company);
	enterController->menu();
}

void AdministratorMenuController::endProgram() {
	theView->printEnd();
	theView->printShutdown();
	company->writeCompanyToFile();
	company->writeClientsToFile();
	company->writeVehiclesToFile();
	exit(0);
}
