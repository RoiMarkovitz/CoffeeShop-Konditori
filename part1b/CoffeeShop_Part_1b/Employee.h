#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <iostream>
using namespace std;

#include "Person.h"
#include "Date.h"

class Employee : public Person {
private:
	double shiftSalary;
	Date hireDate;

	Employee(const Employee& other);
	
	const Employee& operator=(const Employee& other);

public:
	friend class CoffeeShop;
	// ctor
	Employee(const char* name, const char* phoneNumber, double shiftSalary, const Date& hireDate);
	
	// operators
	bool operator<(const Employee& other) const; 
	bool operator>(const Employee& other) const;
	virtual bool operator==(const Person& other) const override;

	// getters
	double getShiftSalary() const { return shiftSalary; }
	const Date* getHireDate() const { return &hireDate; }

	// setters
	bool setShiftSalary(double shiftSalary);
	bool setHireDate(Date& hireDate);

	// functions
	int getSeniority() const;
	void toOs(ostream& os) const override;

};

#endif