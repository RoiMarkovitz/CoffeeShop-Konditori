#pragma warning(disable: 4996)
#include "Pastry.h"
#include "StringUtil.h"

Pastry::Pastry(const char* name, double price, const Recipe& recipe) noexcept(false) : recipe(recipe), name(nullptr)
{
	setPrice(price);
	setName(name);

}

Pastry::Pastry(const char* name, double price, Recipe&& recipe) noexcept(false) : recipe(std::move(recipe)), name(nullptr)
{
	setPrice(price);
	setName(name);
}

Pastry::Pastry(const Pastry& other) : recipe(other.recipe), name(nullptr)
{
	*this = other;
}

Pastry::Pastry(Pastry&& other) noexcept 
{
	*this = std::move(other);
}

Pastry::~Pastry()
{
	delete[] name;
}

const Pastry& Pastry::operator=(const Pastry& other)
{
	if (this != &other)
	{
		setPrice(other.price);
		setName(other.name);
		setRecipe(other.recipe);
	}
	return *this;
}

const Pastry& Pastry::operator=(Pastry&& other) noexcept
{
	if (this != &other)
	{
		setPrice(other.price);
		swap(name, other.name);
		swap(recipe, other.recipe);
	}

	return *this;
}

void Pastry::setName(const char* name) noexcept(false)
{
	if (StringUtil::isValidName(name))
	{
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	else
		throw "Error: invalid pastry name";
}

void Pastry::setPrice(double price) noexcept(false)
{
	if (price > 0)
		this->price = price;
	else
		throw "Error: invalid pastry price";
}

void Pastry::setRecipe(const Recipe& recipe)
{
	this->recipe = recipe;
}

ostream& operator<<(ostream& os, const Pastry& pastry)
{
	os << "Name: " << pastry.name << endl
		<< "Price: " << pastry.price << endl
		<< "Recipe:\n" << pastry.recipe;
	return os;
}
