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
	const string servicesListing = "\nMenu Serviços:";
	const string noServicesRegistered = "\nNão tem serviços registados:";
	const string serviceMenu =
			"\nMenu Serviços\n0->SAIR\n1->Requesitar Novo Serviço\n2->Ver Serviço\n3->Ordenar Listagem dos Serviços\n4->Filtrar Listagem dos Serviços"
					"\n5->Voltar Atrás";
	const string serviceMenuForBusinnessClients =
			"\nMenu Serviços\n0->SAIR\n1->Requesitar Novo Serviço\n2->Ver Serviço\n3->Ordenar Listagem dos Serviços\n4->Filtrar Listagem dos Serviços"
					"\n5->Pagar Serviços\n6->Voltar Atras\n";

	const string enterServiceID = "Introduza o id do serviço";
	const string serviceIDNotFound = "Serviço com o id dado não foi encontrado";

	const string serviceTermExpired = "Prazo  a sua opção";
	const string enterOption = "Introduza a sua opção";
	const string wrongOption = "Introduziu opção errada";
	const string end = "Terminou Menu Serviços";
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
