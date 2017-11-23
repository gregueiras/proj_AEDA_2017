/*
 * FilterServicesView.h
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#ifndef SRC_VIEW_HEADERS_FILTERSERVICESVIEW_H_
#define SRC_VIEW_HEADERS_FILTERSERVICESVIEW_H_

#include <iostream>
#include "Utilities.h"

using namespace std;

class FilterServicesView {
private:
	Utilities *u;
	const string enterOption = "Introduza a sua opcao";
	const string wrongOption = "Opcao escolhida invalida";

	const string filterMenu =
			"\nMenu Filtrar\n1->intervalo de id\n2->intevalo de tempo\n3->intervalo de volume\n4->intervalo de distancia\n5->intervalo de preco\n6->cidade\n7->filtrar\n0->SAIR";
	const string enterIdInterval =
			"Introduza intervalo de id (idInferior idSuperior)";
	const string enterDateInferiorBound =
			"Introduza data limite inferior (dd mm aaaa)";
	const string enterDateSuperiorBound =
			"Introduza data limite superior (dd mm aaaa)";
	const string enterVolumeInterval =
			"Introduza intervalo de volume (volumeInferior volumeSuperior)";
	const string enterDistanceInterval =
			"Introduza intervalo de distancia (distanciaInferior distanciaSuperior)";
	const string enterPriceInterval =
			"Introduza intervalo de preco (precoInferior precoSuperior)";
	const string enterCity = "Introduza cidade";
	const string wrongDate = "Data introduzida invalida";
	const string wrongTimeInterval = "Data introduzida invalido";
	const string wrongVolumeInterval =
			"Intervalo de volume introduzido invalido";
	const string wrongDistanceInterval =
			"Intervalo de distancia introduzido invalido";
	const string wrongPriceInterval = "Intervalo de preco introduzido invalido";
	const string wrongCity = "cidade introduzida invalido";

	const string end = "\nTerminou Menu Cliente";
	void printMessage(const string &message);

public:
	FilterServicesView();
	virtual ~FilterServicesView();

	/**
	 * prints user menu initial message
	 */
	void printFilterMenu();

	/**
	 * prints enter option message
	 */
	void printEnterOption();

	/**
	 * prints wrong option message
	 */
	void printWrongOption();

	/**
	 * prints enter id interval message
	 */
	void printEnterIdInterval();

	/**
	 * prints enter date inferior bound message
	 */
	void printEnterDateInferiorBound();

	/**
	 * prints enter date superior bound message
	 */
	void printEnterDateSuperiorBound();

	/**
	 * prints enter volume interval message
	 */
	void printEnterVolumeInterval();

	/**
	 * prints enter price interval message
	 */
	void printEnterPriceInterval();

	/**
	 * prints enter distance interval message
	 */
	void printEnterDistanceInterval();

	/**
	 * prints enter city message
	 */
	void printEnterCity();

	/**
	 * prints wrong option message
	 */
	void printWrongTimeInterval();

	/**
	 * prints wrong date message
	 */
	void printWrongDate();

	/**
	 * prints wrong volume message
	 */
	void printWrongVolmeInterval();

	/**
	 * prints wrong distance message
	 */
	void printWrongDistanceInterval();

	/**
	 * prints wrong price message
	 */
	void printWrongPriceInterval();

	/**
	 * prints wrong city message
	 */
	void printWrongCity();

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
bool FilterServicesView::getInfo(T &info) {
	return u->readString(info);
}
#endif /* SRC_VIEW_HEADERS_FILTERSERVICESVIEW_H_ */
