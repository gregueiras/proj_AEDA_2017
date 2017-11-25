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
	const string servicesListing = "\nListagem dos Serviços:";
	const string listServicesMenu =
			"\nMenu Listagem\n0->SAIR\n1->Ver Serviço\n2->ordenar\n3->filtrar"
					"\n4->alterar\n5->apagar\n6->voltar atras";
	const string listServicesMenuForBusinnessClients =
			"\nMenu Listagem\n0->SAIR\n1->Ver Serviço\n2->ordenar\n3->filtrar"
					"\n4->alterar\n5->apagar\n6->pagar\n7->voltar atras\n";

	const string enterOption = "\nIntroduza a sua opção 0->SAIR";
	const string enterServiceID = "\nIntroduza o id do serviço";
	const string wrongOption = "\nOpção escolhida invalida";

	const string end = "\nTerminou Menu Listar Serviços";
	const string shutdown = "\nPrograma terminou";
	void printMessage(const string &message);
public:
	ListServicesView();
	virtual ~ListServicesView();

	/**
	 * prints services listing
	 */
	void printServicesListing();

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
	 * prints shutdown message
	 */
	void printShutdown();

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
