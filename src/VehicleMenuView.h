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

	/**
	 * prints vehicle list messagem
	 */
	void printVehicleList();

	/**
	 * prints vehicle menu
	 */
	void printVehicleMenu();

	/**
	 * prints enter option message
	 */
	void printEnterOption();

	/**
	 * prints wrong option message
	 */
	void printWrongOption();

	/**
	 * prints enter plate message
	 */
	void printEnterPlate();

	/**
	 * prints plate not found message
	 */
	void printPlateNotFound();

	/**
	 * prints vehicle not available message
	 */
	void printVehicleNotAvailable();

	/**
	 * prints no vehicle registered message
	 */
	void printNoVehicleRegistered();

	/**
	 * prints end message
	 */
	void printEnd();
	/**
	 * prints shutdown message
	 */
	void printShutdown();

	/**
	 * prints information
	 * @param info information to print
	 */
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
