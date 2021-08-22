#pragma warning(disable: 4996)

#include <iostream>
using namespace std;

#include "Address.h"
#include "StringUtil.h"

Address::Address(const string& cityName, const string& streetName, int streetNumber) noexcept(false) 
{
	setStreetNumber(streetNumber);
	setCity(cityName);
	setStreet(streetName);
}

Address::Address(Address&& other) noexcept
{
	*this = std::move(other);
}


const Address& Address::operator=(Address&& other) noexcept
{
	if (this != &other)
	{
		swap(city, other.city);
		swap(street, other.street);
		streetNumber = other.streetNumber;
	}
	return *this;
}

void Address::setCity(const string& cityName) noexcept(false)
{

	if (StringUtil::isValidName(cityName.c_str()))
		this->city = cityName;
	else
		throw "Error: invalid city name";
}

void Address::setStreet(const string& streetName) noexcept(false)
{
	if (StringUtil::isValidName(streetName.c_str()))
		this->street = streetName;
	else
		throw "Error: invalid street name";
}

void Address::setStreetNumber(int streetNumber) noexcept(false)
{
	if (streetNumber <= 0)
		throw "Error: invalid street number";

	this->streetNumber = streetNumber;
}


ostream& operator<<(ostream& os, const Address& address)
{
	os << address.street << " " << address.streetNumber << ", " << address.city << endl;
	return os;
}


