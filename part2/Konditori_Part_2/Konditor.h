#ifndef __KONDITOR_H
#define __KONDITOR_H

#include <iostream>
using namespace std;

#include "Employee.h"
#include "PastryWithCount.h"

class Konditor : virtual public Employee
{
protected:
	Konditor(const Konditor& other) : Employee(other) {}
	const Konditor& operator=(const Konditor& other) noexcept;

public:
	Konditor(const char* name, double hourlyWage) noexcept(false);
	void bake(PastryWithCount* const* pastries, int logicalSize) const;

	virtual void toOs(ostream& os) const override;
	friend class Konditori;
};

#endif //__KONDITOR_H
