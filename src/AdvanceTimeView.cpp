/*
 * AdvanceTimeView.cpp
 *
 *  Created on: 4 Jan 2018
 *      Author: jotaa
 */

#include "AdvanceTimeView.h"

AdvanceTimeView::AdvanceTimeView() {
	u = new Utilities();
}

AdvanceTimeView::~AdvanceTimeView() {
	// TODO Auto-generated destructor stub
}

void AdvanceTimeView::printMessage(const string& message) {
	cout << message << endl;
}
void AdvanceTimeView::printAdvanceTimeMenu() {
	printMessage(advanceTimeMenu);
}

void AdvanceTimeView::printEnterOption() {
	printMessage(enterOption);
}

void AdvanceTimeView::printWrongOption() {
	printMessage(wrongOption);
}

void AdvanceTimeView::printEnd() {
	printMessage(end);
}

void AdvanceTimeView::printShutdown() {
	printMessage(shutdown);
}

void AdvanceTimeView::printEnterNewCurrentDate() {
	printMessage(enterNewCurrentDate);
}

void AdvanceTimeView::printEnterNewCurrentDay() {
	printMessage(enterNewCurrentDay);
}

void AdvanceTimeView::printEnterNewCurrentMonth() {
	printMessage(enterNewCurrentMonth);
}

void AdvanceTimeView::printEnterNewCurrentYear() {
	printMessage(enterNewCurrentYear);
}

void AdvanceTimeView::printEnterNewCurrentTime() {
	printMessage(enterNewCurrentTime);
}

void AdvanceTimeView::printEnterNewCurrentHour() {
	printMessage(enterNewCurrentHour);
}

void AdvanceTimeView::printEnterNewCurrentMinute() {
	printMessage(enterNewCurrentMinute);
}

void AdvanceTimeView::printCurrentDate(const string date) {
	cout << currentDate << date << endl;
}

void AdvanceTimeView::printCurrentTime(const string time) {
	cout << currentTime << time << endl;
}
