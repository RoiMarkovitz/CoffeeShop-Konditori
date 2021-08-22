#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include <iostream>
using namespace std;

class Employee
{
protected:
	static int idGenerator;
	int id;
	char* name;
	double hourlyWage;

	Employee(const Employee& other);
	const Employee& operator=(const Employee& other);
	Employee(Employee&& other) noexcept;

public:
	Employee(const char* name, double hourlyWage) noexcept(false);
	virtual ~Employee();

	int getId() const { return id; }
	const char* getName() const { return name; }
	double getHourlyWage() const { return hourlyWage; }
	static int getNumOfEmployees() { return idGenerator; }

	void setName(const char* name) noexcept(false);
	void setHourlyWage(double hourlyWage) noexcept(false);

	virtual void toOs(ostream& os) const = 0 {}

	friend ostream& operator<<(ostream& os, const Employee& employee);

	friend class Konditori;
};

#endif //__EMPLOYEE_H
