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
			"\nRemover Utilizador\n0->SAIR\n1->remover\n2->voltar atrás";

	const string enterConfirmation =
			"Deseja remover definitivamente perfil de utilizador?\n0->Não\n->Sim";

	const string enterOption = "Introduza a sua opção";
	const string wrongOption = "Introduziu opção errada";
	const string end = "\nTerminou Remover Utilizador";
	const string shutdown = "\nPrograma terminou";
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
	 * prints shutdown message
	 */
	void printShutdown();

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
