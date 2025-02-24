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
	const string vehicleList = "\nListagem dos ve�culos:";
	const string vehicleMenu =
			"\nMenu Ve�culos\n0->SAIR\n1->Adicionar Novo Ve�culo\n2->Ver Informa��es do Ve�culo\n3->Alterar Informa��es do Ve�culo\n4->Enviar Ve�culo para Manuten��o\n5->Remover Ve�culo\n6->Voltar Atr�s";
	const string enterOption = "Introduza a sua opcao";
	const string wrongOption = "Opcao escolhida invalida";
	const string enterPlate = "Introduza a matricula do ve�culo";
	const string plateNotFound = "Ve�culo com a matricula dada n�o encontrado";
	const string vehicleNotAvailable = "Ve�culo n�o est� dispon�vel";
	const string noVehicleRegistered = "Nao ha ve�culos registados no sistema";

	const string end = "Terminou Menu Ve�culos";
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
