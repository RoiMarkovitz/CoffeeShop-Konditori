#include "Ingredient.h"
#include "StringUtil.h"
#pragma warning(disable: 4996)

Ingredient::Ingredient(const string& name, int amount) noexcept(false)
{
	setAmount(amount);
	setName(name);
}

Ingredient::Ingredient(Ingredient&& other) noexcept
{
	*this = std::move(other);
}

const Ingredient& Ingredient::operator=(Ingredient&& other) noexcept
{
	if (this != &other)
	{
		amount = other.amount;
		swap(name, other.name);
	}
	return *this;
}

bool Ingredient::operator==(const Ingredient& other)
{
	if (name != other.name || amount != other.amount)
		return false;

	return true;
}

void Ingredient::setName(const string& name) noexcept(false)
{
	if (StringUtil::isValidName(name.c_str()))
		this->name = name;
	else
		throw "Error: invalid ingredient name";
}

void Ingredient::setAmount(int amount) noexcept(false)
{
	if (amount <= 0)
		throw "Error: invalid amount";

	this->amount = amount;
}

ostream& operator<<(ostream& os, const Ingredient& ingredient)
{
	os << "amount: " << ingredient.amount << ", name: " << ingredient.name << endl;
	return os;
}