#ifndef __PASTRY_H
#define __PASTRY_H

#include <iostream>
using namespace std;

#include "Recipe.h"

class Pastry
{
private:
	char* name;
	double price;
	Recipe recipe;

public:
	Pastry(const char* name, double price, const Recipe& recipe) noexcept(false);
	Pastry(const char* name, double price, Recipe&& recipe) noexcept(false);
	Pastry(const Pastry& other);
	Pastry(Pastry&& other) noexcept;
	~Pastry();

	const Pastry& operator=(const Pastry& other);
	const Pastry& operator=(Pastry&& other) noexcept;

	const char* getName() const { return name; }
	double getPrice() const { return price; }
	const Recipe& getRecipe() const { return recipe; }

	void setName(const char* name) noexcept(false);
	void setPrice(double price) noexcept(false);
	void setRecipe(const Recipe& recipe);

	friend ostream& operator<<(ostream& os, const Pastry& pastry);
};

#endif //__PASTRY_H
