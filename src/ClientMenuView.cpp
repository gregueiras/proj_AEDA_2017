/*
 * ClientMenuView.cpp
 *
 *  Created on: 06/11/2017
 *      Author: jotaa
 */

#include "ClientMenuView.h"

ClientMenuView::ClientMenuView() {
	u = new Utilities();
}

ClientMenuView::~ClientMenuView() {
}

void ClientMenuView::printMessage(const string &message) {
	cout << message << endl;
}

void ClientMenuView::printEnterOption() {
	printMessage(enterOption);

}
void ClientMenuView::printWrongOption() {
	printMessage(wrongOption);

}
void ClientMenuView::printEnd() {
	printMessage(end);
}
void ClientMenuView::printClientMenu() {
	printMessage(clientMenu);
}

void ClientMenuView::printShutdown() {
	printMessage (shutdown);
}
