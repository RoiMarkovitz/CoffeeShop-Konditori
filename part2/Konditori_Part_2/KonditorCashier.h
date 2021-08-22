#ifndef __KONDITORCASHIER_H
#define __KONDITORCASHIER_H

#include <iostream>
using namespace std;

#include "Konditor.h"
#include "Cashier.h"


class KonditorCashier : public Cashier, public Konditor
{
protected:
	KonditorCashier(const KonditorCashier& other) : Employee(other), Cashier(other), Konditor(other) {}
	const KonditorCashier& operator=(const KonditorCashier& other);

public:
	KonditorCashier(const char* name, double hourlyWage) noexcept(false);
	virtual void toOs(ostream& os) const override;
	friend class Konditori;
};

#endif //__KONDITORCASHIER_H
