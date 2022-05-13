#include "Location.h"

/*
 * setLatitude
 *
 * sets the input to the correspoding member variable for latitude
 *
 * input: double for latitude
 * output: none
 */

void Location::setLatitude(const double& latitude) {
	m_latitude = latitude;
}

/*
 * setLongitude
 *
 * sets the input to the correspoding member variable for longitude
 *
 * input: double for longitude
 * output: none
 */

void Location::setLongitude(const double& longitude) {
	m_longitude = longitude;
}

/*
 * getLatitude
 *
 * gets the value for latitude
 *
 * input: none
 * output: the momber variable for latitude
 */

double Location::getLatitude() const {
	return m_latitude;
}

/*
 * getLongitude
 *
 * gets the value for longitude
 *
 * input: none
 * output: the momber variable for longitude
 */

double Location::getLongitude() const {
	return m_longitude;
}