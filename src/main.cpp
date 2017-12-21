/*
 * main.cpp
 *
 *  Created on: 16/11/2017
 *      Author: jotaa
 */
#include "EnterController.h"
#include "EnterView.h"

int main() {
	cout << "INICIO----------------------" << endl;

	//Address a1("Rua", "Portugal", "Porto", "Lisboa", 1);
	//Address a2("RuaB", "Portugal", "Beja", "Beja", 2);
	//Address a3("RuaC", "Portugal", "Beja", "Beja", 3);
	//Address a4("RuaD", "Portugal", "Porto", "Lisboa", 4);
	//Address a5("RuaE", "Portugal", "Braga", "Braga", 5);
	//Address a6("RuaF", "Portugal", "Aveiro", "Aveiro", 6);

	//Client* p1 = new Personal("Joao", a1, 456789123, "a");

	//Services* s1 = new Services(a1, 40, a2, Hour(8, 30), Date(5, 10, 2017));
	//Services* s2 = new Services(a3, 50, a4, Hour(9, 00), Date(5, 11, 2017));
	//Services* s3 = new Services(a5, 30, a6, Hour(9, 30), Date(5, 5, 2017));
	//s1->getId();

	//p1->addServices(s1);
	//p1->addServices(s2);
	//p1->addServices(s3);

	//Company *c1 = new Company("2020 0000 4030 6790 3012 3", "10345",
	//		"129654342");

//	cout << "Utilizador pessoal" << endl;
//	cout << "ID: " << p1->getId() << endl;
//	cout << "pass: " << p1->getPass() << endl;
	
	Company* c1 = new Company();
	
	c1->readCompanyFromFile();
	

	//c1->addClient(p1);
//
	c1->readClientsFromFile();
	
	c1->readVehiclesFromFile();
	


	//cout << c1->getNib() << endl;

	//SortServicesController *sortServicesController = new SortServicesController(
//	sortServicesController->menu();

	EnterController enter = EnterController(c1);
	
	enter.menu();

	c1->writeCompanyToFile();
	c1->writeClientsToFile();
	c1->writeVehiclesToFile();


}
