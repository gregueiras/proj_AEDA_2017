/*
 * SeeServicesView.h
 *
 *  Created on: 25 Dec 2017
 *      Author: jotaa
 */

#ifndef SRC_SEESERVICESVIEW_H_
#define SRC_SEESERVICESVIEW_H_

#include <iostream>
#include <string>
using namespace std;

class SeeServicesView {
private:
	const string initialMessage = "\nListagem de Serviços dos Clientes";
	const string listServices = "\nListagem dos serviços registados:";
	const string noServicesRegistered =
			"\nNão ha servicos registados no sistema";
	const string end = "Terminou Listagem de Serviços dos Clientes";
	const string shutdown = "\nPrograma terminou";

	void printMessage(const string &message);

public:
	SeeServicesView();
	virtual ~SeeServicesView();

	/**
	 * prints see service initial message
	 */
	void printInitialMessage();

	/**
	 * prints service information message
	 */
	void printInformation(const string &information);

	/**
	 * prints shutdown message
	 */
	void printShutdown() const;

	void printListServices();
	void printNoServicesRegistered();
	/**
	 * prints end message
	 */
	void printEnd();
};

#endif /* SRC_SEESERVICESVIEW_H_ */
