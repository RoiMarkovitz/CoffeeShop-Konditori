#include "Recipe.h"

Recipe::Recipe()
{
	logicalSize = 0;
	ingredients = new LinkedList<Ingredient>();
}

Recipe::Recipe(const Recipe& other)
{
	ingredients = new LinkedList<Ingredient>();
	*this = other;
}

Recipe::Recipe(Recipe&& other) noexcept
{
	ingredients = new LinkedList<Ingredient>();
	*this = std::move(other);
}

Recipe::~Recipe()
{
	delete ingredients;
}

const Recipe& Recipe::operator=(const Recipe& other)
{
	if (this != &other)
	{
		logicalSize = other.logicalSize;
		*ingredients = *other.ingredients;
	}
	return *this;
}

const Recipe& Recipe::operator=(Recipe&& other) noexcept
{
	if (this != &other)
	{
		logicalSize = other.logicalSize;
		*ingredients = std::move(*other.ingredients);
	}

	return *this;
}

const Recipe& Recipe::operator+=(const Ingredient& other)
{
	Ingredient* ingredient;

	ingredient = doesIngredientExist(other);

	if (ingredient)
		ingredient->setAmount(ingredient->getAmount() + 1);
	else
	{
		ingredients->add(other);
		logicalSize++;
	}

	return *this;
}

const Recipe& Recipe::operator-=(const Ingredient& other) noexcept(false)
{
	Ingredient* ingredient;

	ingredient = doesIngredientExist(other);
	if (ingredient != nullptr)
	{
		ingredients->remove(*ingredient);
		logicalSize--;
	}
	else
	{
		throw "Error: Ingredient is not found";
	}

	return *this;
}

Ingredient* Recipe::doesIngredientExist(const Ingredient& other) const
{
	Ingredient* ingredient = ingredients->get(other);

	return ingredient ? ingredient : nullptr;
}

ostream& operator<<(ostream& os, const Recipe& recipe)
{
	os << recipe.logicalSize << " Ingredients:" << endl;
	os << *recipe.ingredients;

	return os;
}