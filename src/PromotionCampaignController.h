/*
 * PromotionCampaignController.h
 *
 *  Created on: 26 Dec 2017
 *      Author: jotaa
 */

#ifndef SRC_PROMOTIONCAMPAIGNCONTROLLER_H_
#define SRC_PROMOTIONCAMPAIGNCONTROLLER_H_

#include "Company.h"
#include "PromotionCampaignView.h"
#include "AdministratorMenuController.h"
#include "Validation.h"

class PromotionCampaignController {
private:
	PromotionCampaignView *theView;
	Company *company;
	Utilities *u;
	Validation *v;
	float discountPercentage;

public:
	PromotionCampaignController(Company *company);

	virtual ~PromotionCampaignController();

	void menu();

	void newAdministratorMenu();

};

#endif /* SRC_PROMOTIONCAMPAIGNCONTROLLER_H_ */
