/*
 * main.cpp
 *
 *  Created on: 16/11/2017
 *      Author: jotaa
 */
#include "EnterController.h"
#include "EnterView.h"

int main() {


	Address a1("Rua", "Portugal", "Porto", "Porto", 5);

	Address a2("RuaB", "Portugal", "Lisboa", "Lisboa", 5);

	Personal p1("Joao", a1, 456789123, "a");
	Personal* p2 = &p1;

	Company* c1 = new Company();
	c1->addClient(p2);

	EnterController enter = EnterController(c1);
	enter.menu();


	//Services* s1 = new Services(a1, 50, a2, Hour(8, 50), Date(5, 10, 2017)) ;
	//p1.addServices(s1);

	//int a;
	//cout << (*s1) << endl;
	//
	//cout << (*p1.getServices().at(0)) << endl;
	//cin >> a;

}
