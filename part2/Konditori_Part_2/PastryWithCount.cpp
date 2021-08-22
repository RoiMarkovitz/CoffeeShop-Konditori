#include <iostream>
using namespace std;

#include "PastryWithCount.h"

PastryWithCount::PastryWithCount(const Pastry& pastry, int amount) noexcept(false) : pastry(pastry)
{
	setAmount(amount);
	setReady(false);
}

PastryWithCount::PastryWithCount(Pastry&& pastry, int amount) noexcept(false) : pastry(std::move(pastry))
{
	setAmount(amount);
	setReady(false);
}

void PastryWithCount::setPastry(const Pastry& pastry)
{
	this->pastry = pastry;
}
void PastryWithCount::setAmount(int amount) noexcept(false)
{
	if (amount > 0)
		this->amount = amount;
	else
		throw "Error: amount must be above 0";
}

void PastryWithCount::setReady(bool isReady)
{
	this->isReady = isReady;
}

double PastryWithCount::getPrice() const
{
	return pastry.getPrice() * amount;
}

ostream& operator<<(ostream& os, const PastryWithCount& pastryWithCount)
{
	os << pastryWithCount.pastry << "amount: " << pastryWithCount.amount << endl;
	return os;
}
