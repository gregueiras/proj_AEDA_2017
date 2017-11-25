/*
 * Validation.h
 *
 *  Created on: 25/10/2017
 *      Author: jotaa
 */

#ifndef VALIDATION_H_
#define VALIDATION_H_

#include <iostream>
#include <regex>

using namespace std;

class Validation {
private:
	string emailRegex =
			"^[_a-z0-9-]+(\\.[_a-z0-9-]+)*@[a-z0-9-]+(\\.[a-z0-9-]+)*(\\.[a-z]{2,4})$";
	string dateRegex = ".*\\d{1,2}[-/. ]\\d{1,2}[-/. ]\\d{1,4}.*";
	string hourRegex = "^([0-9]|[0-1][0-9]|2[0-3])([]|:[0-5]|:[0-5][0-5])?$";
	string longitudeRegex =
			"^(\\+|-)?(?:180(?:(?:\\.0{1,6})?)|(?:[0-9]|[1-9][0-9]|1[0-7][0-9])(?:(?:\\.[0-9]{1,6})?))$";
	string latitudeRegex =
			"^(\\+|-)?(?:90(?:(?:\\.0{1,6})?)|(?:[0-9]|[1-8][0-9])(?:(?:\\.[0-9]{1,6})?))$";
	string nifRegex = "^[0-9]{9}$";
//	string idRegex = "^[1-9][0-9]*$";
	string idRegex = "^\\d$";
public:
	bool validateDateFormat(const string date);
	bool validateHourFormat(const string hour);
	bool validateEMailFormat(const string email);
	bool validateLatitudeFormat(const string latitude);
	bool validateLongitudeFormat(const string longitude);
	bool validateNIFFormat(const string nif);
	bool validateIDFormat(const string id);

	bool validateBound(const int option, const int lowerBound,
			const int upperBound);
}
;

/* namespace std */

#endif /* VALIDATION_H_ */
