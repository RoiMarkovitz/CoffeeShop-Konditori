#include "Bill.h"

#pragma warning(disable: 4996)

Bill::Bill()
{
	date = time(0);
	physicalSize = 1;
	logicalSize = 0;
	items = new PastryWithCount * [physicalSize];
}

Bill::Bill(const Bill& other) : items(nullptr)
{
	*this = other;
}

Bill::Bill(Bill&& other) noexcept : physicalSize(0), logicalSize(0), items(nullptr)
{
	*this = std::move(other);
}

Bill::~Bill()
{
	for (int i = 0; i < logicalSize; i++)
		delete items[i];

	delete[] items;
}

const Bill& Bill::operator=(const Bill& other)
{
	if (this != &other)
	{
		physicalSize = other.physicalSize;
		logicalSize = other.logicalSize;	
		date = other.date;
		delete[] items;
		items = new PastryWithCount * [physicalSize];
		for (int i = 0; i < logicalSize && i < physicalSize; i++)
			items[i] = new PastryWithCount(*other.items[i]);
	}

	return *this;
}

const Bill& Bill::operator=(Bill&& other) noexcept
{
	if (this != &other)
	{
		date = other.date;
		swap(physicalSize, other.physicalSize);
		swap(logicalSize, other.logicalSize);
		swap(items, other.items);
	}

	return *this;
}

void Bill::addPastry(const Pastry& pastry, int amount) noexcept(false)
{
	if (amount <= 0)
		throw "Error: amount cannot be below 1";

	if (logicalSize == physicalSize)
		items = enlargeIngredientsArray();

	items[logicalSize++] = new PastryWithCount(pastry, amount);
}

PastryWithCount** Bill::enlargeIngredientsArray()
{
	PastryWithCount** newItemsArray;
	physicalSize *= ENLARGE_FACTOR;

	newItemsArray = new PastryWithCount * [physicalSize];
	for (int i = 0; i < logicalSize; i++)
		newItemsArray[i] = items[i];

	delete[] items;

	return newItemsArray;
}


double Bill::getTotalPrice() const
{
	double sum = 0;
	for (int i = 0; i < logicalSize; i++)
		sum += items[i]->getPrice();
	return sum;
}

bool Bill::operator<(const Bill& other) const
{
	if (getTotalPrice() < other.getTotalPrice())
		return true;
	if (getTotalPrice() > other.getTotalPrice())
		return false;

	return date > other.date; // smaller if newer
 
}

bool Bill::operator>(const Bill& other) const
{
	return other < *this;
}

const char* Bill::getDate() const
{
	return ctime(&date);
}

ostream& operator<<(ostream& os, const Bill& bill)
{
	os << "Date: " << bill.getDate();
	os << endl << "The items are: " << endl;
	for (int i = 0; i < bill.logicalSize; i++)
		os << i + 1 << ". " << *bill.items[i] << endl;

	os << "Total Price: " << bill.getTotalPrice() << endl;
	return os;
}