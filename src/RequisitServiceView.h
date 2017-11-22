/*
 * RequisitServiceView.h
 *
 *  Created on: 13/11/2017
 *      Author: jotaa
 */

#ifndef SRC_VIEW_HEADERS_REQUISITSERVICEVIEW_H_
#define SRC_VIEW_HEADERS_REQUISITSERVICEVIEW_H_

#include <iostream>
#include "Utilities.h"

using namespace std;

class RequisitServiceView {
private:
	Utilities *u;
	const string initialMessage = "Requisitar Serviço";

	const string departureAddress = "Introduza o endereço de partida";
	const string arrivalAddress = "Introduza o endereço de chegada";
	const string enterVolume = "Introduza o volume da mercadoria";
	const string enterStreet = "Introduza Nome da Rua";
	const string enterCountry = "Introduza País";
	const string enterCity = "Introduza Cidade";
	const string enterCounty = "Introduza Município";
	const string enterDoorNumber = "Introduza Número da Rua";
	const string enterLatitude = "Introduza Latitude";
	const string enterLongitude = "Introduza Longitude";

	const string enterPackagingInitialDate =
			"Introduza data de início do embalamento (dd mm aaaa)";
	const string enterPackagingInitialTime =
			"Introduza tempo de início do embalamento (hh mm)";

	const string enterStorageTime = "Introduza o tempo de armazenamento";

	const string wrongPackagingInitialDay = "dia inicio do embalamento invalido";
	const string wrongPackagingInitialMonth =
			"mes inicio do embalamento invalido";
	const string wrongPackagingInitialYear =
			"ano inicio do embalamento invalido";
	const string wrongPackagingInitialMinute =
			"minuto inicial de embalamento invalido";
	const string wrongPackagingInitialHour =
			"hora inicial de embalamento invalido";
	const string wrongStorageTime = "tempo armazenamento invalido";
	const string wrongNIF = "NIF introduzido invalido";
	const string wrongLatitude = "Latitude introduzida invalida";
	const string wrongLongitude = "Longitude introduzida invalida";

	const string addToEOM =
			"Pretende deixar para o fim do mes?\n1->Sim\n2->Nao\n0->SAIR";
	const string enterOption = "Introduza a sua opção";
	const string wrongOption = "Opçao introduzida invalida";

	const string exit = "\n0->SAIR";
	const string end = "\nTerminou Requesitar Serviço";
	void printMessage(const string &message);

public:
	RequisitServiceView();
	virtual ~RequisitServiceView();

	void printInitialMessage();

	void printDepartureAddress();
	void printArrivalAddress();

	void printEnterStreet();
	void printEnterCountry();
	void printEnterCity();
	void printEnterCounty();
	void printEnterDoorNumber();
	void printEnterLatitude();
	void printEnterLongitude();

	void printEnterPackagingInitialDate();
	void printEnterPackagingInitialTime();
	void printEnterStorageTime();
	void printEnterVolume();

	void printWrongPackagingInitialDay();
	void printWrongPackagingInitialMonth();
	void printWrongPackagingInitialYear();
	void printWrongPackagingInitialMinute();
	void printWrongPackagingInitialHour();
	void printWrongStorageTime();
	void printWrongNIF();
	void printWrongLatitude();
	void printWrongLongitude();

	void printAddToEOM();
	void printEnterOption();
	void printWrongOption();

	void printEnd();

	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool RequisitServiceView::getInfo(T& info) {
	return u->readString(info);
}

#endif /* SRC_VIEW_HEADERS_REQUISITSERVICEVIEW_H_ */
