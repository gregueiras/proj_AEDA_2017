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
	const string payMenu =
			"Pagar Servico\n1->multibanco\n2->transferencia bancaria";

	const string payMenuNormal = "\n3->voltar atras\n0->SAIR";
	const string payMenuBusiness =
			"\n3->cartao de credito\n4->voltar atras\n0->SAIR";
	const string amountToPay = "\nMontante a pagar ->";

	const string enterOption = "Introduza a sua opcao";
	const string wrongOption = "Introduziu opcao errada";
	const string end = "\nTerminou Pagar Servico";
	void printMessage(const string &message);

public:
	PayServiceView();
	virtual ~PayServiceView();

	/**
	 * prints pay service normal menu
	 */
	void printMenuNormal();

	/**
	 * prints pay service business menu
	 */
	void printMenuBusiness();

	/**
	 * prints enter amount to pay message
	 */
	void printAmountToPay();

	/**
	 * prints enter option message
	 */
	void printEnterOption();

	/**
	 * prints wrong option message
	 */
	void printWrongOption();

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
bool PayServiceView::getInfo(T &info) {
	return u->readString(info);
}

#endif /* SRC_VIEW_HEADERS_PAYSERVICEVIEW_H_ */
