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
	const string initialMessage = "\nRequisitar Novo Serviço";

	const string originAddress = "\nIntroduza o endereço de origem. ";
	const string destinationAddress = "\nIntroduza o endereço de destino. ";

	const string enterVolume = "Introduza o volume da mercadoria. ";
	const string enterStreet = "Introduza Nome da Rua. ";
	const string enterCountry = "Introduza País. ";
	const string enterCity = "Introduza Cidade. ";
	const string enterCounty = "Introduza Município. ";
	const string enterDoorNumber = "Introduza Número da Rua. ";
	const string enterLatitude = "Introduza Latitude. ";
	const string enterLongitude = "Introduza Longitude. ";

	const string enterPackagingInitialDate =
			"Introduza data de início do embalamento";
	const string enterPackagingInitialDay =
			"Introduza dia de início do embalamento";
	const string enterPackagingInitialMonth =
			"Introduza mes de início do embalamento";
	const string enterPackagingInitialYear =
			"Introduza ano de início do embalamento";
	const string enterPackagingInitialTime =
			"Introduza tempo de início do embalamento";
	const string enterPackagingInitialHour =
			"Introduza hora de início do embalamento";
	const string enterPackagingInitialMinute =
			"Introduza minuto de início do embalamento. ";

	const string enterStorageTime = "Introduza o tempo de armazenamento";
	const string enterVehicleExpectedTime =
			"Introduza o tempo expectavel para o veículo voltar a estar disponivel";
	const string enterVehicleExpectedHour =
			"Introduza o tempo expectavel para o veículo voltar a estar disponivel";
	const string enterVehicleExpectedMinute =
			"Introduza o tempo expectavel para o veículo voltar a estar disponivel";

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

	const string addToEOM = "Pretende deixar para o fim do mes?\n1->Sim\n2->Nao";
	const string schedulingForDateRequired =
			"Agendamento continua para a data que o cliente pediu";
	const string schedulingForBriefTime =
			"Devido a não haver veículos disponíveis, serviço vai ser agendado para o mais brevemente possível";

	const string enterOption = "Introduza a sua opção";
	const string wrongOption = "Opçao introduzida invalida";

	const string exit = "0->SAIR";
	const string end = "Terminou Requesitar Serviço";
	const string shutdown = "\nPrograma terminou";
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
	void printOriginAddress();

	/**
	 * prints arrival address message
	 */
	void printDestinationAddress();

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
	 * prints enter packaging initial day message
	 */
	void printEnterPackagingInitialDay();

	/**
	 * prints enter packaging initial month message
	 */
	void printEnterPackagingInitialMonth();

	/**
	 * prints enter packaging initial year message
	 */
	void printEnterMaintenanceYear();

	/**
	 * prints enter packaging initial time message
	 */
	void printEnterPackagingInitialTime();

	/**
	 * prints enter packaging initial hour message
	 */
	void printEnterPackagingInitialHour();

	/**
	 * prints enter packaging initial minute message
	 */
	void printEnterPackagingInitialMinute();

	/**
	 * prints enter storage time message
	 */
	void printEnterStorageTime();

	/**
	 * prints enter volume message
	 */
	void printEnterVolume();

	/**
	 * prints enter vehicle expected time message
	 */
	void printEnterVehicleExpectedTime();

	/**
	 * prints enter vehicle expected hour message
	 */
	void printEnterVehicleExpectedHour();

	/**
	 * prints enter vehicle expected minute message
	 */
	void printEnterVehicleExpectedMinute();

	/**
	 * prints scheduling for date required message
	 */
	void printSchedulingForDateRequired();

	/**
	 * prints scheduling for brief time message
	 */
	void printSchedulingForBriefTime();

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
	void printAskAddToEOM();

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
	 * prints shutdown message
	 */
	void printShutdown();

	/**
	 * reads string from keyboard
	 */
	string getLine();

	/**
	 * reads string from keyboard
	 */
	template<typename T> bool getInfo(T &info);
}
;

template<typename T>
bool RequisitServiceView::getInfo(T& info) {
	return u->readString(info);
}

#endif /* SRC_VIEW_HEADERS_REQUISITSERVICEVIEW_H_ */
