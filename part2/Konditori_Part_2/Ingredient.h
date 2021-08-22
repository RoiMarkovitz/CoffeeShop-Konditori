#ifndef __INGREDIENT_H
#define __INGREDIENT_H

#include <iostream>
using namespace std;

class Ingredient
{
private:
	char* name;
	int amount;

public:
	Ingredient(const char* name, int amount = 1) noexcept(false);
	Ingredient(const Ingredient& ingredient);
	Ingredient(Ingredient&& other) noexcept;
	~Ingredient();

	const Ingredient& operator=(const Ingredient& other);
	const Ingredient& operator=(Ingredient&& other) noexcept;

	const char* getName() const { return name; }
	int getAmount() const { return amount; }

	void setName(const char* name) noexcept(false);
	void setAmount(int amount) noexcept(false);

	friend ostream& operator<<(ostream& os, const Ingredient& ingredient);
};

#endif //__INGREDIENT_H