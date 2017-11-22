/*
 * NewUserController.h
 *
 *  Created on: 04/11/2017
 *      Author: jotaa
 */

#ifndef SRC_CONTROLLER_NEWUSERCONTROLLER_H_
#define SRC_CONTROLLER_NEWUSERCONTROLLER_H_

#include "NewUserView.h"
#include "Validation.h"
#include "Client.h"
#include "Personal.h"
#include "Business.h"
#include "Company.h"
#include "Address.h"
#include "EnterController.h"
#include "Utilities.h"

using namespace std; 

class NewUserController {
private:
	NewUserView *theView;
	Validation *v;
	Utilities *u;
	Company *company;

	const unsigned int client_type_personal = 1;
	const unsigned int client_type_business = 2;

	void getUserInformation(unsigned int &userType, string &name,
			unsigned int &nif, string &street, string &country, string &city,
			string &county, unsigned int &doorNumber, double &latitude,
			double &longitude, string &password);
	

	unsigned int getUserType();
	string getName();
	unsigned int getNIF();
	string getStreet();
	string getCountry();
	string getCity();
	string getCounty();
	unsigned int getDoorNumber();
	double getLatitude();
	double getLongitude();
	string getPassword();

	void createUser(unsigned int &userType, string &name, unsigned int &nif,
			string &street, string &country, string &city, string &county,
			unsigned int &doorNumber, double &latitude, double &longitude,
		    string &password);

	template<typename T> void getInfo(T &info);

	void endProgram();
	void newEnterController();

public:
	NewUserController(Company *company);
	virtual ~NewUserController();
	void menu();
};

template<typename T>
void NewUserController::getInfo(T &info) {
	if (!theView->getInfo(info)) { //ctrlz, fim do ficheiro
		theView->printEnd();
		newEnterController();
	}
}
#endif /* SRC_CONTROLLER_NEWUSERCONTROLLER_H_ */
