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

	const string initialMessage = "Menu Utilizador";
	const string userMenu = "\n1->apagar\n2->alterar\n3->voltar atrás\n0->SAIR";

	const string enterOption = "Introduza a sua opção";
	const string wrongOption = "Introduziu opção errada";
	const string end = "\nTerminou Remover Utilizador";
	void printMessage(const string &message);

public:
	UserMenuView();
	virtual ~UserMenuView();

	void printInitialMessage();
	void printUserMenu();

	void printEnterOption();
	void printWrongOption();
	void printEnd();

	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool UserMenuView::getInfo(T &info) {
	return u->readString(info);
}

#endif /* SRC_VIEW_HEADERS_USERMENUVIEW_H_ */
