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
	const string vehicleList = "\nListagem dos veículos:";
	const string vehicleMenu =
			"\nMenu Veículos\n0->SAIR\n1->Adicionar Novo Veículo\n2->Ver Informações do Veículo\n3->Alterar Informações do Veículo\n4->Enviar Veículo para Manutenção\n5->Remover Veículo\n6->Voltar Atrás";
	const string enterOption = "Introduza a sua opcao";
	const string wrongOption = "Opcao escolhida invalida";
	const string enterPlate = "Introduza a matricula do veículo";
	const string plateNotFound = "Veículo com a matricula dada não encontrado";
	const string vehicleNotAvailable = "Veículo não está disponível";
	const string noVehicleRegistered = "Nao ha veículos registados no sistema";

	const string end = "Terminou Menu Veículos";
	const string shutdown = "\nPrograma terminou";
	void printMessage(const string &message);

public:
	VehicleMenuView();
	virtual ~VehicleMenuView();

	void printVehicleList();
	void printVehicleMenu();
	void printEnterOption();
	void printWrongOption();

	void printEnterPlate();
	void printPlateNotFound();
	void printVehicleNotAvailable();
	void printNoVehicleRegistered();

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
