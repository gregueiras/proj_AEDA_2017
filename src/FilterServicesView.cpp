/*
 * FilterServicesView.cpp
 *
 *  Created on: 15/11/2017
 *      Author: jotaa
 */

#include "FilterServicesView.h"

FilterServicesView::FilterServicesView() {
	u = new Utilities();
}

FilterServicesView::~FilterServicesView() {
	// TODO Auto-generated destructor stub
}

void FilterServicesView::printMessage(const string& message) {
	cout << message << endl;

}

void FilterServicesView::printFilterMenu() {
	printMessage(filterMenu);

}

void FilterServicesView::printEnterOption() {
	printMessage(enterOption);

}

void FilterServicesView::printWrongOption() {
	printMessage(wrongOption);

}

void FilterServicesView::printEnd() {
	printMessage(end);

}

void FilterServicesView::printEnterIdInterval() {
	printMessage(enterIdInterval);
}

void FilterServicesView::printEnterDateInferiorBound() {
	printMessage(enterDateInferiorBound);
}

void FilterServicesView::printEnterDateSuperiorBound() {
	printMessage(enterDateSuperiorBound);
}

void FilterServicesView::printEnterVolumeInterval() {
	printMessage(enterVolumeInterval);
}

void FilterServicesView::printEnterPriceInterval() {
	printMessage(enterPriceInterval);
}

void FilterServicesView::printEnterDistanceInterval() {
	printMessage(enterDistanceInterval);
}

void FilterServicesView::printEnterCity() {
	printMessage(enterCity);
}

void FilterServicesView::printWrongTimeInterval() {
	printMessage(wrongTimeInterval);
}

void FilterServicesView::printWrongVolmeInterval() {
	printMessage(wrongVolumeInterval);
}

void FilterServicesView::printWrongDistanceInterval() {
	printMessage(wrongDistanceInterval);
}

void FilterServicesView::printWrongPriceInterval() {
	printMessage(wrongPriceInterval);
}

void FilterServicesView::printWrongCity() {
	printMessage(wrongCity);
}

void FilterServicesView::printWrongDate() {
	printMessage(wrongDate);
}
