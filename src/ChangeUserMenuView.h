/*
 * ChangeMenuView.h
 *
 *  Created on: 08/11/2017
 *      Author: jotaa
 */

#ifndef SRC_VIEW_HEADERS_CHANGEUSERMENUVIEW_H_
#define SRC_VIEW_HEADERS_CHANGEUSERMENUVIEW_H_

#include <iostream>
#include "Utilities.h"

using namespace std;

class ChangeUserMenuView {
private:
	Utilities *u;

	const string initialMessage = "ALterar Utilizador";

	const string changeUserMenu =
			"\n1->name\n2->NIF\n3->street\n4->Country\n5->city\n6->County\n7->DoorNumber\n8->Latitude\n9->Longitude\n10->voltar atr�s\n0->SAIR";

	const string enterName = "Introduza novo nome";
	const string enterNIF = "Introduza novo NIF";
	const string enterStreet = "Introduza nova rua";
	const string enterCountry = "Introduza novo pa�s";
	const string enterCity = "Introduza nova cidade";
	const string enterCounty = "Introduza novo municipio";
	const string enterDoorNumber = "Introduza novo n�mero da porta";
	const string enterLatitude = "Introduza nova latitude";
	const string enterLongitude = "Introduza nova longitude";

	const string enterOption = "Introduza a sua op��o";
	const string wrongOption = "Introduziu op��o errada";
	const string keepContinuing = "Deseja continuar \n0->Nao\n1->Sim";

	const string wrongNIF = "NIF introduzido invalido";
	const string wrongLatitude = "Latitude introduzida invalida";
	const string wrongLongitude = "Longitude introduzida invalida";

	const string end = "\nTerminou Remover Utilizador";
	void printMessage(const string &message);
public:
	ChangeUserMenuView();
	virtual ~ChangeUserMenuView();

	void printInitialMessage();
	void printChangeUser();

	void printEnterNewName();
	void printEnterNewNIF();
	void printEnterNewStreet();
	void printEnterNewCounty();
	void printEnterNewCity();
	void printEnterNewCountry();
	void printEnterNewDoorNumber();
	void printEnterNewLatitude();
	void printEnterNewLongitude();

	void printEnterOption();
	void printEnterContinue();

	void printUserInfo(std::string str);

	void printWrongOption();
	void printWrongNIF();
	void printWrongLatitude();
	void printWrongLongitude();

	void printEnd();

	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool ChangeUserMenuView::getInfo(T &info) {
	return u->readString(info);
}
#endif /* SRC_VIEW_HEADERS_CHANGEUSERMENUVIEW_H_ */
