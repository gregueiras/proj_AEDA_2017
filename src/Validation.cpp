/*
 * Validation.cpp
 *
 *  Created on: 25/10/2017
 *      Author: jotaa
 */

#include "Validation.h"
#include <iostream>
#include <regex>
#include <ctime>

using namespace std;

bool Validation::validateDateFormat(const string date) {
	regex rgx(dateRegex);
	return regex_match(date.begin(), date.end(), rgx);
}

bool Validation::validateHourFormat(const string hour) {
	regex rgx(hourRegex);
	return regex_match(hour.begin(), hour.end(), rgx);
}
bool Validation::validateEMailFormat(const string email) {
	regex rgx(emailRegex);
	return regex_match(email.begin(), email.end(), rgx);
}
/*
 bool Validation::validateDateFormat(const string date) {
 string givenDay = date.substr(0, date.find_first_of('/'));
 string givenMonth = date.substr(date.find_first_of('/'),
 date.find_last_of('/'));
 string givenYear = date.substr(date.find_last_of('/'), date.size());

 time_t theTime = time(NULL);
 struct tm *aTime = localtime(&theTime);

 string presentDay = to_string(aTime->tm_mday);
 string presentMonth = to_string(aTime->tm_mon + 1);
 string presentYear = to_string(aTime->tm_year + 1900);
 //int hour=aTime->tm_hour;
 //int min=aTime->tm_min;

 if (givenDay < presentDay) {
 return false;
 }
 if (givenMonth < presentMonth) {
 return false;
 }
 if (givenYear < presentYear) {
 return false;
 }
 return true;
 }*/

bool Validation::validateLatitudeFormat(const string latitude) {
	regex rgx(latitudeRegex);
	return regex_match(latitude.begin(), latitude.end(), rgx);
}

bool Validation::validateLongitudeFormat(const string longitude) {
	regex rgx(longitudeRegex);
	return regex_match(longitude.begin(), longitude.end(), rgx);
}

bool Validation::validateNIFFormat(const string nif) {
	regex rgx(nifRegex);
	return regex_match(nif.begin(), nif.end(), rgx);
}

bool Validation::validateBound(const int option, const int lowerBound,
		const int upperBound) {
	return option >= lowerBound && option <= upperBound;
}

bool Validation::validateIDFormat(const string id) {
	regex rgx(idRegex);
	return regex_match(id.begin(), id.end(), rgx);
}
