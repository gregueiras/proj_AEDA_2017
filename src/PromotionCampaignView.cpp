/*
 * PromotionCampaignView.cpp
 *
 *  Created on: 26 Dec 2017
 *      Author: jotaa
 */

#include "PromotionCampaignView.h"

PromotionCampaignView::PromotionCampaignView() {
	u = new Utilities();
}

PromotionCampaignView::~PromotionCampaignView() {
	// TODO Auto-generated destructor stub
}

void PromotionCampaignView::printMessage(const string& message) {
	cout << message << endl;
}

void PromotionCampaignView::printInitialMessage() {
	printMessage(initialMessage);
}

void PromotionCampaignView::printEnterDiscountPercentage() {
	printMessage(enterDiscountPercentage);
}

void PromotionCampaignView::printShutdown() {
	printMessage(shutdown);
}

void PromotionCampaignView::printWrongPercentage() {
	printMessage(wrongPercentage);
}

void PromotionCampaignView::printEnd() {
	printMessage(end);
}

void PromotionCampaignView::printPreviousPromotionalCampaignEnded() {
	printMessage(previousPromotionalCampaignEnded);
}
