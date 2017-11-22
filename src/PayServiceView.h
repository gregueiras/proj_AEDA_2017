/*
 * PayServiceView.h
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#ifndef SRC_VIEW_HEADERS_PAYSERVICEVIEW_H_
#define SRC_VIEW_HEADERS_PAYSERVICEVIEW_H_

#include "Utilities.h"

class PayServiceView {
private:
	Utilities *u;
	const string initialMessage = "Pagar Serviço";
	const string payMenu = "\n1->multibanco\n2->transferencia bancaria";

	const string getBackNormal = "\n3->voltar atras\n0->SAIR";
	const string getBackBusiness =
			"\n3->cartao de credito\n4->voltar atras\n0->SAIR";
	const string amountToPay = "\nMontante a pagar ->";

	const string enterOption = "Introduza a sua opção";
	const string wrongOption = "Introduziu opção errada";
	const string end = "\nTerminou Pagar Serviço";
	void printMessage(const string &message);

public:
	PayServiceView();
	virtual ~PayServiceView();

	void printInitialMessage();
	void printPayMenu();

	void printGetBackNormal();
	void printBackBusiness();
	void printAmountToPay();

	void printEnterOption();
	void printWrongOption();
	void printEnd();

	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool PayServiceView::getInfo(T &info) {
	return u->readString(info);
}

#endif /* SRC_VIEW_HEADERS_PAYSERVICEVIEW_H_ */
