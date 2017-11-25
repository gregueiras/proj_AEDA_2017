/*
 * LoginView.cpp
 *
 *  Created on: 03/11/2017
 *      Author: jotaa
 */

#include "LoginView.h"

LoginView::LoginView() {
	u = new Utilities();
}

LoginView::~LoginView() {
}

void LoginView::printMessage(const string &message) {
	cout << message << endl;
}

void LoginView::printInitialMessage() {
	printMessage(initialMessage);
}

void LoginView::printEnterID() {
	printMessage(enterID + exit);
}

void LoginView::printEnterPassword() {
	printMessage(enterPass + exit);
}

void LoginView::printUserNotFound() {
	printMessage(userNotFound);
}
void LoginView::printWrongUserID() {
	printMessage(wrongUserId);
}

void LoginView::printEnd() {
	printMessage(end);
}

void LoginView::printShutdown() {
	printMessage(shutdown);
}

string LoginView::readLine() {
	return u->readLine();
}

/* namespace std */
