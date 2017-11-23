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
	const string initialMessage = "Requisitar Servico";

	const string departureAddress = "Introduza o endereco de partida";
	const string arrivalAddress = "Introduza o endereco de chegada";
	const string enterVolume = "Introduza o volume da mercadoria";
	const string enterStreet = "Introduza Nome da Rua";
	const string enterCountry = "Introduza Pais";
	const string enterCity = "Introduza Cidade";
	const string enterCounty = "Introduza Municipio";
	const string enterDoorNumber = "Introduza Numero da Porta";
	const string enterLatitude = "Introduza Latitude";
	const string enterLongitude = "Introduza Longitude";

	const string enterPackagingInitialDate =
			"Introduza data de inicio do embalamento (dd mm aaaa)";
	const string enterPackagingInitialTime =
			"Introduza tempo de inicio do embalamento (hh mm)";

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
	const string enterOption = "Introduza a sua opcao";
	const string wrongOption = "Opcao introduzida invalida";

	const string exit = "\n0->SAIR";
	const string end = "\nTerminou Requesitar Servico";
	void printMessage(const string &message);

public:
	RequisitServiceView();
	virtual ~RequisitServiceView();

	/**
	 * prints requisit service initial message
	 */
	void printInitialMessage();

	/**
	 * prints departure address message
	 */
	void printDepartureAddress();

	/**
	 * prints arrival address message
	 */
	void printArrivalAddress();

	/**
	 * prints enter street message
	 */
	void printEnterStreet();

	/**
	 * prints enter country message
	 */
	void printEnterCountry();

	/**
	 * prints enter city message
	 */
	void printEnterCity();

	/**
	 * prints enter county message
	 */
	void printEnterCounty();

	/**
	 * prints enter door number message
	 */
	void printEnterDoorNumber();

	/**
	 * prints enter latitude message
	 */
	void printEnterLatitude();

	/**
	 * prints enter longitude message
	 */
	void printEnterLongitude();

	/**
	 * prints enter packaging initial date message
	 */
	void printEnterPackagingInitialDate();

	/**
	 * prints enter packaging initial time message
	 */
	void printEnterPackagingInitialTime();

	/**
	 * prints enter storage time message
	 */
	void printEnterStorageTime();

	/**
	 * prints enter volume message
	 */
	void printEnterVolume();

	/**
	 * prints enter intial day message
	 */
	void printWrongPackagingInitialDay();

	/**
	 * prints enter intial month message
	 */
	void printWrongPackagingInitialMonth();

	/**
	 * prints enter intial year message
	 */
	void printWrongPackagingInitialYear();

	/**
	 * prints enter intial minute message
	 */
	void printWrongPackagingInitialMinute();

	/**
	 * prints enter intial hour message
	 */
	void printWrongPackagingInitialHour();

	/**
	 * prints wrong storage time message
	 */
	void printWrongStorageTime();

	/**
	 * prints wrong nif message
	 */
	void printWrongNIF();

	/**
	 * prints wrong latitude latitude
	 */
	void printWrongLatitude();

	/**
	 * prints wrong longitude latitude
	 */
	void printWrongLongitude();

	/**
	 * prints add to EOM latitude
	 */
	void printAddToEOM();

	/**
	 * prints enter option message
	 */
	void printEnterOption();

	/**
	 * prints wrong option message
	 */
	void printWrongOption();

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
bool RequisitServiceView::getInfo(T& info) {
	return u->readString(info);
}

#endif /* SRC_VIEW_HEADERS_REQUISITSERVICEVIEW_H_ */
