#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>

class Date {
public:
	Date(int year, int month, int day) : m_day(day), m_month(month), m_year(year) {};
	Date() {};
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
private:
	int m_day;
	int m_month;
	int m_year;
};

std::ostream& operator<< (std::ostream& os, Date date);
#endif