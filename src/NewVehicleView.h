/*
 * NewVehicleView.h
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#ifndef SRC_NEWVEHICLEVIEW_H_
#define SRC_NEWVEHICLEVIEW_H_

#include <iostream>
#include "Utilities.h"

using namespace std;

class NewVehicleView {
private:
	Utilities *u;

	const string initialMessage = "\nAdicionar novo ve�culo 0->SAIR";
	const string enterPlate = "Introduza matricula 0->SAIR";
	const string enterBrand = "Introduza marca 0->SAIR";
	const string enterModel = "Introduza modelo 0->SAIR";

	const string enterBirthdayDate = "Introduza data de constru��o 0->SAIR";
	const string enterBirthdayDay =
			"Introduza dia de constru�ao do carro 0->SAIR";
	const string enterBirthdayMonth =
			"Introduza mes de constru�ao do carro 0->SAIR";
	const string enterBirthdayYear =
			"Introduza ano de constru�ao do carro 0->SAIR";

	const string enterExpectableTime = "Introduza tempo expectavel de   0->SAIR";
	const string enterExpectableHour =
			"Introduza numero de horas expectaveis em que o ve�culo voltar� a ficar disponivel 0->SAIR";
	const string enterExpectableMinute =
			"Introduza numero de minutos expectaveis em que o ve�culo voltar� a ficar disponivel 0->SAIR";

	const string enterMaintenanceDate = "Introduza data de manuten�ao 0->SAIR";
	const string enterMaintenanceDay =
			"Introduza dia da proxima manuten�ao do carro 0->SAIR";
	const string enterMaintenanceMonth =
			"Introduza mes da proxima manuten�ao do carro 0->SAIR";
	const string enterMaintenanceYear =
			"Introduza ano da proxima manuten�ao do carro 0->SAIR";

	const string repeatedVehicle = "Ve�culo introduzido j� existente";

	void printMessage(const string &message);
public:
	NewVehicleView();
	virtual ~NewVehicleView();

	void printInitialMessage();
	void printEnterPlate();
	void printEnterBrand();
	void printEnterModel();

	void printEnterBirthdayDate();
	void printEnterBirthdayDay();
	void printEnterBirthdayMonth();
	void printEnterBirthdayYear();

	void printEnterExpectableTime();
	void printEnterExpectableHour();
	void printEnterExpectableMinute();

	void printEnterMaintenanceDate();
	void printEnterMaintenanceDay();
	void printEnterMaintenanceMonth();
	void printEnterMaintenanceYear();

	void printRepeatedVehicle();

	/**
	 * reads string from keyboard
	 */
	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool NewVehicleView::getInfo(T &info) {
	return u->readString(info);
}

#endif /* SRC_NEWVEHICLEVIEW_H_ */
