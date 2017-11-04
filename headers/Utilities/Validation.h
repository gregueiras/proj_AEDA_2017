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
			"^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,4})$";
	string dateRegex =
			"^(?:(?:31(\/|-|\.)(?:0?[13578]|1[02]))\1|(?:(?:29|30)(\/|-|\.)(?:0?[1,3-9]|1[0-2])\2))(?:(?:1[6-9]|[2-9]\d)?\d{2})$|^(?:29(\/|-|\.)0?2\3(?:(?:(?:1[6-9]|[2-9]\d)?(?:0[48]|[2468][048]|[13579][26])|(?:(?:16|[2468][048]|[3579][26])00))))$|^(?:0?[1-9]|1\d|2[0-8])(\/|-|\.)(?:(?:0?[1-9])|(?:1[0-2]))\4(?:(?:1[6-9]|[2-9]\d)?\d{2})$";
	string hourRegex = "^([0-9]|[0-1][0-9]|2[0-3])([]|:[0-5]|:[0-5][0-5])?$";
public:
	bool validateDate(const string date);
	bool validateDateFormat(const string date);
	bool validateHourFormat(const string hour);
	bool validateEMailFormat(const string email);
}
;

/* namespace std */

#endif /* VALIDATION_H_ */
