#ifndef __BILL_H
#define __BILL_H

#include <iostream>
using namespace std;
#include <time.h>
#include "PastryWithCount.h"

class Pastry;

class Bill
{
private:
	static const int ENLARGE_FACTOR = 2;

	time_t date;
	int physicalSize;
	int logicalSize;
	PastryWithCount** items;

	PastryWithCount** enlargeIngredientsArray();
public:
	Bill();
	Bill(const Bill& other);
	Bill(Bill&& other) noexcept;
	~Bill();

	const Bill& operator=(const Bill& other);
	const Bill& operator=(Bill&& other) noexcept;

	const char* getDate() const;
	double getTotalPrice() const;
	int getLogicalSize() const { return logicalSize; }
	PastryWithCount* const* getItems() const { return items; }

	void addPastry(const Pastry& pastry, int amount = 1) noexcept(false);

	bool operator<(const Bill& other) const;
	bool operator>(const Bill& other) const;

	friend ostream& operator<<(ostream& os, const Bill& bill);
};

#endif //__BILL_H
