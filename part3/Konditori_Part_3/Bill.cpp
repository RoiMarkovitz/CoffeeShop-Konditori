#include "Bill.h"

#pragma warning(disable: 4996)

Bill::Bill()
{
	date = time(0);
}

Bill::Bill(const Bill& other) 
{
	*this = other;
}

Bill::Bill(Bill&& other) noexcept 
{
	*this = std::move(other);
}

Bill::~Bill()
{
	vector<PastryWithCount*>::iterator itr = items.begin();
	vector<PastryWithCount*>::iterator itrEnd = items.end();
	for (; itr != itrEnd; ++itr)
		delete* itr;
}

const Bill& Bill::operator=(const Bill& other)
{
	if (this != &other)
	{	
		date = other.date;
		items.clear();
		vector<PastryWithCount*>::const_iterator itr = other.items.begin();
		vector<PastryWithCount*>::const_iterator itrEnd = other.items.end();
		for (int i = 0; itr != itrEnd; ++itr, i++)
			items.push_back(new PastryWithCount(*(*itr)));
	}

	return *this;
}

const Bill& Bill::operator=(Bill&& other) noexcept
{
	if (this != &other)
	{
		date = other.date;
		swap(items, other.items);
	}

	return *this;
}

void Bill::addPastry(const Pastry& pastry, int amount) noexcept(false)
{
	if (amount <= 0)
		throw "Error: amount cannot be below 1";

	if (items.size() == items.capacity())
		items.reserve(items.capacity() * ENLARGE_FACTOR);

	items.push_back(new PastryWithCount(pastry, amount));
}

double Bill::getTotalPrice() const
{
	double sum = 0;
	vector<PastryWithCount*>::const_iterator itr = items.begin();
	vector<PastryWithCount*>::const_iterator itrEnd = items.end();
	for (; itr != itrEnd; ++itr)
		sum += (*itr)->getPrice();
	
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
	vector<PastryWithCount*>::const_iterator itr = bill.items.begin();
	vector<PastryWithCount*>::const_iterator itrEnd = bill.items.end();
	for (int i = 1; itr != itrEnd; ++itr, i++)
		os << i << ". " << *(*itr) << endl;

	os << "Total Price: " << bill.getTotalPrice() << endl;
	return os;
}