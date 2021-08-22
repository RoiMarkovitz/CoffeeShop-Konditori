#ifndef __CASHIER_H
#define __CASHIER_H

#include <iostream>
using namespace std;

#include "Employee.h"


class Cashier : virtual public Employee
{
protected:
	Cashier(const Cashier& other) : Employee(other) {}
	const Cashier& operator=(const Cashier& other);

public:
	Cashier(const char* name, double hourlyWage) noexcept(false);
	bool acceptPayment(double amountToPay) const;

	virtual void toOs(ostream& os) const override;
	friend class Konditori;
};

#endif //__CASHIER_H
