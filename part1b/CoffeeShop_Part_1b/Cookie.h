#ifndef __COOKIE_H__
#define __COOKIE_H__

#include <iostream>
using namespace std;

#include "Product.h"

class Cookie: virtual public Product{
public:
	enum class eFlourType { WHITE, WHOLE, GLUTEN_FREE, enumTypeEnd };
protected:
	eFlourType flour;

public:
	// ctor
	Cookie(const char* name, int calories, double cost, double price, eFlourType flour = eFlourType::WHITE);

	// clone
	virtual Product* clone() const override { return new Cookie(*this); }

	// getters
	eFlourType getFlourType() const { return flour; }

	// functions
	void toOs(ostream& os) const override;

};

#endif