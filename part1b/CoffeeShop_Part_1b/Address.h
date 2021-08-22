#ifndef __ADDRESS_H__
#define __ADDRESS_H__

#include <iostream>
using namespace std;

class Address {
private:
	char* city;
	char* streetName;
	int streetNumber;
public:
	// ctor
	Address(const char* city, const char* streetName, int streetNumber);
	// copy ctor
	Address(const Address& other);
	// move ctor
	Address(Address&& other);
	// assignment operator
	const Address& operator=(const Address& other);
	// move assignment operator
	const Address& operator=(Address&& other);
	// dtor
	~Address();

	// getters
	const char* getCity() const { return city; }
	const char* getStreetName() const { return streetName; }
	int getStreetNumber() const { return streetNumber; }

	// functions
	friend ostream& operator<<(ostream& os, const Address& address);
};

#endif