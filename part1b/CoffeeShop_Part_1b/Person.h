#ifndef __PERSON_H__
#define __PERSON_H__

#include <iostream>
using namespace std;

class Person {
protected:
	char *name, *phoneNumber;

	Person(const Person& other);

	const Person& operator=(const Person& other);

public:
	// ctor
	Person(const char* name, const char* phoneNumber);

	// dtor
	virtual ~Person();

	// operators
	virtual bool operator==(const Person& other) const;

	// getters
	const char* getName() const { return name; }
	const char* getPhoneNumber() const { return phoneNumber; }

	// setters
	bool setPhoneNumber(const char* phoneNumber);

	// functions
	virtual void toOs(ostream& os) const = 0;
	friend ostream& operator<<(ostream& os, const Person& person);
};

#endif