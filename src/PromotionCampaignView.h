/*
 * PromotionCampaignView.h
 *
 *  Created on: 26 Dec 2017
 *      Author: jotaa
 */

#ifndef SRC_PROMOTIONCAMPAIGNVIEW_H_
#define SRC_PROMOTIONCAMPAIGNVIEW_H_

#include <iostream>
#include "Utilities.h"

using namespace std;

class PromotionCampaignView {

private:
	Utilities *u;
	const string initialMessage = "\nDefinir Campanha Promocional";
	const string enterDiscountPercentage = "Introduza a percentagem de desconto";
	const string wrongPercentage = "Percentagem introduzida inválida";
	const string companyDiscountPercentage =
			"Percentagem de desconto da atual campanha promocional: ";
	const string previousPromotionalCampaignEnded =
			"Campanha Promocional anteriormente em  vigor terminada";
	const string end = "Terminou Definir Campanha Promocional";
	const string shutdown = "\nPrograma terminou";

	void printMessage(const string &message);
public:
	PromotionCampaignView();
	virtual ~PromotionCampaignView();

	/**
	 * prints initial message
	 */
	void printInitialMessage();

	/**
	 * prints company discount percentage
	 */
	void printCompanyDiscountPercentage(const float discount);

	/**
	 * prints enter discount percentage message
	 */
	void printEnterDiscountPercentage();

	/**
	 * prints previous promotion campaign ended message
	 */
	void printPreviousPromotionalCampaignEnded();

	/**
	 * prints shutdown message
	 */
	void printShutdown();

	/**
	 * prints wrong percentage message
	 */
	void printWrongPercentage();

	/**
	 * prints end message
	 */
	void printEnd();

	/**
	 * reads string from keyboard
	 */
	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool PromotionCampaignView::getInfo(T &info) {
	return u->readString(info);
}
#endif /* SRC_PROMOTIONCAMPAIGNVIEW_H_ */
