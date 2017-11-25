/*
 * NewUserView.h
 *
 *  Created on: 04/11/2017
 *      Author: jotaa
 */

#ifndef SRC_VIEW_NEWUSERVIEW_H_
#define SRC_VIEW_NEWUSERVIEW_H_

#include <iostream>
#include "Utilities.h"
#include "Validation.h"

using namespace std;

class NewUserView {
private:
	Utilities *u;
	const string newUserMenu = "\nCriar novo perfil utilizador";
	const string enterUserType =
			"\nIntroduza Tipo Utilizador\n0->SAIR\n1->Pessoal\n2->Empresarial\n3->Nao registado";
	const string enterName = "Introduza Nome. 0->SAIR";
	const string enterNIF = "Introduza NIF. 0->SAIR";
	const string enterStreet = "Introduza Nome da Rua. 0->SAIR";
	const string enterCountry = "Introduza País. 0->SAIR";
	const string enterCity = "Introduza Cidade. 0->SAIR";
	const string enterCounty = "Introduza Município. 0->SAIR";
	const string enterDoorNumber = "Introduza Número da Rua. 0->SAIR";
	const string enterLatitude = "Introduza Latitude. 0->SAIR";
	const string enterLongitude = "Introduza Longitude. 0->SAIR";
	const string enterPassword = "Introduza password. 0->SAIR";

	const string wrongNIF = "NIF introduzido invalido";
	const string wrongLatitude = "Latitude introduzida invalida";
	const string wrongLongitude = "Longitude introduzida invalida";
	const string wrongUserType = "Tipo Utilizador introduzido invalido";
	const string end = "Terminou Criar novo perfil utilizador";
	const string shutdown = "\nPrograma terminou";
	void printMessage(const string &message) const;

public:
	NewUserView();
	virtual ~NewUserView();

	/**
	 * prints enter new user menu
	 */
	void printNewUserMenu();

	/**
	 * prints enter user type
	 */
	void printEnterUserType();

	/**
	 * prints enter name
	 */
	void printEnterName();

	/**
	 * prints enter nif
	 */
	void printEnterNIF();

	/**
	 * prints enter street
	 */
	void printEnterStreet();

	/**
	 * prints enter enter country
	 */
	void printEnterCountry();

	/**
	 * prints enter enter city
	 */
	void printEnterCity();

	/**
	 * prints enter county
	 */
	void printEnterCounty();

	/**
	 * prints enter door number
	 */
	void printEnterDoorNumber();

	/**
	 * prints enter latitude
	 */
	void printEnterLatitude();

	/**
	 * prints enter longitude
	 */
	void printEnterLongitude();

	/**
	 * prints enter password
	 */
	void printEnterPassword();

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
	 * prints user ID
	 */
	void printUserID(const unsigned int userID);

	/**
	 * prints wrong user type message
	 */
	void printWrongUserType();

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
	template<typename T> bool getInfo(T &info);

	/**
	 * reads string representing line from keyboard
	 */
	string readLine();
};

template<typename T>
bool NewUserView::getInfo(T &info) {
	return u->readString(info);
}

#endif /* SRC_VIEW_NEWUSERVIEW_H_ */
