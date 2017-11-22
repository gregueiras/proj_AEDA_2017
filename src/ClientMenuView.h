/*
 * ClientMenuView.h
 *
 *  Created on: 06/11/2017
 *      Author: jotaa
 */

#ifndef SRC_VIEW_SRC_CLIENTMENUVIEW_H_
#define SRC_VIEW_SRC_CLIENTMENUVIEW_H_

#include <iostream>
#include "Utilities.h"

using namespace std;

class ClientMenuView {
private:
	Utilities *u;
	const string enterOption = "Introduza a sua opção";
	const string wrongOption = "Opção escolhida invalida";
	const string initialMessage = "\nMenu Cliente";

	const string clientMenu =
			"\n1->utilizador\n2->serviços\n3->voltar atrás\n0->SAIR";

	const string end = "\nTerminou Menu Cliente";
	void printMessage(const string &message);

public:
	ClientMenuView();
	virtual ~ClientMenuView();

	void printInitialMessage();
	void printClientMenu();

	void printEnterOption();
	void printWrongOption();

	void printEnd();

	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool ClientMenuView::getInfo(T &info) {
	return u->readString(info);
}

#endif /* SRC_VIEW_SRC_CLIENTMENUVIEW_H_ */
