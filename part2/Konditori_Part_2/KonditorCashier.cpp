#include "KonditorCashier.h"

KonditorCashier::KonditorCashier(const char* name, double hourlyWage) noexcept(false) : Employee(name, hourlyWage), Cashier(name, hourlyWage), Konditor(name, hourlyWage) {}

void KonditorCashier::toOs(ostream& os) const
{
	os << ", Has two roles:" << endl;
	Cashier::toOs(os);
	Konditor::toOs(os);
}
