#ifndef __INGREDIENT_H
#define __INGREDIENT_H

#include <string>
#include <iostream>
using namespace std;

class Ingredient
{
private:
	string name;
	int amount;

public:
	Ingredient(const string& name, int amount = 1) noexcept(false);
	Ingredient(const Ingredient& ingredient) = default;
	Ingredient(Ingredient&& other) noexcept;

	const Ingredient& operator=(Ingredient&& other) noexcept;
	bool operator==(const Ingredient& other);
	const string& getName() const { return name; }
	int getAmount() const { return amount; }

	void setName(const string& name) noexcept(false);
	void setAmount(int amount) noexcept(false);

	friend ostream& operator<<(ostream& os, const Ingredient& ingredient);
};

#endif //__INGREDIENT_H