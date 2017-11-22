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
#include "Services.h"

using namespace std;

class Utilities {
public:
	Utilities();
	virtual ~Utilities();
	
	template<typename T>string toString(const T &value);

	template<typename T> bool readString(T &s);


	bool isCapitalDistrito(const string city);
};



template<typename T>
bool Utilities::readString(T &s) {
	cin >> s;

	//validate string
	if (cin.fail()) {
		if (cin.eof()) {
			return false;
		}
		else {
			cin.clear(); // reset failbit, clear error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear input buffer
		}
	}
	else {
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

}

#endif /* SRC_MODEL_UTILITIES_H_ */
