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
	const string title =
			"\n----------------------\nSistema Gestão Empresa\n----------------------\n";
	const string options =
			"0->SAIR\n   1->Login\n   2->Criar Novo Perfil Utilizador";
	const string enterOption = "Introduza a sua opção";
	const string wrongOption = "Opçao escolhida inválida";
	const string end = "Terminou Programa";
	void printMessage(const string message) const;
public:
	EnterView();
	virtual ~EnterView();

	void printEnterMenu() const;
	void printWrongOption() const;
	void printEnterOption() const;
	void printEnd() const;

	template<typename T> bool getInfo(T& info);
};

template<typename T>
bool EnterView::getInfo(T& info) {
	return u->readString(info);
}


#endif /* VIEW_ENTERVIEW_H_ */
