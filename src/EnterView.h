/*
 * EnterView.h
 *
 *  Created on: 04/11/2017
 *      Author: jotaa
 */

#ifndef VIEW_ENTERVIEW_H_
#define VIEW_ENTERVIEW_H_

#include "Utilities.h"
#include "Validation.h"

#include <iostream>

using namespace std;

class EnterView {
private:
	Utilities *u;
	const string options =
			"\n----------------------\nSistema Gestao Empresa\n----------------------\n0->Sair\n1->Login\n2->Criar Novo Perfil Utilizador";
	const string enterOption = "Introduza a sua opcao";
	const string wrongOption = "Opcao escolhida inv�lida";
	const string end = "Terminou Programa";
	const string shutdown = "\nPrograma terminou";
	void printMessage(const string message) const;
public:
	EnterView();
	virtual ~EnterView();

	/**
	 * prints user menu initial message
	 */
	void printEnterMenu() const;

	/**
	 * prints wrong option message
	 */
	void printWrongOption() const;

	/**
	 * prints enter option message
	 */
	void printEnterOption() const;

	/**
	 * prints end message
	 */
	void printEnd() const;

	/**
	 * prints shutdown message
	 */
	void printShutdown();

	/**
	 * reads string from keyboard
	 */
	template<typename T> bool getInfo(T& info);
};

template<typename T>
bool EnterView::getInfo(T& info) {
	return u->readString(info);
}

#endif /* VIEW_ENTERVIEW_H_ */
