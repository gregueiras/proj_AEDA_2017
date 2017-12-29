/*
 * AdministratorMenuView.h
 *
 *  Created on: 25 Dec 2017
 *      Author: jotaa
 */

#ifndef SRC_ADMINISTRATORMENUVIEW_H_
#define SRC_ADMINISTRATORMENUVIEW_H_

#include <iostream>
#include "Utilities.h"

using namespace std;

class AdministratorMenuView {
private:
	Utilities *u;
	const string administratorMenu =
			"Menu Administrador\n0->SAIR\n1->ver registo de serviços\n2->nova campanha promocional\n3->veículos\n4->voltar atras";
	const string enterOption = "Introduza a sua opção";
	const string end = "Terminou Menu de Administrador";
	const string shutdown = "\nPrograma terminou";
	const string wrongOption = "Introduziu opcao errada";

	void printMessage(const string &message);
public:
	AdministratorMenuView();
	virtual ~AdministratorMenuView();

	void printAdministratorMenu();

	void printEnterOption();

	void printShutdown();
	void printWrongOption();

	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool AdministratorMenuView::getInfo(T &info) {
	return u->readString(info);
}

#endif /* SRC_ADMINISTRATORMENUVIEW_H_ */
