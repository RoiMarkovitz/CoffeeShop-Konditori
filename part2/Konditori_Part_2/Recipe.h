#ifndef __RECIPE_H
#define __RECIPE_H

#include <iostream>
using namespace std;

#include "Ingredient.h"

class Recipe
{
private:
	static const int ENLARGE_FACTOR = 2;
	int physicalSize;
	int logicalSize;
	Ingredient** ingredients;
	
	Ingredient* doesIngredientExist(const Ingredient& other) const;
	Ingredient** enlargeIngredientsArray();
public:
	Recipe();
	Recipe(const Recipe& other);
	Recipe(Recipe&& other) noexcept;
	~Recipe();

	const Recipe& operator=(const Recipe& other);
	const Recipe& operator=(Recipe&& other) noexcept;

	const Recipe& operator+=(const Ingredient& other);
	const Recipe& operator-=(const Ingredient& other) noexcept(false);
	
	const Ingredient* const* getIngredients() const { return ingredients; }
	
	friend ostream& operator<<(ostream& os, const Recipe& recipe);
};

#endif //__RECIPE_H
