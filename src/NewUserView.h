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
			"\nIntroduza Tipo Utilizador\n1->Pessoal\n2->Empresarial";
	const string enterName = "Introduza Nome";
	const string enterNIF = "Introduza NIF";
	const string enterStreet = "Introduza Nome da Rua";
	const string enterCountry = "Introduza Pais";
	const string enterCity = "Introduza Cidade";
	const string enterCounty = "Introduza Municipio";
	const string enterDoorNumber = "Introduza Numero da Porta";
	const string enterLatitude = "Introduza Latitude";
	const string enterLongitude = "Introduza Longitude";
	const string enterPassword = "Introduza password";
	const string wrongNIF = "NIF introduzido invalido";
	const string wrongLatitude = "Latitude introduzida invalida";
	const string wrongLongitude = "Longitude introduzida invalida";
	const string wrongUserType = "Tipo Utilizador introduzido invalido";
	const string exit = "\n0->SAIR";
	const string end = "Terminou Criar novo perfil utilizador";
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
	 * prints wrong user type message
	 */
	void printWrongUserType();

	/**
	 * prints end message
	 */
	void printEnd() const;

	/**
	 * reads string from keyboard
	 */
	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool NewUserView::getInfo(T &info) {
	return u->readString(info);
}

#endif /* SRC_VIEW_NEWUSERVIEW_H_ */
