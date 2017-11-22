/*
 * main.cpp
 *
 *  Created on: 16/11/2017
 *      Author: jotaa
 */
#include "EnterController.h"
#include "EnterView.h"

int main() {
	Company* c1= new Company();

	EnterController enter = EnterController(c1);
	enter.menu();
}
