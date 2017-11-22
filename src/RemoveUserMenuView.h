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

	const string initialMessage = "Remover Utilizador";
	const string removeUserMenu = "\n1->remover\n2->voltar atrás\n0->SAIR";

	const string enterConfirmation =
			"Deseja mesmo remover utilizador?\n0->Não\n->Sim";

	const string enterOption = "Introduza a sua opção";
	const string wrongOption = "Introduziu opção errada";
	const string end = "\nTerminou Remover Utilizador";
	void printMessage(const string &message);

public:
	RemoveMenuView();
	virtual ~RemoveMenuView();

	void printInitialMessage();
	void printRemoveUser();

	void printEnterOption();
	void printEnterConfirmation();

	void printWrongOption();

	void printEnd();

	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool RemoveMenuView::getInfo(T& info) {
	return u->readString(info);
}
#endif /* SRC_VIEW_HEADERS_REMOVEUSERMENUVIEW_H_ */
