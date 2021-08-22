#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include <iostream>
using namespace std;

#include "Person.h"

class Customer : public Person {
private:
	bool clubMember;

	Customer(const Customer& other);

	const Customer& operator=(const Customer& other);

public:
	friend class CoffeeShop;
	// ctor
	Customer(const char* name, const char* phoneNumber, bool clubMember = false);
	
	// getters
	bool isClubMember() const;

	// setters
	bool setClubMember(bool clubMember);

	// functions
	void toOs(ostream& os) const override;

};

#endif