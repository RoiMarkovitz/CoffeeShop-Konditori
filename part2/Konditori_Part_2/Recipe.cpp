#include "Recipe.h"

Recipe::Recipe()
{
	physicalSize = 1;
	logicalSize = 0;
	ingredients = new Ingredient * [physicalSize];
}

Recipe::Recipe(const Recipe& other) : ingredients(nullptr)
{
	*this = other;
}

Recipe::Recipe(Recipe&& other) noexcept : ingredients(nullptr), physicalSize(0), logicalSize(0)
{
	*this = std::move(other);
}

Recipe::~Recipe()
{
	for (int i = 0; i < logicalSize; i++)
		delete ingredients[i];

	delete[] ingredients;
}

const Recipe& Recipe::operator=(const Recipe& other)
{
	if (this != &other)
	{
		physicalSize = other.physicalSize;
		logicalSize = other.logicalSize;

		delete[] ingredients;
		ingredients = new Ingredient * [physicalSize];
		for (int i = 0; i < logicalSize && i < physicalSize; i++)
			ingredients[i] = new Ingredient(*other.ingredients[i]);
	}
	return *this;
}

const Recipe& Recipe::operator=(Recipe&& other) noexcept
{
	if (this != &other)
	{
		swap(physicalSize, other.physicalSize);
		swap(logicalSize, other.logicalSize);
		swap(ingredients, other.ingredients);
	}

	return *this;
}

const Recipe& Recipe::operator+=(const Ingredient& other)
{
	Ingredient* ingredient;
	if (logicalSize == physicalSize)
		ingredients = enlargeIngredientsArray();

	ingredient = doesIngredientExist(other);

	if (ingredient)
		ingredient->setAmount(ingredient->getAmount() + 1);
	else
		ingredients[logicalSize++] = new Ingredient(other);

	return *this;
}

const Recipe& Recipe::operator-=(const Ingredient& other) noexcept(false)
{
	Ingredient* ingredient;
	int amountToReduce;

	ingredient = doesIngredientExist(other);
	if (ingredient != nullptr)
	{
		if (ingredient->getAmount() > 1)
		{
			ingredient->setAmount(amountToReduce = ingredient->getAmount() - 1);
		}
		else
		{
			for (int i = 0; i < logicalSize; i++)
			{
				if (ingredients[i] == ingredient)
				{
					delete ingredient;
					if (i > 0) // not the first ingredient in array
						ingredients[i] = ingredients[logicalSize];

					logicalSize--;
					break;
				}
			}
		}
	}
	else
	{
		throw "Error: Ingredient is not found";
	}

	return *this;
}

Ingredient* Recipe::doesIngredientExist(const Ingredient& other) const
{
	for (int i = 0; i < logicalSize; i++)
		if (strcmp(ingredients[i]->getName(), other.getName()) == 0)
			return ingredients[i];

	return nullptr;
}

Ingredient** Recipe::enlargeIngredientsArray()
{
	Ingredient** newIngredientsArray;
	physicalSize *= ENLARGE_FACTOR;

	newIngredientsArray = new Ingredient * [physicalSize];
	for (int i = 0; i < logicalSize; i++)
		newIngredientsArray[i] = ingredients[i];

	delete[] ingredients;

	return newIngredientsArray;
}

ostream& operator<<(ostream& os, const Recipe& recipe)
{
	os << recipe.logicalSize << " Ingredients:" << endl;
	for (int i = 0; i < recipe.logicalSize; i++)
		os << i + 1 << ". " << *recipe.ingredients[i];

	return os;
}