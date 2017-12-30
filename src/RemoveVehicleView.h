/*
 * RemoveVehicleView.h
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#ifndef SRC_REMOVEVEHICLEVIEW_H_
#define SRC_REMOVEVEHICLEVIEW_H_

#include <iostream>
#include "Utilities.h"

using namespace std;

class RemoveVehicleView {
private:
	Utilities *u;

	const string removeVehicleMenu =
			"\nRemover Ve�culo\n0->SAIR\n1->remover\n2->voltar atr�s";
	const string enterConfirmation =
			"Deseja remover definitivamente ve�culo?\n0->N�o\n1->Sim";

	const string enterOption = "Introduza a sua op��o";
	const string wrongOption = "Introduziu op��o errada";
	const string end = "\nTerminou Remover Utilizador";
	const string shutdown = "\nPrograma terminou";
	void printMessage(const string &message);
public:
	RemoveVehicleView();
	virtual ~RemoveVehicleView();

	void printRemoveVehicleMenu();

	/**
	 * prints enter option message
	 */
	void printEnterOption();

	/**
	 * prints enter confirmation message
	 */
	void printEnterConfirmation();

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
bool RemoveVehicleView::getInfo(T& info) {
	return u->readString(info);
}

#endif /* SRC_REMOVEVEHICLEVIEW_H_ */
