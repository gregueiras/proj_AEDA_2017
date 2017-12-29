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
			"Menu Ve�culos \n1->Adicionar Ve�culo\n2->Alterar Ve�culo\n3->Enviar Ve�culo para Manuten��o\n4->Remover Ve�culo\5->Voltar Atr�s";
	const string enterOption = "Introduza a sua opcao";
	const string wrongOption = "Opcao escolhida invalida";
	const string enterPlate = "Introduza a matricula do ve�culo";
	const string plateNotFound = "Ve�culo com a matricula dada n�o encontrado";

	const string end = "\nTerminou Menu Ve�culos";
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
