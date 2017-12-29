/*
 * VehicleMenuView.h
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#ifndef SRC_VEHICLEMENUVIEW_H_
#define SRC_VEHICLEMENUVIEW_H_

#include <iostream>
#include "Utilities.h"

using namespace std;

class VehicleMenuView {
private:
	Utilities *u;
	const string vehicleMenu =
			"Menu Veículos \n1->Adicionar Veículo\n2->Alterar Veículo\n3->Enviar Veículo para Manutenção\n4->Remover Veículo\5->Voltar Atrás";
	const string enterOption = "Introduza a sua opcao";
	const string wrongOption = "Opcao escolhida invalida";
	const string enterPlate = "Introduza a matricula do veículo";
	const string plateNotFound = "Veículo com a matricula dada não encontrado";

	const string end = "\nTerminou Menu Veículos";
	const string shutdown = "\nPrograma terminou";
	void printMessage(const string &message);

public:
	VehicleMenuView();
	virtual ~VehicleMenuView();

	void printVehicleMenu();
	void printEnterOption();
	void printWrongOption();

	void printEnterPlate();
	void printPlateNotFound();

	void printEnd();
	void printShutdown();

	void printInformation(const string info);

	/**
	 * reads string from keyboard
	 */
	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool VehicleMenuView::getInfo(T &info) {
	return u->readString(info);
}

#endif /* SRC_VEHICLEMENUVIEW_H_ */
