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

void FilterServicesView::printEnterIDInterval() {
	printMessage(enterIdInterval);
}

void FilterServicesView::printEnterIDInferiorBound() {
	printMessage(enterIdInferiorBound);
}

void FilterServicesView::printEnterIDSuperiorBound() {
	printMessage(enterIdSuperiorBound);
}

void FilterServicesView::printEnterDateInterval() {
	printMessage(enterDateInterval);
}

void FilterServicesView::printEnterDateInferiorBound() {
	printMessage(enterDateInferiorBound);
}

void FilterServicesView::printEnterDayInferiorBound() {
	printMessage(enterDayInferiorBound);
}

void FilterServicesView::printEnterMonthInferiorBound() {
	printMessage(enterMonthInferiorBound);
}

void FilterServicesView::printEnterYearInferiorBound() {
	printMessage(enterYearInferiorBound);
}

void FilterServicesView::printEnterDateSuperiorBound() {
	printMessage(enterDateSuperiorBound);
}

void FilterServicesView::printEnterDaySuperiorBound() {
	printMessage(enterDaySuperiorBound);
}

void FilterServicesView::printEnterMonthSuperiorBound() {
	printMessage(enterMonthSuperiorBound);
}

void FilterServicesView::printEnterYearSuperiorBound() {
	printMessage(enterYearSuperiorBound);
}

void FilterServicesView::printEnterVolumeInterval() {
	printMessage(enterVolumeInterval);
}

void FilterServicesView::printEnterVolumeInferiorBound() {
	printMessage(enterVolumeInferiorBound);
}

void FilterServicesView::printEnterVolumeSuperiorBound() {
	printMessage(enterVolumeSuperiorBound);
}

void FilterServicesView::printEnterPriceInterval() {
	printMessage(enterPriceInterval);
}

void FilterServicesView::printEnterPriceInferiorBound() {
	printMessage(enterDistanceInferiorBound);
}

void FilterServicesView::printEnterPriceSuperiorBound() {
	printMessage(enterDistanceSuperiorBound);
}

void FilterServicesView::printEnterDistanceInterval() {
	printMessage(enterDistanceInterval);
}

void FilterServicesView::printEnterDistanceInferiorBound() {
	printMessage(enterPriceInferiorBound);
}

void FilterServicesView::printEnterDistanceSuperiorBound() {
	printMessage(enterPriceSuperiorBound);
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

void FilterServicesView::printShutdown() {
	printMessage(shutdown);
}
