/*
 * SeeVehicleView.h
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#ifndef SRC_SEEVEHICLEVIEW_H_
#define SRC_SEEVEHICLEVIEW_H_

#include <iostream>
#include <string>
#include "Utilities.h"

using namespace std;

class SeeVehicleView {
private:
	Utilities *u;
	const string initialMessage = "\nVer Informaçoes do ve�culo";

	const string end = "\nTerminou Ver Informaçoes do ve�culo";
	void printMessage(const string &message);

public:
	SeeVehicleView();
	virtual ~SeeVehicleView();

	/**
	 * prints see service initial message
	 */
	void printInitialMessage();

	/**
	 * prints service information message
	 */
	void printInformation(const string &information);

	void printEnd();
	/**
	 * reads string from keyboard
	 */
	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool SeeVehicleView::getInfo(T &info) {
	return u->readString(info);
}
#endif /* SRC_SEEVEHICLEVIEW_H_ */
