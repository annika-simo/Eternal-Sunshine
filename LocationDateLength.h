#ifndef LOCATIONDATELENGTH_H
#define LOCATIONDATELENGTH_H

#include "Date.h"
#include "Location.h"

class LocationDateLength {
public:
	LocationDateLength() {};
	LocationDateLength(Date date, Location location) : m_date(date), m_location(location) {};
	Date getDate() const;
	Location getLocation() const;
	int getLength() const;
	void setLength(const int dayLength);
private:
	int m_dayLength;
	Location m_location;
	Date m_date;
};

int operator-(LocationDateLength dayLengthA, LocationDateLength dayLengthB);

#endif
