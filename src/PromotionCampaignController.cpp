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
}

PromotionCampaignController::~PromotionCampaignController() {
}

void PromotionCampaignController::menu() {
	promotionCampaignHandler();
	newAdministratorMenu();
}

void PromotionCampaignController::promotionCampaignHandler() {
	company->setDiscount(getPromotionCampaignPercentage());
}

float PromotionCampaignController::getPromotionCampaignPercentage() {
	float discountPercentage;
	bool flag;
	theView->printInitialMessage();
	theView->printCompanyDiscountPercentage(company->getDiscount());
	do {
		theView->printEnterDiscountPercentage();
		flag = theView->getInfo(discountPercentage);
		if (flag == false) {
			theView->printWrongPercentage();
		}
	} while (!flag);
	return discountPercentage;
}

void PromotionCampaignController::newAdministratorMenu() {
	theView->printEnd();
	AdministratorMenuController *administratorMenu =
			new AdministratorMenuController(company);
	administratorMenu->menu();
}
