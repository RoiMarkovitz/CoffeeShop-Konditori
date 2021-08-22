#include <iostream>
using namespace std;

#include "Shift.h"
#include "Employee.h"
#include "Cashier.h"
#include "Konditor.h"

Shift::Shift() : cashier(nullptr), konditor(nullptr) {}

void Shift::setCashier(Cashier* cashier) noexcept(false)
{
	if (!cashier)
		throw "Error: cashier cannot be nullptr";
	
	this->cashier = cashier;
}

void Shift::setKonditor(Konditor* konditor) noexcept(false)
{
	if (!konditor)
		throw "Error: konditor cannot be nullptr";
	
	this->konditor = konditor;
}

ostream& operator<<(ostream& os, const Shift& shift)
{
	if (shift.cashier != nullptr)
		os << "Cashier: " << *shift.cashier << endl;
	else
		os << "Cashier: not assigned yet" << endl;
	if (shift.konditor != nullptr)
		os << "Konditor: " << *shift.konditor << endl;
	else
		os << "Konditor: not assigned yet" << endl;

	return os;
}