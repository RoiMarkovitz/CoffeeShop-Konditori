#pragma warning(disable: 4996)

#include "Employee.h"
#include "StringUtil.h"

int Employee::idGenerator = 0;

Employee::Employee(const char* name, double hourlyWage) noexcept(false) : name(nullptr)
{
	setHourlyWage(hourlyWage);
	setName(name);
	id = ++idGenerator;
}

Employee::Employee(const Employee& other) : name(nullptr)
{
	setHourlyWage(other.hourlyWage);
	setName(other.name);
	id = other.id;
}

Employee::Employee(Employee&& other) noexcept
{
	setHourlyWage(other.hourlyWage);
	swap(name, other.name);
	id = other.id;
}

Employee::~Employee()
{
	delete[] name;
}

void Employee::setName(const char* name) noexcept(false)
{
	if (StringUtil::isValidName(name))
	{
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
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

