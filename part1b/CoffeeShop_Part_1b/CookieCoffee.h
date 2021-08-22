#ifndef __COOKIECOFFEE_H__
#define __COOKIECOFFEE_H__

#include <iostream>
using namespace std;

class CookieCoffee: public Cookie, public Coffee{
private:
	bool groundCookie;
	double discountPercent;

public:
	// ctor
	CookieCoffee(const Cookie& cookie, const Coffee& coffee, double discountPercent = 0, bool groundCookie = false);
	
	// clone
	virtual Product* clone() const override { return new CookieCoffee(*this); }

	// getters
	bool isGroundCookie() const { return groundCookie; }
	double getDiscountPercent() const { return discountPercent; }

	// setters
	bool setDiscountPercent(double discountPercent);

	// functions
	virtual void toOs(ostream& os) const override;

};

#endif
