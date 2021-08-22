#include "Konditori.h"
#include "Pastry.h"
#include "Bill.h"
#include "Cashier.h"
#include "Konditor.h"
#include "KonditorCashier.h"
#include "Shift.h"
#include "StringUtil.h"

#pragma warning(disable: 4996)

Konditori::Konditori(const char* name, const Address& address) noexcept(false) : address(address)
{
	setName(name);
}

Konditori::Konditori(const char* name, Address&& address) noexcept(false) : address(std::move(address))
{
	setName(name);
}

Konditori::Konditori(Konditori&& other) noexcept : address(other.getAddress())
{
	setName(name);

	swap(employees, other.employees);
	swap(pastries, other.pastries);
	swap(bills, other.bills);

	currentShift = other.currentShift;
}

Konditori::~Konditori()
{
	vector<Employee*>::iterator itrE = employees.begin();
	vector<Employee*>::iterator itrEend = employees.end();
	for (; itrE != itrEend; ++itrE)
		delete* itrE;

	vector<Pastry*>::iterator itrP = pastries.begin();
	vector<Pastry*>::iterator itrPend = pastries.end();
	for (; itrP != itrPend; ++itrP)
		delete* itrP;

	vector<Bill*>::iterator itrB = bills.begin();
	vector<Bill*>::iterator itrBend = bills.end();
	for (; itrB != itrBend; ++itrB)
		delete* itrB;
}

void Konditori::setName(const string& name) noexcept(false)
{
	if (StringUtil::isValidName(name.c_str()))
		this->name = name;
	else
		throw "Error: invalid konditori name";
}

const Konditori& Konditori::operator+=(const Employee& other)
{
	if (employees.size() == employees.capacity())
		employees.reserve(employees.capacity() * ENLARGE_FACTOR);

	const KonditorCashier* k = dynamic_cast<const KonditorCashier*>(&other);
	if (k)
		employees.push_back(new KonditorCashier(*k));
	else
	{
		const Konditor* k = dynamic_cast<const Konditor*>(&other);
		if (k)
			employees.push_back(new Konditor(*k));
		else
		{
			const Cashier* c = dynamic_cast<const Cashier*>(&other);
			if (c)
				employees.push_back(new Cashier(*c));
		}
	}

	return *this;
}

Employee* Konditori::getEmployeeById(int id) const
{
	vector<Employee*>::const_iterator itr = employees.begin();
	vector<Employee*>::const_iterator itrEnd = employees.end();
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getId() == id)
		{
			return *itr;
		}
	}

	return nullptr;
}

Konditori::ePastryActionStatus Konditori::addPastry(const Pastry& pastry)
{
	if (pastries.size() == pastries.capacity())
		pastries.reserve(pastries.capacity() * ENLARGE_FACTOR);

	if (isSamePastryName(pastry.getName()))
		return Konditori::ePastryActionStatus::FAILED_ALREADY_EXIST;

	pastries.push_back(new Pastry(pastry));

	return Konditori::ePastryActionStatus::SUCCEED;
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

bool Konditori::isSamePastryName(const string& pastryName) const
{
	vector<Pastry*>::const_iterator itr = pastries.begin();
	vector<Pastry*>::const_iterator itrEnd = pastries.end();
	for (; itr != itrEnd; ++itr)
	{
		if (strcmp((*itr)->getName().c_str(), pastryName.c_str()) == 0)
			return true;
	}

	return false;
}

const Pastry* Konditori::getPastryByName(const string& pastryName) const
{
	vector<Pastry*>::const_iterator itr = pastries.begin();
	vector<Pastry*>::const_iterator itrEnd = pastries.end();
	for (; itr != itrEnd; ++itr)
	{
		if (strcmp((*itr)->getName().c_str(), pastryName.c_str()) == 0)
			return *itr;
	}
	
	return nullptr;
}

Pastry* Konditori::getPastryByName(const string& pastryName)
{
	vector<Pastry*>::iterator itr = pastries.begin();
	vector<Pastry*>::iterator itrEnd = pastries.end();
	for (; itr != itrEnd; ++itr)
	{
		if (strcmp((*itr)->getName().c_str(), pastryName.c_str()) == 0)
			return *itr;		
	}

	return nullptr;
}

const Bill* const* Konditori::getTopBills() const
{
	int start = bills.size() - 5;
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

	if (bills.size() == bills.capacity())
		bills.reserve(bills.capacity() * ENLARGE_FACTOR);

	bills.push_back(new Bill(bill));

	insertionSort();
}

void Konditori::insertionSort()
{
	for (int i = 1; i < (int)bills.size(); i++)
	{
		for (int j = i; j > 0 && *bills[j - 1] > * bills[j]; j--)
		{
			Bill* temp = bills[j];
			bills[j] = bills[j - 1];
			bills[j - 1] = temp;
		}
	}
}

ostream& operator<<(ostream& os, const Konditori& konditori)
{
	os << "Konditori name:" << endl << konditori.getName() << endl
		<< "Address:\n" << konditori.getAddress() << endl;
	return os;
}