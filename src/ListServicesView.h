/*
 * ListServicesView.h
 *
 *  Created on: 13/11/2017
 *      Author: jotaa
 */

#ifndef SRC_VIEW_SRC_LISTSERVICESVIEW_H_
#define SRC_VIEW_SRC_LISTSERVICESVIEW_H_

#include <iostream>
#include "Utilities.h"

using namespace std;

class ListServicesView {
private:
	Utilities *u;
	const string listServicesMenu =
			"\nListar Servicos\n1->Ver Servico\n2->ordenar\n3->filtrar\n4->alterar\n5->apagar\n6->voltar atras\n0->SAIR";
	const string listServicesMenuForBusinnessClients =
			"\n1->Ver Servico\n2->ordenar\n3->filtrar\n4->alterar\n5->apagar\n6->pagar\n7->voltar atras\n0->SAIR";

	const string enterOption = "Introduza a sua opcao";
	const string enterServiceID = "Introduza o id do servico";
	const string wrongOption = "Opcao escolhida invalida";

	const string end = "\nTerminou Menu Listar Servicos";
	void printMessage(const string &message);
public:
	ListServicesView();
	virtual ~ListServicesView();

	/**
	 * prints list services menu
	 */
	void printListServicesMenu();

	/**
	 * prints list services menu
	 */
	void printListServicesMenuForBusinnessClients();

	/**
	 * prints list services menu
	 */
	void printEnterOption();

	/**
	 * prints list services menu
	 */
	void printEnterServiceID();

	/**
	 * prints list services menu
	 */
	void printServiceInfo(unsigned int i, string userInfo);

	/**
	 * prints list services menu
	 */
	void printWrongOption();

	/**
	 * prints list services menu
	 */
	void printEnd();

	/**
	 * prints list services menu
	 */
	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool ListServicesView::getInfo(T &info) {
	return u->readString(info);
}
#endif /* SRC_VIEW_SRC_LISTSERVICESVIEW_H_ */
