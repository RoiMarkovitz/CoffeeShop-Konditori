#include "Ingredient.h"
#include "StringUtil.h"
#pragma warning(disable: 4996)

Ingredient::Ingredient(const char* name, int amount) noexcept(false) : name(nullptr)
{
	setAmount(amount);
	setName(name);
}

Ingredient::Ingredient(const Ingredient& other) : name(nullptr)
{
	*this = other;
}

Ingredient::Ingredient(Ingredient&& other) noexcept
{
	*this = std::move(other);
}

Ingredient::~Ingredient()
{
	delete[]name;
}

const Ingredient& Ingredient::operator=(const Ingredient& other)
{
	if (this != &other)
	{
		amount = other.amount;
		setName(other.name);
	}
	return *this;
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

void Ingredient::setName(const char* name) noexcept(false)
{
	if (StringUtil::isValidName(name))
	{
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
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
	os << ingredient.amount << " " << ingredient.name << endl;
	return os;
}