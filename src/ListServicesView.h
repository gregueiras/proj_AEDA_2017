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
	const string initialMessage = "Listar Serviços";
	const string listServicesMenu =
			"\n1->Ver Serviço\n2->ordenar\n3->filtrar\n4->alterar\n5->apagar\n6->voltar atras\n0->SAIR";
	const string listServicesMenuForBusinnessClients =
			"\n1->Ver Serviço\n2->ordenar\n3->filtrar\n4->alterar\n5->apagar\n6->pagar\n7->voltar atras\n0->SAIR";

	const string enterOption = "Introduza a sua opção";
	const string enterServiceID = "Introduza o id do serviço";
	const string wrongOption = "Opção escolhida invalida";

	const string end = "\nTerminou Menu Listar Serviços";
	void printMessage(const string &message);
public:
	ListServicesView();
	virtual ~ListServicesView();

	void printInitialMessage();
	void printListServicesMenu();
	void printListServicesMenuForBusinnessClients();

	void printEnterOption();
	void printEnterServiceID();
	void printServiceInfo(unsigned int i, string userInfo);
	void printWrongOption();

	void printEnd();

	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool ListServicesView::getInfo(T &info) {
	return u->readString(info);
}
#endif /* SRC_VIEW_SRC_LISTSERVICESVIEW_H_ */
