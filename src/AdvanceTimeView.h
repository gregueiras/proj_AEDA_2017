/*
 * AdvanceTimeView.h
 *
 *  Created on: 4 Jan 2018
 *      Author: jotaa
 */

#ifndef SRC_ADVANCETIMEVIEW_H_
#define SRC_ADVANCETIMEVIEW_H_

#include <iostream>
#include "Utilities.h"

using namespace std;

class AdvanceTimeView {
private:
	Utilities *u;
	const string advanceTimeMenu =
			"\nMenu Avançar Tempo\n0->SAIR\n1->Avançar Data\n2->Avançar Hora"
					"\n3->Voltar Atras";
	const string enterOption = "Introduza a sua opção";
	const string wrongOption = "Introduziu opcao errada";
	const string currentDate = "data atual: ";
	const string currentTime = "tempo atual: ";

	const string enterNewCurrentDate = "Introduza nova data atual";
	const string enterNewCurrentDay = "Introduza novo dia atual";
	const string enterNewCurrentMonth = "Introduza novo mes atual";
	const string enterNewCurrentYear = "Introduza novo ano atual";

	const string enterNewCurrentTime = "Introduza novo tempo atual";
	const string enterNewCurrentHour = "Introduza nova hora";
	const string enterNewCurrentMinute = "Introduza novo minuto";

	const string end = "Terminou Menu de Avançar Tempo";
	const string shutdown = "\nPrograma terminou";

	void printMessage(const string &message);
public:
	AdvanceTimeView();
	virtual ~AdvanceTimeView();

	void printAdvanceTimeMenu();
	void printCurrentDate(const string date);
	void printCurrentTime(const string time);

	void printEnterOption();
	void printWrongOption();

	void printEnterNewCurrentDate();
	void printEnterNewCurrentDay();
	void printEnterNewCurrentMonth();
	void printEnterNewCurrentYear();

	void printEnterNewCurrentTime();
	void printEnterNewCurrentHour();
	void printEnterNewCurrentMinute();

	void printEnd();
	void printShutdown();

	template<typename T> bool getInfo(T &info);
};

template<typename T>
bool AdvanceTimeView::getInfo(T &info) {
	return u->readString(info);
}
#endif /* SRC_ADVANCETIMEVIEW_H_ */
