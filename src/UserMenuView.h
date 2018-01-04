/*
 * UserMenuView.h
 *
 *  Created on: 08/11/2017
 *      Author: jotaa
 */

#ifndef SRC_VIEW_HEADERS_USERMENUVIEW_H_
#define SRC_VIEW_HEADERS_USERMENUVIEW_H_

#include <iostream>
#include "Utilities.h"

using namespace std;

class UserMenuView {
private:
	Utilities *u;

	const string userMenu =
			"\nMenu Perfil Utilizador\n0->SAIR\n1->Alterar Perfil de Utilizador\n2->Apagar Perfil de Utilizador\n3->Voltar Atrás";

	const string enterOption = "Introduza a sua opção";
	const string wrongOption = "Introduziu opção errada";
	const string end = "\nTerminou Remover Utilizador";
	const string shutdown = "\nPrograma terminou";
	void printMessage(const string &message);

public:
	UserMenuView();
	virtual ~UserMenuView();

	/**
	 * prints user menu initial message
	 */
	void printUserMenu();

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
bool UserMenuView::getInfo(T &info) {
	return u->readString(info);
}

#endif /* SRC_VIEW_HEADERS_USERMENUVIEW_H_ */
