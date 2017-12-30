/*
 * ChangeVehicleView.h
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#ifndef SRC_CHANGEVEHICLEVIEW_H_
#define SRC_CHANGEVEHICLEVIEW_H_

#include <iostream>
#include "Utilities.h"

class ChangeVehicleView {
private:
	Utilities *u;

	const string initialMessage = "\nAlterar informaçoes do veículo";
	const string changeVehicleMenu =
			"Alterar Veículo\n0->SAIR\n1->matrícula\n2->marca\n3->modelo\n4->data de construção\n5->tempo expecctavel de espera na manutençao"
					"\n6->proxima data de manutençao\n7->voltar atras";
	const string end = "Terminou alterar informaçoes do veículo";
	const string shutdown = "Terminou programa";
	const string enterOption = "Introduza a sua opção";
	const string wrongOption = "Opção introduzida errada";

	const string enterNewPlate = "Introduza nova matricula 0->SAIR";
	const string enterNewBrand = "Introduza nova marca 0->SAIR";
	const string enterNewModel = "Introduza novo modelo 0->SAIR";

	const string enterNewBirthdayDate =
			"Introduza nova data de construção 0->SAIR";
	const string enterNewBirthdayDay =
			"Introduza novo dia de construçao do carro 0->SAIR";
	const string enterNewBirthdayMonth =
			"Introduza novo mes de construçao do carro 0->SAIR";
	const string enterNewBirthdayYear =
			"Introduza novo ano de construçao do carro 0->SAIR";

	const string enterNewExpectableTime =
			"Introduza novo tempo expectavel de manutenção 0->SAIR";
	const string enterNewExpectableHour =
			"Introduza novo numero de horas expectaveis em que o veículo voltará a ficar disponivel 0->SAIR";
	const string enterNewExpectableMinute =
			"Introduza novo numero de minutos expectaveis em que o veículo voltará a ficar disponivel 0->SAIR";

	const string enterNewMaintenanceDate =
			"Introduza nova data de manutençao 0->SAIR";
	const string enterNewMaintenanceDay =
			"Introduza novo dia da proxima manutençao do carro 0->SAIR";
	const string enterNewMaintenanceMonth =
			"Introduza novo mes da proxima manutençao do carro 0->SAIR";
	const string enterNewMaintenanceYear =
			"Introduza novo ano da proxima manutençao do carro 0->SAIR";
	void printMessage(const string& message);
public:
	ChangeVehicleView();
	virtual ~ChangeVehicleView();

	void printInitialMessage();
	void printChangeVehicleMenu();
	void printEnterOption();
	void printWrongOption();
	void printEnd();
	void printShutdown();

	void printEnterNewPlate();
	void printEnterNewBrand();
	void printEnterNewModel();

	void printEnterNewBirthdayDate();
	void printEnterNewBirthdayDay();
	void printEnterNewBirthdayMonth();
	void printEnterNewBirthdayYear();

	void printEnterNewExpectableTime();
	void printEnterNewExpectableHour();
	void printEnterNewExpectableMinute();

	void printEnterNewMaintenanceDate();
	void printEnterNewMaintenanceDay();
	void printEnterNewMaintenanceMonth();
	void printEnterNewMaintenanceYear();

	void printInformation(const string information);
	/**
	 * reads string from keyboard
	 */
	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool ChangeVehicleView::getInfo(T &info) {
	return u->readString(info);
}
#endif /* SRC_CHANGEVEHICLEVIEW_H_ */
