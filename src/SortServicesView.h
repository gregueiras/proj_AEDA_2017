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
	const string sortServicesMenu =
			"\nMenu Ordenaçao dos Serviços\n0->SAIR\n1->ID\n2->Data\n3->Volume\n4->Distancia\n5->Preço\n6->Voltar Atrás";

	const string enterOption = "Introduza a sua opção";
	const string wrongOption = "Opção escolhida invalida";

	const string end = "Terminou Menu ordenaçao dos serviços";
	const string shutdown = "\nPrograma terminou";
	void printMessage(const string &message);

public:
	SortServicesView();
	virtual ~SortServicesView();

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
	 * prints shutdown message
	 */
	void printShutdown();

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
