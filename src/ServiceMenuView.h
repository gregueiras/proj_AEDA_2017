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
	const string initialMessage = "Menu Serviços";
	const string serviceMenu =
			"\n1->requesitar\n2->listar\n3->voltar atras\n0->SAIR";

	const string enterOption = "Introduza a sua opção";
	const string wrongOption = "Introduziu opção errada";
	const string end = "\nTerminou Remover Utilizador";
	void printMessage(const string &message);

public:
	ServiceMenuView();
	virtual ~ServiceMenuView();

	void printInitialMessage();
	void printServiceMenu();

	void printEnterOption();
	void printWrongOption();

	void printEnd();

	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool ServiceMenuView::getInfo(T& info) {
	return u->readString(info);
}


#endif /* SRC_VIEW_HEADERS_SERVICEMENUVIEW_H_ */
