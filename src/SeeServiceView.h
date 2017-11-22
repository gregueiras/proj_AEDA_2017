/*
 * SeeServiceView.h
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#ifndef SRC_VIEW_SRC_SEESERVICEVIEW_H_
#define SRC_VIEW_SRC_SEESERVICEVIEW_H_

#include  "ClientMenuView.h"
#include  "Validation.h"
#include "ListServicesController.h"
#include "Client.h"

#include <string>
using std::string;

class SeeServiceView {
private:
	const string initialMessage = "\nVer Informa��es do cliente";

	const string end = "\nTerminou Menu Cliente";
	void printMessage(const string &message);

public:
	SeeServiceView();
	virtual ~SeeServiceView();

	void printInitialMessage();
	void printServiceInformation(const string &information);
	void printEnd();
};

#endif /* SRC_VIEW_SRC_SEESERVICEVIEW_H_ */
