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

	const string filterMenu =
			"\nMenu Filtrar\n0->SAIR\n1->Intervalo de ID\n2->Intervalo de Tempo\n3->Intervalo de Volume\n4->Intervalo de Distancia"
					"\n5->Intervalo de Preço\n6->Cidade\n7->Filtrar\n8->Voltar Atras";

	const string enterIdInterval = "Introduza intervalo de id";
	const string enterIdInferiorBound = "Introduza id limite inferior 0->SAIR";
	const string enterIdSuperiorBound = "Introduza id limite superior 0->SAIR";

	const string enterDateInterval = "Introduza intervalo de datas";
	const string enterDateInferiorBound = "Introduza data limite inferior";
	const string enterDayInferiorBound = "Introduza dia limite inferior 0->SAIR";
	const string enterMonthInferiorBound =
			"Introduza mes limite inferior 0->SAIR";
	const string enterYearInferiorBound =
			"Introduza ano limite inferior 0->SAIR";

	const string enterDateSuperiorBound = "Introduza data limite superior";
	const string enterDaySuperiorBound = "Introduza dia limite superior 0->SAIR";
	const string enterMonthSuperiorBound =
			"Introduza mes limite superior 0->SAIR";
	const string enterYearSuperiorBound =
			"Introduza ano limite superior 0->SAIR";

	const string enterVolumeInterval = "Introduza intervalo de volume";
	const string enterVolumeInferiorBound =
			"Introduza volume limite inferior 0->SAIR";
	const string enterVolumeSuperiorBound =
			"Introduza volume limite superior 0->SAIR";

	const string enterDistanceInterval = "Introduza intervalo de distancia";
	const string enterDistanceInferiorBound =
			"Introduza distancia limite inferior 0->SAIR";
	const string enterDistanceSuperiorBound =
			"Introduza distancia limite superior 0->SAIR";

	const string enterPriceInterval = "Introduza intervalo de preço";
	const string enterPriceInferiorBound =
			"Introduza preço limite inferior 0->SAIR";
	const string enterPriceSuperiorBound =
			"Introduza preço limite superior 0->SAIR";

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
	const string shutdown = "\nPrograma terminou";
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
	void printEnterIDInterval();

	/**
	 * prints enter id inferior bound message
	 */
	void printEnterIDInferiorBound();

	/**
	 * prints enter id superior bound message
	 */
	void printEnterIDSuperiorBound();

	/**
	 * prints enter date interval message
	 */
	void printEnterDateInterval();

	/**
	 * prints enter date inferior bound message
	 */
	void printEnterDateInferiorBound();

	/**
	 * prints enter day  inferior bound message
	 */
	void printEnterDayInferiorBound();

	/**
	 * prints enter month  inferior bound message
	 */
	void printEnterMonthInferiorBound();

	/**
	 * prints enter year inferior bound message
	 */
	void printEnterYearInferiorBound();

	/**
	 * prints enter date superior bound message
	 */
	void printEnterDateSuperiorBound();

	/**
	 * prints enter day superior bound message
	 */
	void printEnterDaySuperiorBound();

	/**
	 * prints enter month superior bound message
	 */
	void printEnterMonthSuperiorBound();

	/**
	 * prints enter year superior bound message
	 */
	void printEnterYearSuperiorBound();

	/**
	 * prints enter volume interval message
	 */
	void printEnterVolumeInterval();

	/**
	 * prints enter year inferior bound message
	 */
	void printEnterVolumeInferiorBound();

	/**
	 * prints enter year superior bound message
	 */
	void printEnterVolumeSuperiorBound();

	/**
	 * prints enter price interval message
	 */
	void printEnterPriceInterval();

	/**
	 * prints enter price inferior bound message
	 */
	void printEnterPriceInferiorBound();

	/**
	 * prints enter price superior bound message
	 */
	void printEnterPriceSuperiorBound();

	/**
	 * prints enter distance interval message
	 */
	void printEnterDistanceInterval();

	/**
	 * prints enter distance inferior bound message
	 */
	void printEnterDistanceInferiorBound();

	/**
	 * prints enter distance superior bound message
	 */
	void printEnterDistanceSuperiorBound();

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
	 * prints shutdown message
	 */
	void printShutdown();

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
