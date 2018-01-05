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

	const string changeVehicleMenu =
			"Menu Alterar Ve�culo\n0->SAIR\n1->matr�cula\n2->marca\n3->modelo\n4->data de constru��o\n5->tempo expecctavel de espera na manuten�ao"
					"\n6->proxima data de manuten�ao\n7->voltar atras";
	const string enterOption = "Introduza a sua op��o";
	const string wrongOption = "Op��o introduzida errada";

	const string enterNewPlate = "Introduza nova matricula 0->SAIR";
	const string enterNewBrand = "Introduza nova marca 0->SAIR";
	const string enterNewModel = "Introduza novo modelo 0->SAIR";

	const string enterNewBirthdayDate =
			"Introduza nova data de constru��o 0->SAIR";
	const string enterNewBirthdayDay =
			"Introduza novo dia de constru�ao do carro 0->SAIR";
	const string enterNewBirthdayMonth =
			"Introduza novo mes de constru�ao do carro 0->SAIR";
	const string enterNewBirthdayYear =
			"Introduza novo ano de constru�ao do carro 0->SAIR";

	const string enterNewExpectableTime =
			"Introduza novo tempo expectavel de manuten��o 0->SAIR";
	const string enterNewExpectableHour =
			"Introduza novo numero de horas expectaveis em que o ve�culo voltar� a ficar disponivel 0->SAIR";
	const string enterNewExpectableMinute =
			"Introduza novo numero de minutos expectaveis em que o ve�culo voltar� a ficar disponivel 0->SAIR";

	const string enterNewMaintenanceDate =
			"Introduza nova data de manuten�ao 0->SAIR";
	const string enterNewMaintenanceDay =
			"Introduza novo dia da proxima manuten�ao do carro 0->SAIR";
	const string enterNewMaintenanceMonth =
			"Introduza novo mes da proxima manuten�ao do carro 0->SAIR";
	const string enterNewMaintenanceYear =
			"Introduza novo ano da proxima manuten�ao do carro 0->SAIR";

	const string end = "Terminou Menu Alterar Ve�culo";
	const string shutdown = "Terminou programa";
	void printMessage(const string& message);
public:
	ChangeVehicleView();
	virtual ~ChangeVehicleView();

	/**
	 * prints change vehicle menu message
	 */
	void printChangeVehicleMenu();
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
	 * prints enter new plate message
	 */
	void printEnterNewPlate();
	/**
	 * prints enter new brand message
	 */
	void printEnterNewBrand();
	/**
	 * prints enter new model message
	 */
	void printEnterNewModel();

	/**
	 * prints enter new date message
	 */
	void printEnterNewBirthdayDate();
	/**
	 * prints enter new day message
	 */
	void printEnterNewBirthdayDay();
	/**
	 * prints enter new month message
	 */
	void printEnterNewBirthdayMonth();
	/**
	 * prints enter new year message
	 */
	void printEnterNewBirthdayYear();

	/**
	 * prints enter new expectable time message
	 */
	void printEnterNewExpectableTime();
	/**
	 * prints enter new expectable hour message
	 */
	void printEnterNewExpectableHour();
	/**
	 * prints enter new expectable minute message
	 */
	void printEnterNewExpectableMinute();

	/**
	 * prints enter new maintenance date message
	 */
	void printEnterNewMaintenanceDate();
	/**
	 * prints enter new maintenance day message
	 */
	void printEnterNewMaintenanceDay();
	/**
	 * prints enter new maintenance month message
	 */
	void printEnterNewMaintenanceMonth();
	/**
	 * prints enter new maintenance year message
	 */
	void printEnterNewMaintenanceYear();

	/**
	 * prints information
	 * @information information to print
	 */
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
