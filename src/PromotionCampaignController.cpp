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
	promotionCampaignHandler();
	newAdministratorMenu();
}

void PromotionCampaignController::promotionCampaignHandler() {
	getPromotionCampaignPercentage();
	company->setDiscount(discountPercentage);
}

float PromotionCampaignController::getPromotionCampaignPercentage() {
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
}

void PromotionCampaignController::newAdministratorMenu() {
	AdministratorMenuController *administratorMenu =
			new AdministratorMenuController(company);
	administratorMenu->menu();
}
