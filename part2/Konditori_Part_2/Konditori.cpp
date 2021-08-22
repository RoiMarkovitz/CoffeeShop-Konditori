#include "Konditori.h"
#include "Pastry.h"
#include "Bill.h"
#include "Cashier.h"
#include "Konditor.h"
#include "KonditorCashier.h"
#include "Shift.h"
#include "StringUtil.h"

#pragma warning(disable: 4996)

Konditori::Konditori(const char* name, const Address& address) noexcept(false) : address(address), name(nullptr)
{
	setName(name);
	initArrays();
}

Konditori::Konditori(const char* name, Address&& address) noexcept(false) : address(std::move(address)), name(nullptr)
{
	setName(name);
	initArrays();
}

void Konditori::initArrays()
{
	employees = new Employee * [1];
	employeesPhysicalSize = 1;
	employeesLogicalSize = 0;

	pastries = new Pastry * [1];
	pastriesPhysicalSize = 1;
	pastriesLogicalSize = 0;

	bills = new Bill * [1];
	billsPhysicalSize = 1;
	billsLogicalSize = 0;
}

Konditori::Konditori(Konditori&& other) noexcept : address(other.getAddress()), employees(nullptr), pastries(nullptr), bills(nullptr), name(nullptr)
{
	setName(name);
	
	swap(employees, other.employees);
	employeesPhysicalSize = other.employeesPhysicalSize;
	employeesLogicalSize = other.employeesLogicalSize;

	swap(pastries, other.pastries);
	pastriesPhysicalSize = other.pastriesPhysicalSize;
	pastriesLogicalSize = other.pastriesLogicalSize;

	swap(bills, other.bills);
	billsPhysicalSize = other.billsPhysicalSize;
	billsLogicalSize = other.billsLogicalSize;

	currentShift = other.currentShift;
}

Konditori::~Konditori()
{
	for (int i = 0; i < employeesLogicalSize; i++)
		delete employees[i];
	delete[] employees;

	for (int i = 0; i < pastriesLogicalSize; i++)
		delete pastries[i];
	delete[] pastries;

	for (int i = 0; i < billsLogicalSize; i++)
		delete bills[i];
	delete[] bills;
}

void Konditori::setName(const char* name) noexcept(false)
{
	if (StringUtil::isValidName(name))
	{
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	else
		throw "Error: invalid konditori name";
}

const Konditori& Konditori::operator+=(const Employee& other)
{	
	if (employeesLogicalSize == employeesPhysicalSize)
		employees = enlargeEmployeesArray();
	
		const KonditorCashier* k = dynamic_cast<const KonditorCashier*>(&other);
		if (k)
			employees[employeesLogicalSize] = new KonditorCashier(*k);
		else 
		{
			const Konditor* k = dynamic_cast<const Konditor*>(&other);
			if (k)
				employees[employeesLogicalSize] = new Konditor(*k);
			else
			{
				const Cashier* c = dynamic_cast<const Cashier*>(&other);
				if (c)
					employees[employeesLogicalSize] = new Cashier(*c);
			}
		}
	
	employeesLogicalSize++;
	return *this;
}

Employee** Konditori::enlargeEmployeesArray()
{
	Employee** newEmployeeArray;
	employeesPhysicalSize *= ENLARGE_FACTOR;
	newEmployeeArray = new Employee * [employeesPhysicalSize];

	for (int i = 0; i < employeesLogicalSize; i++)
		newEmployeeArray[i] = employees[i];

	delete[] employees;

	return newEmployeeArray;
}

Employee* Konditori::getEmployeeById(int id) const
{
	for (int i = 0; i < employeesLogicalSize; ++i)
	{
		if (employees[i]->getId() == id)
		{
			return employees[i];
		}
	}
	return nullptr;
}

Konditori::ePastryActionStatus Konditori::addPastry(const Pastry& pastry)
{
	if (pastriesLogicalSize == pastriesPhysicalSize)
		pastries = enlargePastriesArray();

	if (isSamePastryName(pastry.getName()))
		return Konditori::ePastryActionStatus::FAILED_ALREADY_EXIST;

	pastries[pastriesLogicalSize++] = new Pastry(pastry);
	
	return Konditori::ePastryActionStatus::SUCCEED;
}

Pastry** Konditori::enlargePastriesArray()
{
	Pastry** newPastriesArray;
	pastriesPhysicalSize *= ENLARGE_FACTOR;
	newPastriesArray = new Pastry * [pastriesPhysicalSize];

	for (int i = 0; i < pastriesLogicalSize; i++)
		newPastriesArray[i] = pastries[i];

	delete[] pastries;

	return newPastriesArray;
}

Konditori::ePastryActionStatus Konditori::renamePastry(const Pastry& pastry, const char* newName)
{
	if (newName == nullptr)
		return Konditori::ePastryActionStatus::FAILED_GENERAL;
	
	if (isSamePastryName(newName))
		return Konditori::ePastryActionStatus::FAILED_ALREADY_EXIST;

	getPastryByName(pastry.getName())->setName(newName);
	return Konditori::ePastryActionStatus::SUCCEED;
}

bool Konditori::isSamePastryName(const char* pastryName) const
{
	for (int i = 0; i < pastriesLogicalSize; i++)
	{
		if (strcmp(pastries[i]->getName(), pastryName) == 0)
			return true;
	}
	return false;
}

const Pastry* Konditori::getPastryByName(const char* pastryName) const
{
	for (int i = 0; i < pastriesLogicalSize; ++i)
	{
		if (strcmp(pastries[i]->getName(), pastryName) == 0)
		{
			return pastries[i];
		}
	}
	return nullptr;
}

Pastry* Konditori::getPastryByName(const char* pastryName)
{
	for (int i = 0; i < pastriesLogicalSize; ++i)
	{
		if (strcmp(pastries[i]->getName(), pastryName) == 0)
		{
			return pastries[i];
		}
	}
	return nullptr;
}

const Bill* const* Konditori::getTopBills() const
{
	int start = billsLogicalSize - 5;
	if (start < 0)
		start = 0;
	return &bills[start];
}

const Bill* const* Konditori::getBottomBills() const
{
	return &bills[0];
}

void Konditori::addBill(const Bill& bill) noexcept(false)
{
	if (bill.getLogicalSize() == 0)
		throw "Error: cannot add a bill with no items";

	if (billsLogicalSize == billsPhysicalSize)
		bills = enlargeBillsArray();

	bills[billsLogicalSize++] = new Bill(bill);

	insertionSort();
}

Bill** Konditori::enlargeBillsArray()
{
	Bill** newBillsArray;
	billsPhysicalSize *= ENLARGE_FACTOR;
	newBillsArray = new Bill * [billsPhysicalSize];

	for (int i = 0; i < billsLogicalSize; i++)
		newBillsArray[i] = bills[i];

	delete[] bills;

	return newBillsArray;
}

void Konditori::insertionSort()
{
	for (int i = 1; i < billsLogicalSize; i++)
	{
		for (int j = i; j > 0 && *bills[j-1] > *bills[j] ; j--)
		{
			Bill* temp = bills[j];
			bills[j] = bills[j-1];
			bills[j-1] = temp;
		}		
	}
}

ostream& operator<<(ostream& os, const Konditori& konditori)
{
	os << "Konditori name:" << endl << konditori.getName() << endl
		<< "Address:\n" << konditori.getAddress() << endl;
	return os;
}