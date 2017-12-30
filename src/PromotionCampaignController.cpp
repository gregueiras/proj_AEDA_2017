/*
 * PromotionCampaignController.cpp
 *
 *  Created on: 26 Dec 2017
 *      Author: jotaa
 */

#include "PromotionCampaignController.h"

PromotionCampaignController::PromotionCampaignController(Company *company) {
	this->company = company;
	this->theView = new PromotionCampaignView();
	this->u = new Utilities();
	this->v = new Validation();
	discountPercentage = 0;
}

PromotionCampaignController::~PromotionCampaignController() {
}

void PromotionCampaignController::menu() {
	theView->printInitialMessage();
	theView->printCompanyDiscountPercentage(company->getDiscount());
	theView->printEnterDiscountPercentage();
	if (theView->getInfo(discountPercentage) == true) {
		company->setDiscount(discountPercentage);
	}
	newAdministratorMenu();
}

void PromotionCampaignController::newAdministratorMenu() {
	AdministratorMenuController *administratorMenu =
			new AdministratorMenuController(company);
	administratorMenu->menu();
}
