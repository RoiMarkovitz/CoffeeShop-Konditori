#include "Cashier.h"

Cashier::Cashier(const char* name, double hourlyWage) noexcept(false) : Employee(name, hourlyWage) {}

bool Cashier::acceptPayment(double amountToPay) const
{
	if (amountToPay <= 0)
		return false;

	return true;
}

void Cashier::toOs(ostream& os) const
{
	os << ", Role: Cashier" << endl;
}
