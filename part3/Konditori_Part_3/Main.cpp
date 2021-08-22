#include "Main.h"
#include "Cashier.h"
#include "Konditor.h"
#include "KonditorCashier.h"

#include <iostream>
using namespace std;

int main()
{
	bool isLoop = true;

	while (isLoop)
	{
		try
		{
			Konditori k = initKonditori();
			isLoop = false;
			mainMenu(k);
		}

		catch (const char* msg)
		{
			cout << msg << endl;
		}
	}

	return 0;
}

Konditori initKonditori() noexcept(false)
{

	char name[STR_LEN];
	cout << "Insert konditori name: ";
	cin.getline(name, STR_LEN);

	char cName[STR_LEN];
	cout << "Insert city name: ";
	cin.getline(cName, STR_LEN);

	char sName[STR_LEN];
	cout << "Insert street name: ";
	cin.getline(sName, STR_LEN);

	int houseNumber;
	cout << "Insert house number: ";
	cin >> houseNumber;
	getchar();

	return Konditori(name, Address(cName, sName, houseNumber));
}

void mainMenu(Konditori& k)
{
	bool isExit = false;
	int option;
	cout << k;

	do
	{
		cout << "\n<<<<<<<Please choose an option>>>>>>>" << endl
			<< "1.Edit Konditori information" << endl
			<< "2.Add employee" << endl
			<< "3.Show employees" << endl
			<< "4.Edit shift" << endl
			<< "5.Show shift" << endl
			<< "6.Add pastry" << endl
			<< "7.Edit pastry" << endl
			<< "8.Show pastry" << endl
			<< "9.Show bills" << endl
			<< "10.Shop" << endl
			<< "0.Exit" << endl
			<< "Your option: ";
		cin >> option;
		getchar();
		switch (option)
		{
		case 0:
			isExit = true;
			break;
		case 1:
			try
			{
				editKonditoriInformation(k);
				cout << k;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		case 2:
			try
			{
				addEmployee(k);
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		case 3:
			showEmployees(k.getEmployees());
			break;
		case 4:
			editShift(k);
			break;
		case 5:
			showShift(k.getCurrentShift());
			break;
		case 6:
			try
			{
				addPastry(k);
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		case 7:
			try
			{
				editPastry(k);
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		case 8:
			showPastry(k);
			break;
		case 9:
			showBills(k);
			break;
		case 10:
			shop(k);
			break;
		default:
			cout << "Invalid Input!\n";
			break;
		}
	} while (!isExit);
	cout << "Bye :)\n";
}

void editKonditoriInformation(Konditori& k) noexcept(false)
{
	int option;

	while (true)
	{
		cout << "\nWhich konditori option would you like to edit?" << endl
			<< "1.Konditori name" << endl
			<< "2.City name" << endl
			<< "3.Street name" << endl
			<< "4.House number" << endl
			<< "0.Return to main menu" << endl
			<< "Your option: ";
		cin >> option;
		getchar();
		switch (option)
		{
		case 1:
			editKonditoriName(k);
			return;
		case 2:
			editKonditoriCity(k.getAddress());
			return;
		case 3:
			editKonditoriStreet(k.getAddress());
			return;
		case 4:
			editKonditoriHouseNumber(k.getAddress());
			return;
		case 0:
			return;
		default:
			cout << "Invalid Input!\n";
			break;
		}
	}
}

void editKonditoriName(Konditori& k) noexcept(false)
{
	char newName[STR_LEN];
	cout << "Insert konditori name: ";
	cin.getline(newName, STR_LEN);
	k.setName(newName);
}

void editKonditoriCity(Address& a) noexcept(false)
{
	char newName[STR_LEN];
	cout << "Insert city name: ";
	cin.getline(newName, STR_LEN);
	a.setCity(newName);
}

void editKonditoriStreet(Address& a) noexcept(false)
{
	char newName[STR_LEN];
	cout << "Insert street name: ";
	cin.getline(newName, STR_LEN);
	a.setStreet(newName);
}

void editKonditoriHouseNumber(Address& a) noexcept(false)
{
	unsigned int newHouseNumber;
	cout << "Insert house number: ";
	cin >> newHouseNumber;
	getchar();
	a.setStreetNumber(newHouseNumber);
}

void addEmployee(Konditori& k) noexcept(false)
{
	int option;
	double hourlyWage;
	char name[STR_LEN];
	cout << "Insert employee name: ";
	cin.getline(name, STR_LEN);
	cout << "Insert hourly wadge: ";
	cin >> hourlyWage;
	getchar();
	cout << endl;

	while (true)
	{
		cout << "What is the employee role?" << endl
			<< "1.Cashier" << endl
			<< "2.Konditor" << endl
			<< "3.Konditor-Cashier" << endl
			<< "0.Return to main menu" << endl
			<< "Your option: ";
		cin >> option;
		getchar();
		switch (option)
		{
		case 1:
			k += (Cashier(name, hourlyWage));
			return;
		case 2:
			k += (Konditor(name, hourlyWage));
			return;
		case 3:
			k += (KonditorCashier(name, hourlyWage));
			return;
		case 0:
			return;
		default:
			cout << "Invalid Input!\n";
			break;
		}
	}
}

void showEmployees(const vector<Employee*> employees)
{
	cout << employees.size() << " Employees:\n";
	vector<Employee*>::const_iterator itr = employees.begin();
	vector<Employee*>::const_iterator itrEnd = employees.end();
	for (; itr != itrEnd; ++itr)
		cout << *(*itr) << endl;
}

void editShift(Konditori& k)
{
	if (k.getEmployeesLogicalSize() == 0)
	{
		cout << "There are 0 employees. add employees first" << endl;
		return;
	}

	showEmployees(k.getEmployees());
	int option;

	int id;
	cout << "insert employee id: ";
	cin >> id;
	getchar();
	Employee* employee = k.getEmployeeById(id);
	if (!employee)
	{
		cout << "\nEmployee not found";
		return;
	}

	KonditorCashier* kc = dynamic_cast<KonditorCashier*>(employee);
	if (kc)
	{
		while (true)
		{
			cout << "\nWhich employee whould you like to replace in shift?" << endl
				<< "1.Cashier" << endl
				<< "2.Konditor" << endl
				<< "0.Return to main menu" << endl
				<< "Your option: ";
			cin >> option;
			getchar();
			switch (option)
			{
			case 1:
				k.getCurrentShift().setCashier(kc);
				return;
			case 2:
				k.getCurrentShift().setKonditor(kc);
				return;
			case 0:
				return;
			default:
				cout << "Invalid Input!\n";
				break;
			}
		}
	}
	else
	{
		Konditor* konditor = dynamic_cast<Konditor*>(employee);
		if (konditor)
		{
			k.getCurrentShift().setKonditor(konditor);
			return;
		}
		Cashier* cashier = dynamic_cast<Cashier*>(employee);
		if (cashier)
		{
			k.getCurrentShift().setCashier(cashier);
			return;
		}
	}
}

void showShift(const Shift& shift)
{
	cout << "Showing shift:\n";
	cout << shift;
}

void addPastry(Konditori& k) noexcept(false)
{
	Recipe recipe = initRecipeFromUser();

	char name[STR_LEN];
	double price;
	cout << "Insert pastry name: ";
	cin.getline(name, STR_LEN);
	cout << "Insert price: ";
	cin >> price;
	getchar();

	printPastryActionStatus(k.addPastry(Pastry(name, price, recipe)));
}

Recipe initRecipeFromUser() noexcept(false)
{
	Recipe recipe = Recipe();
	bool isLoop = true;
	char userChoice;
	while (isLoop)
	{
		Ingredient newIngredient = initIngredientFromUser();
		recipe += newIngredient;
		cout << "Are you sure? y for yes" << endl;
		cin >> userChoice;
		getchar();
		if (userChoice != 'y')
		{
			recipe -= newIngredient;
		}
		cout << "Add another? y for yes" << endl;
		cin >> userChoice;
		getchar();
		isLoop = (userChoice == 'y');
	}
	return recipe;
}

Ingredient initIngredientFromUser() noexcept(false)
{
	int amount;
	char ingredientName[STR_LEN];
	cout << "Insert ingredient name: ";
	cin.getline(ingredientName, STR_LEN);
	cout << "Insert amount: ";
	cin >> amount;
	getchar();

	return Ingredient(ingredientName, amount);
}

void editPastry(Konditori& k) noexcept(false)
{
	char nameToSearch[STR_LEN];
	Pastry* pastryFound;
	cout << "Insert pastry name: ";
	cin.getline(nameToSearch, STR_LEN);
	pastryFound = k.getPastryByName(nameToSearch);

	if (pastryFound)
		editPastryMenu(k, *pastryFound);
	else
		cout << "Pastry not found\n";
}

void editPastryMenu(Konditori& k, Pastry& p) noexcept(false)
{
	int option;

	while (true)
	{
		cout << "\nWhich attribute would you like to edit?" << endl
			<< "1.Pastry name" << endl
			<< "2.Pastry price" << endl
			<< "3.Recipe" << endl
			<< "0.Return to main menu" << endl
			<< "Your option: ";
		cin >> option;
		getchar();
		switch (option)
		{
		case 1:
			char newName[STR_LEN];
			cout << "Insert new name: ";
			cin.getline(newName, STR_LEN);
			printPastryActionStatus(k.renamePastry(p, newName));
			return;
		case 2:
			double newPrice;
			cout << "Insert new price: ";
			cin >> newPrice;
			cout << endl;
			p.setPrice(newPrice);
			cout << "Action succeed!\n";
			return;
		case 3:
			p.setRecipe(initRecipeFromUser());
			cout << "Action succeed!\n";
			return;
		case 0:
			return;
		default:
			cout << "Invalid Input!\n";
			break;
		}
	}
}

void printPastryActionStatus(Konditori::ePastryActionStatus status)
{
	switch (status)
	{
	case Konditori::ePastryActionStatus::SUCCEED:
		cout << "Action succeed!\n";
		break;
	case Konditori::ePastryActionStatus::FAILED_ALREADY_EXIST:
		cout << "ERROR: pastry with this name already exist\n";
		break;
	case Konditori::ePastryActionStatus::FAILED_GENERAL:
		cout << "ERROR: general failure\n";
		break;
	}
}

void showPastry(const Konditori& k)
{
	char nameToSearch[STR_LEN];
	const Pastry* pastryFound;

	cout << "Insert pastry name: ";
	cin.getline(nameToSearch, STR_LEN);
	cout << endl;
	pastryFound = k.getPastryByName(nameToSearch);
	if (pastryFound)
	{
		cout << *pastryFound << endl;
	}
	else
	{
		cout << "Pastry not found\n";
	}
}

void showBills(const Konditori& k)
{
	int option, numOfBills = k.getBillsLogicalSize() > 5 ? 5 : k.getBillsLogicalSize();

	if (numOfBills == 0)
	{
		cout << "There are no bills in the system yet" << endl;
		return;
	}

	while (true)
	{
		cout << "\nWhich bills would you like see?" << endl
			<< "1.Top half" << endl
			<< "2.Low half" << endl
			<< "0.Return to main menu" << endl
			<< "Your option: ";
		cin >> option;
		getchar();
		switch (option)
		{
		case 1:
			printBills(k.getTopBills(), numOfBills);
			return;
		case 2:
			printBills(k.getBottomBills(), numOfBills);
			return;
		case 0:
			return;
		default:
			cout << "Invalid Input!\n";
			break;
		}
	}
}

void printBills(const Bill* const* bills, int size)
{
	cout << "Bills:\n";
	for (int i = 0; i < size; i++)
		cout << *bills[i] << endl;
}

void shop(Konditori& k)
{
	char nameToSearch[STR_LEN];
	char userChoice;
	Pastry* pastryFound;
	bool isLoop = true;
	bool isAmountCorrect = false;
	int amount;

	const Shift shift = k.getCurrentShift();
	const Cashier* currentCashier = shift.getCashier();
	const Konditor* currentKonditor = shift.getKonditor();

	Bill bill;

	if (!currentCashier)
	{
		cout << "No cashier in current shift! Can't accept payment!";
		return;
	}
	if (!currentKonditor)
	{
		cout << "No konditor in current shift! Can't bake!";
		return;
	}

	while (isLoop)
	{
		cout << "Insert pastry name: ";
		cin.getline(nameToSearch, STR_LEN);
		pastryFound = k.getPastryByName(nameToSearch);
		if (pastryFound)
		{
			while (!isAmountCorrect)
			{
				cout << "Insert amount: ";
				cin >> amount;
				getchar();
				try
				{
					bill.addPastry(*pastryFound, amount);
					isAmountCorrect = true;
				}
				catch (const char* msg)
				{
					cout << msg << endl;
				}
			}
		}
		else
		{
			cout << "Pastry not found" << endl;
		}
		cout << "Add another? y for yes" << endl;
		cin >> userChoice;
		getchar();
		isAmountCorrect = false;
		isLoop = (userChoice == 'y');
	}

	if ((*currentCashier).acceptPayment(bill.getTotalPrice()))
	{
		cout << "Payment accepted" << endl;
		(*currentKonditor).bake(bill.getItems());
	}
	else
	{
		cout << "Payment is not accepted" << endl;
	}

	try
	{
		k.addBill(bill);
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}
