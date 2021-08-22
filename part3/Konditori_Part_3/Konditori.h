#ifndef __KONDITORI_H
#define __KONDITORI_H

#include <string>
#include "Employee.h"
#include "Address.h"
#include "Shift.h"

#include <iostream>
using namespace std;

#include <vector>

class Pastry;
class Bill;

class Konditori
{

public:
	enum class ePastryActionStatus { SUCCEED, FAILED_ALREADY_EXIST, FAILED_GENERAL };

private:
	static const int ENLARGE_FACTOR = 2;
	string name;
	Address address;
	Shift currentShift;

	vector<Employee*> employees;
	vector<Pastry*> pastries;
	vector<Bill*> bills;

	bool isSamePastryName(const string& pastryName) const;
	void insertionSort();

public:
	Konditori(const char* name, const Address& address) noexcept(false);
	Konditori(const char* name, Address&& address) noexcept(false);
	Konditori(const Konditori& other) = delete;	
	Konditori(Konditori&& other) noexcept;
	~Konditori();
	
	const Konditori& operator=(const Konditori& other) = delete;
	const Konditori& operator=(Konditori&& other) = delete;
	
	const string& getName() const { return name; }
	void setName(const string& name);

	const Address& getAddress() const { return address; }
	Address& getAddress() { return address; }

	const Shift& getCurrentShift() const { return currentShift; }
	Shift& getCurrentShift() { return currentShift; }

	const vector<Employee*> getEmployees() const { return employees; }
	int getEmployeesLogicalSize() const { return employees.size(); }
	const Konditori& operator+=(const Employee& other);
	Employee* getEmployeeById(int id) const;

	const vector<Pastry*> getPastries() const { return pastries; }
	ePastryActionStatus addPastry(const Pastry& pastry); 
	ePastryActionStatus renamePastry(const Pastry& pastry, const char* newName);
	
	Pastry* getPastryByName(const string& pastryName);
	const Pastry* getPastryByName(const string& pastryName) const;

	const vector<Bill*> getBills() const { return bills; }
	int getBillsLogicalSize() const { return bills.size(); }
	void addBill(const Bill& bill) noexcept(false);
	const Bill*const* getTopBills() const;
	const Bill*const* getBottomBills() const;

	friend ostream& operator<<(ostream& os, const Konditori& konditori);
};

#endif //__KONDITORI_H