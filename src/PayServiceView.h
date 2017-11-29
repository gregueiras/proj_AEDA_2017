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
	const string payMenuNormal =
			"\nPagar Serviço\n1->multibanco(pagamento de serviços)\n2->transferencia bancaria";
	const string payMenuBusiness =
			"\nPagar Serviço\n0->SAIR\n1->multibanco(pagamento de serviços)\n2->transferencia bancaria\n3->Cartao Credito";

	const string payEOM = "\nPagar Serviços do mes anterior\n0->SAIR";
	const string amountToPay = "\nMontante a pagar-> ";
	const string noEOMLeftToPay =
			"\nNao ha pagamentos do final do mes em divida";
	const string entity = "\nEntidade-> ";
	const string nib = "\nNIB-> ";
	const string reference = "\nReferencia-> ";
	const string enterCreditCardNumber =
			"\nIntroduza o numero do cartao de credito";

	const string enterOption = "Introduza a sua opção";
	const string wrongOption = "Introduziu opção errada";
	const string end = "\nTerminou Pagar Serviço";
	const string shutdown = "\nPrograma terminou";
	void printMessage(const string &message);

public:
	PayServiceView();
	virtual ~PayServiceView();

	/**
	 * prints pay service normal menu
	 */
	void printPayMenuNormal();

	/**
	 * prints pay service normal menu
	 */
	void printPayMenuBusiness();

	/**
	 * prints pay service business menu
	 */
	void printPayEOM();

	/**
	 * prints enter amount to pay message
	 */
	void printAmountToPay(double amountToPay);

	/**
	 * prints entity of the company
	 */
	void printEntity(string entity);

	/**
	 * prints reference of the company
	 */
	void printReference(string reference);

	/**
	 * prints nib of the company
	 */
	void printNIB(string nib);

	/**
	 *
	 */
	void printEnterCreditCardNumber();
	/**
	 * prints enter option message
	 */
	void printEnterOption();

	/**
	 * prints wrong option message
	 */
	void printWrongOption();

	/**
	 * prints no payments for the end of the month left to pay
	 */
	void printNoEOMLeftToPay();

	/**
	 * prints end message
	 */
	void printEnd();

	/**
	 * prints shutdown message
	 */
	void printShutdown();

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
