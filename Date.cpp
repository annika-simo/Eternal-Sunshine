#include "Date.h"
#include <iostream>

/*
 * setDay
 *
 * sets the input to the correspoding member variable for day
 *
 * input: integer for day
 * output: none
 */

void Date::setDay(int day) {
	m_day = day;
}

/*
 * setMonth
 *
 * sets the input to the correspoding member variable for month
 *
 * input: integer for month
 * output: none
 */

void Date::setMonth(int month) {
	m_month = month;
}

/*
 * setYear
 *
 * sets the input to the correspoding member variable for year
 *
 * input: integer for year
 * output: none
 */

void Date::setYear(int year) {
	m_year = year;
}

/*
 * getDay
 *
 * gets the value for day
 *
 * input: none
 * output: the momber variable for day
 */

int Date::getDay() const {
	return m_day;
}

/*
 * getMonth
 *
 * gets the value for month
 *
 * input: none
 * output: the momber variable for month
 */

int Date::getMonth() const {
	return m_month;
}

/*
 * getYear
 *
 * gets the value for year
 *
 * input: none
 * output: the momber variable for year
 */

int Date::getYear() const {
	return m_year;
}

/*
 * overloading << operator
 *
 * overloads the << operator to format and print a variable of the date type
 *
 * input: ostream type variable os and date type variable date
 * output: ostream result
 */

std::ostream& operator<< (std::ostream& os, Date date) { 
	os << date.getYear() << "-" << date.getMonth() << "-" << date.getDay();
	return os;
}