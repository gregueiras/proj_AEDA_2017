/*
 * ChangeMenuView.h
 *
 *  Created on: 08/11/2017
 *      Author: jotaa
 */

#ifndef CHANGEUSERMENUVIEW_H_
#define CHANGEUSERMENUVIEW_H_

#include <iostream>
#include "Utilities.h"

using namespace std;

class ChangeUserMenuView {
private:
	Utilities *u;

	const string changeUserMenu =
			"\nALterar Utilizador\n1->name\n2->NIF\n3->street\n4->Country\n5->city\n6->County\n7->DoorNumber\n8->Latitude\n9->Longitude\n10->voltar atr�s\n0->SAIR";

	const string enterName = "Introduza novo nome";
	const string enterNIF = "Introduza novo NIF";
	const string enterStreet = "Introduza nova rua";
	const string enterCountry = "Introduza novo pais";
	const string enterCity = "Introduza nova cidade";
	const string enterCounty = "Introduza novo municipio";
	const string enterDoorNumber = "Introduza novo numero da porta";
	const string enterLatitude = "Introduza nova latitude";
	const string enterLongitude = "Introduza nova longitude";

	const string enterOption = "Introduza a sua opcao";
	const string wrongOption = "Introduziu opcao errada";
	const string keepContinuing = "Deseja continuar \n0->Nao\n1->Sim";

	const string wrongNIF = "NIF introduzido invalido";
	const string wrongLatitude = "Latitude introduzida invalida";
	const string wrongLongitude = "Longitude introduzida invalida";

	const string end = "\nTerminou Remover Utilizador";
	void printMessage(const string &message);
public:
	ChangeUserMenuView();
	virtual ~ChangeUserMenuView();

	/**
	 * prints change user
	 */
	void printChangeUser();

	/**
	 * prints enter new name
	 */
	void printEnterNewName();

	/**
	 * prints enter new nif
	 */
	void printEnterNewNIF();

	/**
	 * prints enter new street
	 */
	void printEnterNewStreet();

	/**
	 * prints enter new county
	 */
	void printEnterNewCounty();

	/**
	 * prints enter new city
	 */
	void printEnterNewCity();

	/**
	 * prints enter new country
	 */
	void printEnterNewCountry();

	/**
	 * prints enter new door number
	 */
	void printEnterNewDoorNumber();

	/**
	 * prints enter new latitude
	 */
	void printEnterNewLatitude();

	/**
	 * prints enter new longitude
	 */
	void printEnterNewLongitude();

	/**
	 * prints enter option
	 */
	void printEnterOption();

	/**
	 * prints continue info
	 */
	void printEnterContinue();

	/**
	 * prints user info
	 */
	void printUserInfo(string str);

	/**
	 * prints wrong option message
	 */
	void printWrongOption();

	/**
	 * prints wrong nif message
	 */
	void printWrongNIF();

	/**
	 * prints wrong latitude message
	 */
	void printWrongLatitude();

	/**
	 * prints wrong longitude message
	 */
	void printWrongLongitude();

	/**
	 * prints end message
	 */
	void printEnd();

	/**
	 * reads string from keyboard
	 */
	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool ChangeUserMenuView::getInfo(T &info) {
	return u->readString(info);
}
#endif /* CHANGEUSERMENUVIEW_H_ */
