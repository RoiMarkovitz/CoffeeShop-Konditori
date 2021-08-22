#ifndef __COFFEE_H__
#define __COFFEE_H__

#include <iostream>
using namespace std;

#include "Product.h"

class Coffee : virtual public Product {
protected:
	bool withMilk;
	int sugarSpoons;
public:
	// ctor
	Coffee(const char* name, int calories, double cost, double price, bool withMilk = false, int sugarSpoons = 0);

	// operators
	const Coffee& operator+=(int sugarSpoons);

	// clone
	virtual Product* clone() const override { return new Coffee(*this); }

	// getters
	bool getWithMilk() const { return withMilk; }
	int getSugarSpoons() const { return sugarSpoons; }

	// functions
	bool addSugar(int sugarSpoons = 1);
	bool setMilk(bool isWithMilk);

	void toOs(ostream& os) const override;

};

#endif
