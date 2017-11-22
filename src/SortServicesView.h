/*
 * SortServicesView.h
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#ifndef SRC_VIEW_HEADERS_SORTSERVICESVIEW_H_
#define SRC_VIEW_HEADERS_SORTSERVICESVIEW_H_

#include <iostream>
#include "Utilities.h"

using namespace std;

class SortServicesView {
private:
	Utilities *u;
	const string initialMessage = "\nMenu de ordenaçao dos serviços";
	const string enterOption = "Introduza a sua opção";
	const string wrongOption = "Opção escolhida invalida";

	const string sortServicesMenu =
			"\n1->id\n2->date\n3->volume\n4->distancia\n5->preço\n4->\n3->voltar atrás\n0->SAIR";

	const string end = "\nTerminou Menu de ordenaçao dos serviços";
	void printMessage(const string &message);

public:
	SortServicesView();
	virtual ~SortServicesView();

	void printInitialMessage();
	void printSortServicesMenu();

	void printEnterOption();
	void printWrongOption();

	void printEnd();

	template<typename T> bool getInfo(T &info);
};


template<typename T>
bool SortServicesView::getInfo(T& info) {
	return u->readString(info);
}


#endif /* SRC_VIEW_HEADERS_SORTSERVICESVIEW_H_ */
