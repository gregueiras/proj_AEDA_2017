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
			"\nMenu Administrador\n0->SAIR\n1->Ver Registo de Serviços\n2->Criar Nova Campanha Promocional\n3->Menu dos Veículos"
					"\n4->Avançar tempo\n5->Voltar Atras";
	const string enterOption = "Introduza a sua opção";
	const string wrongOption = "Introduziu opcao errada";
	const string end = "Terminou Menu Administrador";
	const string shutdown = "\nPrograma terminou";

	void printMessage(const string &message);
public:
	AdministratorMenuView();
	virtual ~AdministratorMenuView();

	void printAdministratorMenu();

	void printEnterOption();

	void printShutdown();
	void printEnd();
	void printWrongOption();

	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool AdministratorMenuView::getInfo(T &info) {
	return u->readString(info);
}

#endif /* SRC_ADMINISTRATORMENUVIEW_H_ */
