/*
 * LoginView.h
 *
 *  Created on: 03/11/2017
 *      Author: jotaa
 */

#ifndef SRC_VIEW_LOGINVIEW_H_
#define SRC_VIEW_LOGINVIEW_H_

#include <iostream>
#include "Validation.h"
#include "Utilities.h"

using namespace std;

class LoginView {
private:
	Utilities *u;
	const string initialMessage = "\nLogin";

	const string enterID = "Introduza id";
	const string enterPass = "Introduza pass";
	const string userNotFound = "Utilizador nao encontrado";
	const string wrongUserId = "ID introduzido invalido";
	const string exit = " 0->SAIR";
	const string end = "Terminou Login";
	const string shutdown = "\nPrograma terminou";
	void printMessage(const string &message);

public:
	LoginView();
	virtual ~LoginView();

	/**
	 * prints user menu initial message
	 */
	void printInitialMessage();

	/**
	 * prints enter id message
	 */
	void printEnterID();

	/**
	 * prints enter password message
	 */
	void printEnterPassword();

	/**
	 * prints user not found message
	 */
	void printUserNotFound();

	/**
	 * prints wrong user id message
	 */
	void printWrongUserID();

	/**
	 * prints end message
	 */
	void printEnd();

	/**
	 * print shutdown message
	 */
	void printShutdown();

	/**
	 * reads string from keyboard
	 */
	template<typename T> bool getInfo(T &info);

	string readLine();
};

template<typename T>
bool LoginView::getInfo(T &info) {
	return u->readString(info);
}
/* namespace std */

#endif /* SRC_VIEW_LOGINVIEW_H_ */
