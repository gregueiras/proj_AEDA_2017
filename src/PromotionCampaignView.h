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
	const string initialMessage = "Definir Campanha Promocional";
	const string enterDiscountPercentage = "Introduza a percentagem de desconto";
	const string previousPromotionalCampaignEnded =
			"Campanha Promocional anteriormente em  vigor terminada";
	const string end = "Terminou Definir Campanha Promocional";
	const string wrongPercentage = "Percentagem introduzida inv�lida";
	const string shutdown = "\nPrograma terminou";

	void printMessage(const string &message);
public:
	PromotionCampaignView();
	virtual ~PromotionCampaignView();

	void printInitialMessage();

	void printEnterDiscountPercentage();

	void printPreviousPromotionalCampaignEnded();
	void printShutdown();
	void printWrongPercentage();
	void printEnd();

	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool PromotionCampaignView::getInfo(T &info) {
	return u->readString(info);
}
#endif /* SRC_PROMOTIONCAMPAIGNVIEW_H_ */
