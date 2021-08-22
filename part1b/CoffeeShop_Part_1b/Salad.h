#ifndef __SALAD_H__
#define __SALAD_H__

#include <iostream>
using namespace std;

#include "Product.h"

class Salad: virtual public Product{
public:
	enum class eDressingType {VINEGRET, SOY, THOUSAND_ISLAND, enumTypeEnd};
private:
	eDressingType dressing;

public:
	// ctor
	Salad(const char* name, int calories, double cost, double price, eDressingType dressing = eDressingType::enumTypeEnd);

	// clone
	virtual Product* clone() const override { return new Salad(*this); }

	// getters
	eDressingType getDressing() const { return dressing; }

	// functions
	bool addDressing(eDressingType dressing);

	void toOs(ostream& os) const override;

};

#endif
