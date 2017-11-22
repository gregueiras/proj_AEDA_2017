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
	const string initialMessage = "\nCriar novo perfil utilizador";
	const string enterUserType =
			"Introduza Tipo Utilizador\n1->Pessoal\n2->Empresarial";
	const string enterName = "Introduza Nome";
	const string enterNIF = "Introduza NIF";
	const string enterStreet = "Introduza Nome da Rua";
	const string enterCountry = "Introduza País";
	const string enterCity = "Introduza Cidade";
	const string enterCounty = "Introduza Município";
	const string enterDoorNumber = "Introduza Número da Rua";
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

	void printInitialMessage() const;

	void printEnterUserType();
	void printEnterName();
	void printEnterNIF();
	void printEnterStreet();
	void printEnterCountry();
	void printEnterCity();
	void printEnterCounty();
	void printEnterDoorNumber();
	void printEnterLatitude();
	void printEnterLongitude();
	void printEnterPassword();

	void printWrongNIF();
	void printWrongLatitude();
	void printWrongLongitude();
	void printWrongUserType();

	void printEnd() const;

	template<typename T>bool getInfo(T &info);
};

template<typename T>
bool NewUserView::getInfo(T &info) {
	return u->readString(info);
}

#endif /* SRC_VIEW_NEWUSERVIEW_H_ */
