#ifndef __KONDITORI_H
#define __KONDITORI_H

#include "Employee.h"
#include "Address.h"
#include "Shift.h"
#include <iostream>

using namespace std;

class Pastry;
class Bill;

class Konditori
{

public:
	enum class ePastryActionStatus { SUCCEED, FAILED_ALREADY_EXIST, FAILED_GENERAL };

private:
	static const int ENLARGE_FACTOR = 2;
	char* name;
	Address address;
	Shift currentShift;

	Employee** employees;
	int employeesPhysicalSize, employeesLogicalSize;

	Pastry** pastries;
	int pastriesPhysicalSize, pastriesLogicalSize;

	Bill** bills;
	int billsPhysicalSize, billsLogicalSize;

	void initArrays();
	bool isSamePastryName(const char* pastryName) const;
	Bill** enlargeBillsArray();
	Employee** enlargeEmployeesArray();
	Pastry** enlargePastriesArray();
	void insertionSort();

public:
	Konditori(const char* name, const Address& address) noexcept(false);
	Konditori(const char* name, Address&& address) noexcept(false);
	Konditori(const Konditori& other) = delete;	
	Konditori(Konditori&& other) noexcept;
	~Konditori();
	
	const Konditori& operator=(const Konditori& other) = delete;
	const Konditori& operator=(Konditori&& other) = delete;
	
	const char* getName() const { return name; }
	void setName(const char* name);

	const Address& getAddress() const { return address; }
	Address& getAddress() { return address; }

	const Shift& getCurrentShift() const { return currentShift; }
	Shift& getCurrentShift() { return currentShift; }

	const Employee*const* getEmployees() const { return employees; }
	int getEmployeesLogicalSize() const { return employeesLogicalSize; }
	const Konditori& operator+=(const Employee& other);
	Employee* getEmployeeById(int id) const;

	const Pastry*const* getPastries() const { return pastries; }
	ePastryActionStatus addPastry(const Pastry& pastry); 
	ePastryActionStatus renamePastry(const Pastry& pastry, const char* newName);
	
	Pastry* getPastryByName(const char* pastryName);
	const Pastry* getPastryByName(const char* pastryName) const;

	const Bill*const* getBills() const { return bills; }
	int getBillsLogicalSize() const { return billsLogicalSize; }
	void addBill(const Bill& bill) noexcept(false);
	const Bill*const* getTopBills() const;
	const Bill*const* getBottomBills() const;

	friend ostream& operator<<(ostream& os, const Konditori& konditori);
};

#endif //__KONDITORI_H