/*
 * Utilities.h
 *
 *  Created on: 04/11/2017
 *      Author: jotaa
 */

#ifndef SRC_MODEL_UTILITIES_H_
#define SRC_MODEL_UTILITIES_H_

#include <iostream>
#include <limits>
#include <time.h> 

#include "Services.h"
#include "Vehicle.h"
#include "Date.h"
#include "Hour.h"


using namespace std;

class Utilities {
public:
	Utilities();
	virtual ~Utilities();

	template<typename T> bool readString(T &s);

	bool isCapitalDistrito(const string city);

	Date lastDayofMonth(unsigned int month, unsigned int year);
	string readLine();
};

template<typename T>
bool Utilities::readString(T &s) {
	cin >> s;

	//validate string
	if (cin.fail()) {
		if (cin.eof()) {
		} else {
			cin.clear(); // reset failbit, clear error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear input buffer
		}
		return false;
	} else {
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear input buffer
	}
	return true;
}

namespace Sort {

/**
 * Auxiliary for SortByDate
 * @param a1 lhs service
 * @param a2 rhs service
 * @return True a1 < a2, false if a1>=a2
 */
bool auxSortbyDate(Services* a, Services* b);

/**
 * Auxiliary for SortByPrice
 * @param a1 lhs service
 * @param a2 rhs service
 * @return True a1 < a2, false if a1>=a2
 */
bool auxSortbyPrice(Services* a, Services* b);

/**
 * Auxiliary for SortByVolume
 * @param a1 lhs service
 * @param a2 rhs service
 * @return True a1 < a2, false if a1>=a2
 */
bool auxSortbyVolume(Services* a, Services* b);

/**
 * Auxiliary for SortByDistance
 * @param a1 lhs service
 * @param a2 rhs service
 * @return True a1 < a2, false if a1>=a2
 */
bool auxSortbyDistance(Services* a, Services* b);

/**
 * Auxiliary for SortByID
 * @param a1 lhs service
 * @param a2 rhs service
 * @return True a1 ID < a2 ID, false if a1 ID >= a2 ID
 */
bool auxSortbyID(Services* a, Services* b);

/**
 * Auxiliary for SortbyMaintenanceDate
 * @param a lhs vehicle
 * @param b rhs vehicle
 * @return True if a has to go to maintenance before b, false otherwise
 */
bool auxSortbyMaintenanceDate(Vehicle a, Vehicle b);

}

/**
 * Auxiliary for Banking Specs on Company
 * @param length size of return
 * @return string of numbers with size == length
 */
string generateRandom(int length);

/**
* Gets current Timezone Date
* @return current Timezone Date
*/
Date getTimeZoneDate();

/**
* Gets current Timezone Hour
* @return current Timezone Hour
*/
Hour getTimeZoneHour();

#endif /* SRC_MODEL_UTILITIES_H_ */
