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

	/**
	 * method to change campaign promotion percentage
	 */
	void promotionCampaignHandler();

	/**
	 * user interaction method to read promotion campaign percentage
	 * @return the promotion campaign percentage
	 */
	float getPromotionCampaignPercentage();

	/**
	 * opens new administrator menu
	 */
	void newAdministratorMenu();

public:
	/**
	 * Contructor that initalizes all variables
	 * @param company pointer to the company object
	 */
	PromotionCampaignController(Company *company);

	/**
	 * destructor
	 */
	virtual ~PromotionCampaignController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();

};

#endif /* SRC_PROMOTIONCAMPAIGNCONTROLLER_H_ */
