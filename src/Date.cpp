#include "Date.h"

// Constructors/Destructors
//  

Date::Date() {
	initAttributes();
}

Date::~Date() {
}

void Date::setDay(unsigned int new_var) {
	day = new_var;
}

unsigned int Date::getDay() {
	return day;
}

void Date::setMonth(unsigned int new_var) {
	month = new_var;
}

unsigned int Date::getMonth() {
	return month;
}
void Date::setYear(unsigned int new_var) {
	year = new_var;
}

unsigned int Date::getYear() {
	return year;
}
void Date::initAttributes() {
}

