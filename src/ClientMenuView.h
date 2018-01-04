/*
 * ClientMenuView.h
 *
 *  Created on: 06/11/2017
 *      Author: jotaa
 */

#ifndef SRC_VIEW_SRC_CLIENTMENUVIEW_H_
#define SRC_VIEW_SRC_CLIENTMENUVIEW_H_

#include <iostream>
#include "Utilities.h"

using namespace std;

class ClientMenuView {
private:
	Utilities *u;
	const string clientMenu =
			"\nMenu Cliente\n0->SAIR\n1->Menu Perfil Utilizador\n2->Menu dos Servicos\n3->Voltar Atras";
	const string enterOption = "Introduza a sua opcao";
	const string wrongOption = "Opcao escolhida invalida";
	const string notificationHeader = "\n-----Novas Notificações-----\n";
	const string pendingChangeAdress =
			"Esteve algum tempo afastado. Atualize a sua morada";

	const string end = "\nTerminou Menu Cliente";
	const string shutdown = "\nPrograma terminou";
	void printMessage(const string &message);

public:
	ClientMenuView();
	virtual ~ClientMenuView();

	/**
	 * prints client menu
	 */
	void printClientMenu();

	/**
	 * prints enter option message
	 */
	void printEnterOption();

	/**
	 * prints wrong option message
	 */
	void printWrongOption();

	void printNotificationsHeader();

	void printPendingChangeAdress();

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
bool ClientMenuView::getInfo(T &info) {
	return u->readString(info);
}

#endif /* SRC_VIEW_SRC_CLIENTMENUVIEW_H_ */
