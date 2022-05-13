#ifndef LOCATION_CPP
#define LOCATION_CPP


class Location {
public:
	Location(double latitude, double longitude) : m_latitude(latitude), m_longitude(longitude) {};
	Location() {};
	double getLatitude() const;
	double getLongitude() const;
	void setLatitude(const double& latitude);
	void setLongitude(const double& longitude);
private:
	double m_latitude;
	double m_longitude;
};

#endif
