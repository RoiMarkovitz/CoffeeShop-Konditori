#pragma warning(disable: 4996)

#include "Employee.h"
#include "StringUtil.h"

int Employee::idGenerator = 0;

Employee::Employee(const string& name, double hourlyWage) noexcept(false) 
{
	setHourlyWage(hourlyWage);
	setName(name);
	id = ++idGenerator;
}

Employee::Employee(Employee&& other) noexcept
{
	setHourlyWage(other.hourlyWage);
	swap(name, other.name);
	id = other.id;
}

Employee::~Employee() {}

void Employee::setName(const string& name) noexcept(false)
{
	if (StringUtil::isValidName(name.c_str()))
		this->name = name;
	else
		throw "Error: invalid employee name";
}

void Employee::setHourlyWage(double hourlyWage) noexcept(false)
{
	if (hourlyWage <= 0)
		throw "Error: invalid hourly wage";

	this->hourlyWage = hourlyWage;
}

ostream& operator<<(ostream& os, const Employee& employee)
{
	os << "Name: " << employee.name << ", ID: " << employee.id << ", Hourly Wage: " << employee.hourlyWage;
	employee.toOs(os);
	return os;
}

