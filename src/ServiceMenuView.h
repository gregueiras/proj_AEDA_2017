/*
 * ServiceMenuView.h
 *
 *  Created on: 08/11/2017
 *      Author: jotaa
 */

#ifndef SRC_VIEW_HEADERS_SERVICEMENUVIEW_H_
#define SRC_VIEW_HEADERS_SERVICEMENUVIEW_H_

#include <iostream>
#include "Utilities.h"

using namespace std;

class ServiceMenuView {
private:
	Utilities *u;
	const string serviceMenu =
			"Menu Servicos\n1->requesitar\n2->listar\n3->voltar atras\n0->SAIR";

	const string enterOption = "Introduza a sua opcao";
	const string wrongOption = "Introduziu opcao errada";
	const string end = "\nTerminou Remover Utilizador";
	void printMessage(const string &message);

public:
	ServiceMenuView();
	virtual ~ServiceMenuView();

	/**
	 * prints user menu initial message
	 */
	void printServiceMenu();

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
bool ServiceMenuView::getInfo(T& info) {
	return u->readString(info);
}

#endif /* SRC_VIEW_HEADERS_SERVICEMENUVIEW_H_ */
