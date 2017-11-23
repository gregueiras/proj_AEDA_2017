/*
 * RemoveMenuView.h
 *
 *  Created on: 08/11/2017
 *      Author: jotaa
 */

#ifndef SRC_VIEW_HEADERS_REMOVEUSERMENUVIEW_H_
#define SRC_VIEW_HEADERS_REMOVEUSERMENUVIEW_H_

#include <iostream>
#include "Utilities.h"

using namespace std;

class RemoveMenuView {
private:
	Utilities *u;

	const string removeUserMenu =
			"Remover Utilizador\n1->remover\n2->voltar atras\n0->SAIR";

	const string enterConfirmation =
			"Deseja mesmo remover utilizador?\n0->Nao\n->Sim";

	const string enterOption = "Introduza a sua opcao";
	const string wrongOption = "Introduziu opcao errada";
	const string end = "\nTerminou Remover Utilizador";
	void printMessage(const string &message);

public:
	RemoveMenuView();
	virtual ~RemoveMenuView();

	/**
	 * prints remove user menu initial message
	 */
	void printRemoveUser();

	/**
	 * prints enter option message
	 */
	void printEnterOption();

	/**
	 * prints enter confirmation message
	 */
	void printEnterConfirmation();

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
bool RemoveMenuView::getInfo(T& info) {
	return u->readString(info);
}
#endif /* SRC_VIEW_HEADERS_REMOVEUSERMENUVIEW_H_ */
