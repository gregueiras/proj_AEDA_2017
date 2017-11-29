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

	const string changeUserMenu =
			"Alterar Utilizador\n0->SAIR\n1->name\n2->NIF\n3->street\n4->Country\n5->city"
					"\n6->County\n7->DoorNumber\n8->Latitude\n9->Longitude\n10->Password\n11->voltar atras";
	const string newChangeUserMenu = "\nAlterar perfil utilizador";
	const string enterUserType =
			"\nIntroduza opçao para alterar\n0->SAIR\n1->nome\n2->nif\n3->nome da rua\n4->País\n5->cidade\n6->municipio\n7->numero da rua"
					"\n8->latitude\n9->longitude\n10->password";
	const string enterOption = "Introduza a sua opção";

	const string enterNewName = "Introduza novo Nome. 0->SAIR";
	const string enterNewNIF = "Introduza novo NIF. 0->SAIR";
	const string enterNewStreet = "Introduza novo Nome da Rua. 0->SAIR";
	const string enterNewCountry = "Introduza novo País. 0->SAIR";
	const string enterNewCity = "Introduza nova Cidade. 0->SAIR";
	const string enterNewCounty = "Introduza novo Município. 0->SAIR";
	const string enterNewDoorNumber = "Introduza novo Número da porta. 0->SAIR";
	const string enterNewLatitude = "Introduza nova Latitude. 0->SAIR";
	const string enterNewLongitude = "Introduza nova Longitude. 0->SAIR";
	const string enterNewPassword = "Introduza nova password. 0->SAIR";

	const string wrongNIF = "NIF introduzido invalido";
	const string wrongLatitude = "Latitude introduzida invalida";
	const string wrongLongitude = "Longitude introduzida invalida";
	const string wrongOption = "Introduziu opï¿½ï¿½o errada";

	const string end = "Terminou Criar novo perfil utilizador";
	const string shutdown = "\nPrograma terminou";

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
	 * prints enter new longitude
	 */
	void printEnterNewPassword();

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
	 * prints shutdown message
	 */
	void printShutdown();

	/**
	 * reads string from keyboard
	 */
	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool ChangeUserMenuView::getInfo(T &info) {
	return u->readString(info);
}
#endif /* SRC_VIEW_HEADERS_CHANGEUSERMENUVIEW_H_ */
