#include "LocationDateLength.h"
#include "Date.h"
#include "Location.h"
#include <iostream>

/*
 * getDate
 *
 * gets the value for date
 *
 * input: none
 * output: the momber variable for date
 */

Date LocationDateLength::getDate() const {
	return m_date;
}

/*
 * getLocation
 *
 * gets the value for location
 *
 * input: none
 * output: the momber variable for location
 */

Location LocationDateLength::getLocation() const {
	return m_location;
}

/*
 * getLength
 *
 * gets the value for length
 *
 * input: none
 * output: the momber variable for length
 */

int LocationDateLength::getLength() const {
	return m_dayLength;
}

/*
 * setLength
 *
 * sets the input to the correspoding member variable for day langth
 *
 * input: integer for day length
 * output: none
 */

void LocationDateLength::setLength(const int dayLength) {
	m_dayLength = dayLength;
}

/*
 * overloading - operator
 *
 * overloads the - operator to subtact the day lengths
 *
 * input: ostream type variable os and date type variable date
 * output: int for the difference in day length in seconds
 */

int operator-(LocationDateLength dayLengthA, LocationDateLength dayLengthB) {
	return dayLengthA.getLength() - dayLengthB.getLength();
}