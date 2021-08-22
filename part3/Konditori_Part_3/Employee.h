#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include <string>
#include <iostream>
using namespace std;

class Employee
{
protected:
	static int idGenerator;
	int id;
	string name;
	double hourlyWage;

	Employee(const Employee& other) = default;
	const Employee& operator=(const Employee& other);
	Employee(Employee&& other) noexcept;

public:
	Employee(const string& name, double hourlyWage) noexcept(false);

	// will be kept for polymorphism if in the future dervied classes may need to release memory 
	virtual ~Employee();

	int getId() const { return id; }
	const string& getName() const { return name; }
	double getHourlyWage() const { return hourlyWage; }
	static int getNumOfEmployees() { return idGenerator; }

	void setName(const string& name) noexcept(false);
	void setHourlyWage(double hourlyWage) noexcept(false);

	virtual void toOs(ostream& os) const = 0 {}

	friend ostream& operator<<(ostream& os, const Employee& employee);

	friend class Konditori;
};

#endif //__EMPLOYEE_H
