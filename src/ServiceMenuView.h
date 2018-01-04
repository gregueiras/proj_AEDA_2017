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
	const string servicesListing = "\nMenu Servi�os:";
	const string noServicesRegistered = "\nN�o tem servi�os registados:";
	const string serviceMenu =
			"\nMenu Servi�os\n0->SAIR\n1->Requesitar Novo Servi�o\n2->Ver Servi�o\n3->Ordenar Listagem dos Servi�os\n4->Filtrar Listagem dos Servi�os"
					"\n5->Voltar Atr�s";
	const string serviceMenuForBusinnessClients =
			"\nMenu Servi�os\n0->SAIR\n1->Requesitar Novo Servi�o\n2->Ver Servi�o\n3->Ordenar Listagem dos Servi�os\n4->Filtrar Listagem dos Servi�os"
					"\n5->Pagar Servi�os\n6->Voltar Atras\n";

	const string enterServiceID = "Introduza o id do servi�o";
	const string serviceIDNotFound = "Servi�o com o id dado n�o foi encontrado";

	const string serviceTermExpired = "Prazo  a sua op��o";
	const string enterOption = "Introduza a sua op��o";
	const string wrongOption = "Introduziu op��o errada";
	const string end = "Terminou Menu Servi�os";
	const string shutdown = "\nPrograma terminou";
	void printMessage(const string &message);

public:
	ServiceMenuView();
	virtual ~ServiceMenuView();

	/**
	 * prints services listing
	 */
	void printServicesListing();

	/**
	 * prints message for no services registered
	 */
	void printNoServicesRegistered();

	/**
	 * prints list services menu
	 */
	void printServiceInfo(unsigned int id, string userInfo);

	/**
	 * prints services menu
	 */
	void printServiceMenu();

	/**
	 * prints services menu for business clientes
	 */
	void printServiceMenuForBusinnessClients();

	/**
	 * prints enter option message
	 */
	void printEnterOption();

	/**
	 * prints wrong option message
	 */
	void printWrongOption();

	/**
	 * prints list services menu
	 */
	void printEnterServiceID();

	/**
	 * print id of service not found message
	 */
	void printServiceIDNotFound();

	/**
	 * print message that service term of change has expired
	 */
	void printServiceTermExpired();
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
bool ServiceMenuView::getInfo(T& info) {
	return u->readString(info);
}

#endif /* SRC_VIEW_HEADERS_SERVICEMENUVIEW_H_ */
