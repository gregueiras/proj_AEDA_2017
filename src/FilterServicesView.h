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
	const string enterOption = "Introduza a sua opção";
	const string wrongOption = "Opção escolhida invalida";
	const string initialMessage = "\nMenu Filtrar";

	const string filterMenu =
			"\n1->intervalo de id\n2->intevalo de tempo\n3->intervalo de volume\n4->intervalo de distancia\n5->intervalo de preço\n6->cidade\n7->filtrar\n0->SAIR";
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
			"Introduza intervalo de preço (preçoInferior preçoSuperior)";
	const string enterCity = "Introduza cidade";
	const string wrongDate = "Data introduzida invalida";
	const string wrongTimeInterval = "Data introduzida invalido";
	const string wrongVolumeInterval =
			"Intervalo de volume introduzido invalido";
	const string wrongDistanceInterval =
			"Intervalo de distancia introduzido invalido";
	const string wrongPriceInterval = "Intervalo de preço introduzido invalido";
	const string wrongCity = "cidade introduzida invalido";

	const string end = "\nTerminou Menu Cliente";
	void printMessage(const string &message);

public:
	FilterServicesView();
	virtual ~FilterServicesView();

	void printInitialMessage();
	void printFilterMenu();

	void printEnterOption();
	void printWrongOption();

	void printEnterIdInterval();
	void printEnterDateInferiorBound();
	void printEnterDateSuperiorBound();
	void printEnterVolumeInterval();
	void printEnterPriceInterval();
	void printEnterDistanceInterval();

	void printEnterCity();

	void printWrongTimeInterval();
	void printWrongDate();
	void printWrongVolmeInterval();
	void printWrongDistanceInterval();
	void printWrongPriceInterval();
	void printWrongCity();

	void printEnd();

	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool FilterServicesView::getInfo(T &info) {
	return u->readString(info);
}
#endif /* SRC_VIEW_HEADERS_FILTERSERVICESVIEW_H_ */
