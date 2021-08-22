#ifndef __DATE_H__
#define __DATE_H__

#include <iostream>
using namespace std;

class Date {
private:
	int day, month, year;
public:
	// ctor
	Date(int day, int month, int year);

	// getters
	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }

	// functions
	friend ostream& operator<<(ostream& os, const Date& date);
};

#endif