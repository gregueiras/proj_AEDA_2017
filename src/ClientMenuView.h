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
	const string enterOption = "Introduza a sua opcao";
	const string wrongOption = "Opcao escolhida invalida";

	const string clientMenu =
			"\nMenu Cliente\n1->utilizador\n2->servicos\n3->voltar atras\n0->SAIR";

	const string end = "\nTerminou Menu Cliente";
	const string shutdown = "\nPrograma terminou";
	void printMessage(const string &message);

public:
	ClientMenuView();
	virtual ~ClientMenuView();

	/**
	 * prints client menu
	 */
	void printClientMenu();

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
	 * prints shutdown message
	 */
	void printShutdown();

	/**
	 * reads string from keyboard
	 */
	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool ClientMenuView::getInfo(T &info) {
	return u->readString(info);
}

#endif /* SRC_VIEW_SRC_CLIENTMENUVIEW_H_ */
