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
	const string initialMessage = "\nMenu de ordenacao dos servicos";
	const string enterOption = "Introduza a sua opcao";
	const string wrongOption = "Opcao escolhida invalida";

	const string sortServicesMenu =
			"\n1->id\n2->date\n3->volume\n4->distancia\n5->preco\n4->\n3->voltar atras\n0->SAIR";

	const string end = "\nTerminou Menu de ordenacao dos servicos";
	void printMessage(const string &message);

public:
	SortServicesView();
	virtual ~SortServicesView();

	/**
	 * prints user menu initial message
	 */
	void printInitialMessage();

	/**
	 * prints sort services menu
	 */
	void printSortServicesMenu();

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
bool SortServicesView::getInfo(T& info) {
	return u->readString(info);
}

#endif /* SRC_VIEW_HEADERS_SORTSERVICESVIEW_H_ */
