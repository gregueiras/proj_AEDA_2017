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
			"Menu Utilizador\n1->apagar\n2->alterar\n3->voltar atras\n0->SAIR";

	const string enterOption = "Introduza a sua opcao";
	const string wrongOption = "Introduziu opcao errada";
	const string end = "\nTerminou Remover Utilizador";
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
	 * reads string from keyboard
	 */
	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool UserMenuView::getInfo(T &info) {
	return u->readString(info);
}

#endif /* SRC_VIEW_HEADERS_USERMENUVIEW_H_ */
