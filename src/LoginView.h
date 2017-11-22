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
	const string exit = "\n0->SAIR";
	const string end = "\nTerminou Login";
	void printMessage(const string &message);

public:
	LoginView();
	virtual ~LoginView();

	void printInitialMessage();
	void printEnterID();
	void printEnterPassword();
	void printUserNotFound();
	void printWrongUserID();
	void printEnd();

	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool LoginView::getInfo(T &info) {
	return u->readString(info);
}
/* namespace std */

#endif /* SRC_VIEW_LOGINVIEW_H_ */
